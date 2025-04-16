#include "ConversationClient.h"
#include <gtest/gtest.h>

TEST(ConversationClientTest, StartConversationInitializesCorrectly) {
    ConversationClient client;
    EXPECT_NO_THROW(client.startConversation()); // Ensures no exceptions
}

TEST(ConversationClientTest, SendMessageReturnsTrue) {
    ConversationClient client;
    EXPECT_TRUE(client.sendMessage("Hello, AI!")); // Validate sending a message
}

TEST(ConversationClientTest, ReceiveResponseReturnsExpected) {
    ConversationClient client;
    std::string response = client.receiveResponse();
    EXPECT_EQ(response, "Expected AI response"); // Mocked expected response
}

TEST(ConversationClientTest, EndConversationTerminatesGracefully) {
    ConversationClient client;
    EXPECT_NO_THROW(client.endConversation()); // Ensures no errors
}
