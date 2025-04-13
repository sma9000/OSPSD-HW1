#include "ConversationClient.h"
#include "Config.h"
#include <gtest/gtest.h>
#include <string>

TEST(AIConversationClientIntegrationTest, MultiTurnConversation) {
    // Set configuration so that the client works in mock mode (bypassing real API calls)
    Config* config = Config::getInstance();
    config->set("MOCK_MODE", "true");
    config->set("OPENAI_API_KEY", "dummy_key");
    config->set("OPENAI_API_ENDPOINT", "http://dummy.endpoint");

    ConversationClient client;
    client.startConversation();
    
    // Send first message and check response
    EXPECT_TRUE(client.sendMessage("Hi, AI!"));
    std::string response1 = client.receiveResponse();
    EXPECT_EQ(response1, "Expected AI response");

    // Send second message and check response again (ensuring history updates)
    EXPECT_TRUE(client.sendMessage("How are you?"));
    std::string response2 = client.receiveResponse();
    EXPECT_EQ(response2, "Expected AI response");

    client.endConversation();
}
