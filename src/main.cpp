#include "ConversationClient.h"
#include "Config.h"
#include <iostream>
#include <string>
#include <cstdlib> 

int main() {
    // Securely load API key from an environment variable
    const char* apiKey = std::getenv("OPENAI_API_KEY");
    if (!apiKey) {
        std::cerr << "Error: OpenAI API Key not found in environment variables.\n";
        return 1;
    }

    Config* config = Config::getInstance();
    config->set("OPENAI_API_KEY", apiKey);  // Securely set API key
    config->set("OPENAI_API_ENDPOINT", "https://api.openai.com/v1/completions");

    ConversationClient client;
    client.startConversation();

    std::string input;
    std::cout << "Enter your message: ";
    std::getline(std::cin, input);

    if (client.sendMessage(input)) {
        try {
            std::string response = client.receiveResponse();
            std::cout << "AI Response: " << response << std::endl;
        } catch(const std::exception &ex) {
            std::cerr << ex.what() << std::endl;
        }
    } else {
        std::cerr << "Failed to send message." << std::endl;
    }

    client.endConversation();
    return 0;
}

