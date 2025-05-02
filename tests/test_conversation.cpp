#include "Config.h"
#include "ConversationClient.h"
#include <gtest/gtest.h>
#include <string>

TEST(ConversationIntegrationTest, FullConversationFlowInMockMode) {
  // Set up the config for mock mode
  Config *config = Config::getInstance();
  config->clear();
  config->set("MOCK_MODE", "true");

  ConversationClient client;

  EXPECT_NO_THROW(client.startConversation());
  EXPECT_TRUE(client.sendMessage("Hello, AI!"));

  std::string response = client.receiveResponse();
  EXPECT_FALSE(response.empty());
  EXPECT_EQ(response, "Expected AI response");

  EXPECT_NO_THROW(client.endConversation());
}