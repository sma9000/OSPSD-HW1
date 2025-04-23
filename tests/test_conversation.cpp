#include "ConversationClient.h"
#include "Config.h"
#include <gtest/gtest.h>
#include <string>

TEST(ConversationIntegrationTest, FullConversationFlow) {
    // Set test configuration and mock mode.
    Config* config = Config::getInstance();
    config->set("MOCK_MODE", "true");
    config->set("OPENAI_API_KEY", "dummy_key");
    config->set("OPENAI_API_ENDPOINT", "http://dummy.endpoint");

    ConversationClient client;

    // Step 1: Start the conversation
    EXPECT_NO_THROW(client.startConversation());

    // Step 2: Send a message
    std::string userInput = "Hello, AI!";
    EXPECT_TRUE(client.sendMessage(userInput));

    // Step 3: Receive a response
    std::string response = client.receiveResponse();
    EXPECT_FALSE(response.empty());  // Ensure the response is not empty
    EXPECT_EQ(response, "Expected AI response");

    // Step 4: End the conversation
    EXPECT_NO_THROW(client.endConversation());
}
