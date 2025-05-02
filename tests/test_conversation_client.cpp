#include "ConversationClient.h"
#include "Config.h"
#include <gtest/gtest.h>
#include <string>

TEST(ConversationClientTest, SendMessageInMockModeReturnsTrue) {
    Config* config = Config::getInstance();
    config->clear();  // Ensure clean config state
    config->set("MOCK_MODE", "true");

    ConversationClient client;
    bool result = client.sendMessage("Hello");

    EXPECT_TRUE(result);
}

TEST(ConversationClientTest, ReceiveResponseReturnsExpectedInMockMode) {
    Config* config = Config::getInstance();
    config->clear();  // Ensure clean config state
    config->set("MOCK_MODE", "true");

    ConversationClient client;

    // Populate conversation history
    ASSERT_TRUE(client.sendMessage("Hello"));

    // Check that the AI response matches what's expected in mock mode
    std::string response = client.receiveResponse();
    EXPECT_EQ(response, "Expected AI response");
}

TEST(ConversationClientTest, StartAndEndConversationDoesNotThrow) {
    ConversationClient client;
    EXPECT_NO_THROW(client.startConversation());
    EXPECT_NO_THROW(client.endConversation());
}
