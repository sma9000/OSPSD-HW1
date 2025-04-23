#include "ConversationClient.h"
#include "Config.h"
#include "Error.h"
#include "ResponseFormatter.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <thread>

// cpr and nlohmann/json libraries are available
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool ConversationClient::sendMessage(const std::string& input) {
    try {
        // Preprocess user input (for example: trim, lower-case, etc.)
        std::string processedInput = nlp.preprocessInput(input);

        // Build and add user message to history
        Message userMsg;
        userMsg.sender = "User";
        userMsg.content = processedInput;
        userMsg.timestamp = std::chrono::system_clock::now();
        history.addMessage(userMsg);

        // Retrieve configuration settings
        Config* config = Config::getInstance();

        // Check for mock mode: if enabled, bypass HTTP call
        if (config->get("MOCK_MODE") == "true") {
            std::string aiResponse = "Expected AI response";
            // Postprocess and format the fixed response.
            aiResponse = nlp.postprocessOutput(aiResponse);
            aiResponse = ResponseFormatter::formatResponse(aiResponse, "info");
            aiResponse = ResponseFormatter::addNewLineIfNeeded(aiResponse);

            // Create and store the AI message.
            Message aiMsg;
            aiMsg.sender = "AI";
            aiMsg.content = aiResponse;
            aiMsg.timestamp = std::chrono::system_clock::now();
            history.addMessage(aiMsg);
            return true;
        }

        // For real API calls, retrieve the API key and endpoint
        std::string apiKey = config->get("OPENAI_API_KEY");
        std::string apiEndpoint = config->get("OPENAI_API_ENDPOINT");

        if (apiKey.empty() || apiEndpoint.empty()) {
            throw ServiceError("API key or endpoint is not set in configuration.");
        }

        // Prepare JSON payload for the OpenAI API call
        json payload;
        payload["model"] = "text-davinci-003";  // Adjust to the desired model
        payload["prompt"] = processedInput;
        payload["max_tokens"] = 150;

        // Call OpenAI API via HTTP POST
        auto response = cpr::Post(cpr::Url{apiEndpoint},
                                  cpr::Header{
                                      {"Content-Type", "application/json"},
                                      {"Authorization", "Bearer " + apiKey}
                                  },
                                  cpr::Body{payload.dump()},
                                  cpr::Timeout{10000});  // 10-second timeout

        // Check for HTTP-related errors
        if (response.status_code != 200) {
            throw NetworkError("Status code: " + std::to_string(response.status_code));
        }

        // Parse the response JSON
        json resJson = json::parse(response.text);
        std::string aiResponse = resJson["choices"][0]["text"];

        // Postprocess the AI output
        aiResponse = nlp.postprocessOutput(aiResponse);

        // Format the response using ResponseFormatter
        aiResponse = ResponseFormatter::formatResponse(aiResponse, "info");
        aiResponse = ResponseFormatter::addNewLineIfNeeded(aiResponse);

        // Create and store the AI message
        Message aiMsg;
        aiMsg.sender = "AI";
        aiMsg.content = aiResponse;
        aiMsg.timestamp = std::chrono::system_clock::now();
        history.addMessage(aiMsg);

        return true;
    }
    catch (const std::exception &ex) {
        // Log error and indicate failure
        std::cerr << "Error sending message: " << ex.what() << "\n";
        return false;
    }
}


std::string ConversationClient::receiveResponse() const {
    // Retrieve conversation history and locate the last AI message.
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

void ConversationClient::endConversation() {
    // Finalize conversation and log closure.
    std::cout << ResponseFormatter::addTimestamp("Conversation ended.\n");
}
