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

    // Must call sendMessage() first to populate history
    ASSERT_TRUE(client.sendMessage("Hello"));

    // Validate the stored AI response in mock mode
    std::string response = client.receiveResponse();
    EXPECT_EQ(response, "[INFO] Expected AI response\n");
}

TEST(ConversationClientTest, StartAndEndConversationDoesNotThrow) {
    ConversationClient client;
    EXPECT_NO_THROW(client.startConversation());
    EXPECT_NO_THROW(client.endConversation());
}
