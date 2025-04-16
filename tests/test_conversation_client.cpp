#include "IConversationClient.h"
#include <gtest/gtest.h>
#include <string>

// Mock implementation
class MockConversationClient : public IConversationClient {
public:
    void startConversation() override {}
    bool sendMessage(const std::string& input) override { return true; }
    std::string receiveResponse() override { return "Expected AI response"; }
    void endConversation() override {}
};

TEST(ConversationClientTest, SendMessageReturnsBool) {
    MockConversationClient client;
    bool result = client.sendMessage("Hello, AI!");
    EXPECT_TRUE(result);
}

TEST(ConversationClientTest, ReceiveResponseReturnsExpectedShape) {
    MockConversationClient client;
    std::string response = client.receiveResponse();
    EXPECT_EQ(response, "Expected AI response");
    EXPECT_TRUE((std::is_same<decltype(response), std::string>::value));
}

TEST(ConversationClientTest, FullConversationFlow) {
    MockConversationClient client;
    EXPECT_NO_THROW(client.startConversation());
    EXPECT_TRUE(client.sendMessage("Hey"));
    std::string response = client.receiveResponse();
    EXPECT_FALSE(response.empty());
    EXPECT_NO_THROW(client.endConversation());
}
