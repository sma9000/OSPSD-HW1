#include "IConversationClient.h"
#include <gtest/gtest.h>
#include <string>

// Dummy implementation
class DummyConversationClient : public IConversationClient {
public:
    void startConversation() override {}
    bool sendMessage(const std::string& input) override { return true; }
    std::string receiveResponse() override { return "Expected AI response"; }
    void endConversation() override {}
};

TEST(ConversationIntegrationTest, FullConversationFlow) {
    DummyConversationClient client;

    EXPECT_NO_THROW(client.startConversation());
    EXPECT_TRUE(client.sendMessage("Hello, AI!"));

    std::string response = client.receiveResponse();
    EXPECT_FALSE(response.empty());
    EXPECT_EQ(response, "Expected AI response");

    EXPECT_NO_THROW(client.endConversation());
}