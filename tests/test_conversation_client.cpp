#include "ConversationClient.h"
#include "Config.h"
#include <gtest/gtest.h>
#include <string>

TEST(ConversationClientTest, StartConversationInitializesCorrectly) {
    Config* config = Config::getInstance();
    config->set("MOCK_MODE", "true");
    EXPECT_NO_THROW({
        ConversationClient client;
        client.startConversation();
    });
}

TEST(ConversationClientTest, SendMessageReturnsTrue) {
    Config* config = Config::getInstance();
    config->set("MOCK_MODE", "true");
    ConversationClient client;
    EXPECT_TRUE(client.sendMessage("Hello, AI!")); // Validate sending a message in mock mode
}

TEST(ConversationClientTest, ReceiveResponseReturnsExpected) {
    Config* config = Config::getInstance();
    config->set("MOCK_MODE", "true");
    ConversationClient client;
    client.startConversation();
    client.sendMessage("Hello, AI!");
    std::string response = client.receiveResponse();
    EXPECT_EQ(response, "Expected AI response"); // Validate against the expected mock response
}

TEST(ConversationClientTest, EndConversationTerminatesGracefully) {
    ConversationClient client;
    EXPECT_NO_THROW(client.endConversation()); // Ensures no errors during termination
}

