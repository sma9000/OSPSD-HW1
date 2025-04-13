#include "ConversationClient.h"
#include "Config.h"
#include <iostream>
#include <string>

std::string API_KEY = "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"

int main() {
    // Configure the OpenAI API settings.
    Config* config = Config::getInstance();
    config->set("OPENAI_API_KEY", API_KEY);  // Replace with actual API key.
    config->set("OPENAI_API_ENDPOINT", "https://api.openai.com/v1/completions");

    // Instantiate and start the conversation client.
    ConversationClient client;
    client.startConversation();
    
    // Example conversation loop (can be expanded in future)
    std::string input;
    std::cout << "Enter your message: ";
    std::getline(std::cin, input);

    if (client.sendMessage(input)) {
        try {
            std::string response = client.receiveResponse();
            std::cout << "AI Response: " << response << std::endl;
        }
        catch(const std::exception &ex) {
            std::cerr << ex.what() << std::endl;
        }
    }
    else {
        std::cerr << "Failed to send message." << std::endl;
    }

    client.endConversation();
    return 0;
}
