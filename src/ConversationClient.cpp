#include "ConversationClient.h"
#include "Config.h"
#include "Error.h"

#include <iostream>
#include <chrono>
#include <thread>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool ConversationClient::sendMessage(const std::string& input) {
    try {
        // No preprocessing step since NLP is removed
        std::string processedInput = input;

        // Add user message to history
        Message userMsg;
        userMsg.sender = "User";
        userMsg.content = processedInput;
        userMsg.timestamp = std::chrono::system_clock::now();
        history.addMessage(userMsg);

        // Load config
        Config* config = Config::getInstance();

        // If MOCK_MODE is enabled, skip API call
        if (config->get("MOCK_MODE") == "true") {
            std::string aiResponse = "Expected AI response";

            Message aiMsg;
            aiMsg.sender = "AI";
            aiMsg.content = aiResponse;
            aiMsg.timestamp = std::chrono::system_clock::now();
            history.addMessage(aiMsg);
            return true;
        }

        std::string apiKey = config->get("OPENAI_API_KEY");
        std::string apiEndpoint = config->get("OPENAI_API_ENDPOINT");

        if (apiKey.empty() || apiEndpoint.empty()) {
            throw ServiceError("API key or endpoint is not set in configuration.");
        }

        json payload;
        payload["model"] = "text-davinci-003";
        payload["prompt"] = processedInput;
        payload["max_tokens"] = 150;

        auto response = cpr::Post(
            cpr::Url{apiEndpoint},
            cpr::Header{
                {"Content-Type", "application/json"},
                {"Authorization", "Bearer " + apiKey}
            },
            cpr::Body{payload.dump()},
            cpr::Timeout{10000}
        );

        if (response.status_code != 200) {
            throw NetworkError("Status code: " + std::to_string(response.status_code));
        }

        json resJson = json::parse(response.text);
        std::string aiResponse = resJson["choices"][0]["text"];

        Message aiMsg;
        aiMsg.sender = "AI";
        aiMsg.content = aiResponse;
        aiMsg.timestamp = std::chrono::system_clock::now();
        history.addMessage(aiMsg);

        return true;
    }
    catch (const std::exception &ex) {
        std::cerr << "Error sending message: " << ex.what() << "\n";
        return false;
    }
}

std::string ConversationClient::receiveResponse() {
    auto messages = history.getMessages();
    if (messages.empty()) {
        throw InputError("No messages in conversation history.");
    }
    for (auto it = messages.rbegin(); it != messages.rend(); ++it) {
        if (it->sender == "AI") {
            return it->content;
        }
    }
    throw Error("No AI response present in the conversation history.");
}

void ConversationClient::startConversation() {
    std::cout << "Conversation started.\n";
}

void ConversationClient::endConversation() {
    std::cout << "Conversation ended.\n";
}