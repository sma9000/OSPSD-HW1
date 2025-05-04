#include "ConversationClient.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>
#include <thread>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// --- Helper Functions ---

std::string extractNumberFrom(const std::string& text) {
    std::regex number_regex(R"((\b\d{1,3}\b)(\%|percent|probability)?)");
    std::smatch match;
    if (std::regex_search(text, match, number_regex)) {
        return match[1];
    }
    return "0";
}

std::string getEnvVar(const std::string& key, const std::string& defaultValue = "") {
    const char* val = std::getenv(key.c_str());
    return val ? val : defaultValue;
}

std::string createPrompt(const std::string& email_body) {
    std::string sanitized = std::regex_replace(email_body, std::regex("\""), "'");
    return "You are an email spam detection model.\n"
           "Given the following email body, respond ONLY with a single integer (0–100), "
           "representing the likelihood of spam:\n\n"
           "- 0 to 30: Legitimate\n"
           "- 31 to 70: Suspicious\n"
           "- 71 to 100: Spam\n\n"
           "Email:\n\n\"" + sanitized + "\"\n\n"
           "Respond with only the number, nothing else.";
}

// --- Main Program ---

int main() {
    Config* config = Config::getInstance();
    config->set("MOCK_MODE", getEnvVar("MOCK_MODE", "false"));
    config->set("OPENAI_API_KEY", getEnvVar("OPENAI_API_KEY"));
    config->set("OPENAI_API_ENDPOINT", getEnvVar("OPENAI_API_ENDPOINT", "https://api.openai.com/v1/chat/completions"));

    const int MAX_RETRIES = 3;
    const int RATE_LIMIT_DELAY_MS = 1000;
    const int MAX_EMAILS = 10;

    std::string emailsFile = getEnvVar("EMAILS_FILE", "emails.csv");
    std::string resultsFile = getEnvVar("RESULTS_FILE", "results.csv");

    std::cout << "Using input file: " << emailsFile << std::endl;
    std::cout << "Writing results to: " << resultsFile << std::endl;

    std::ifstream infile(emailsFile);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open " << emailsFile << std::endl;
        return 1;
    }

    std::ofstream outfile(resultsFile);
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create results file: " << resultsFile << std::endl;
        return 1;
    }
    outfile << "mail_id,Pct_spam\n";

    std::string line;
    std::getline(infile, line); // Skip header
    int processed_emails = 0;

    while (std::getline(infile, line) && processed_emails < MAX_EMAILS) {
        size_t comma_pos = line.find(',');
        if (comma_pos == std::string::npos) {
            std::cerr << "Skipping malformed line: " << line << std::endl;
            continue;
        }

        std::string mail_id = line.substr(0, comma_pos);
        std::string email_body = line.substr(comma_pos + 1);
        std::string prompt = createPrompt(email_body);

        bool success = false;
        for (int i = 0; i < MAX_RETRIES && !success; ++i) {
            try {
                std::clog << "Processing: " << mail_id << std::endl;

                json request_body = {
                    {"model", "gpt-3.5-turbo"},
                    {"messages", {
                        {{"role", "system"}, {"content", "You are a spam detection AI. Respond ONLY with a number 0-100."}},
                        {{"role", "user"}, {"content", prompt}}
                    }},
                    {"temperature", 0.1},
                    {"max_tokens", 1}
                };

                auto response = cpr::Post(
                    cpr::Url{config->get("OPENAI_API_ENDPOINT")},
                    cpr::Header{
                        {"Authorization", "Bearer " + config->get("OPENAI_API_KEY")},
                        {"Content-Type", "application/json"}
                    },
                    cpr::Body{request_body.dump()}
                );

                if (response.status_code == 200) {
                    json response_json = json::parse(response.text);
                    std::string ai_response = response_json["choices"][0]["message"]["content"];
                    std::string spam_pct = extractNumberFrom(ai_response);

                    std::clog << "AI Response: " << ai_response << "\nSpam %: " << spam_pct << "\n\n";
                    outfile << mail_id << "," << spam_pct << "\n";
                    success = true;
                    ++processed_emails;

                    std::this_thread::sleep_for(std::chrono::milliseconds(RATE_LIMIT_DELAY_MS));
                } else if (response.text.find("rate_limit_exceeded") != std::string::npos) {
                    size_t wait_pos = response.text.find("try again in ");
                    if (wait_pos != std::string::npos) {
                        int wait_seconds = std::stoi(response.text.substr(wait_pos + 13));
                        std::cerr << "Rate limited. Waiting " << wait_seconds << " seconds...\n";
                        std::this_thread::sleep_for(std::chrono::seconds(wait_seconds + 1));
                    }
                } else {
                    throw std::runtime_error("API Error: " + response.text);
                }
            } catch (const std::exception& e) {
                std::cerr << "Attempt " << (i + 1) << " failed: " << e.what() << std::endl;
            }
        }

        if (!success) {
            outfile << mail_id << ",error\n";
            std::cerr << "Failed to process: " << mail_id << std::endl;
        }
    }

    infile.close();
    outfile.close();
    std::cout << "Analysis complete. Processed " << processed_emails << "/" << MAX_EMAILS << " emails." << std::endl;
    return 0;
}
