#include <gtest/gtest.h>
#include "Config.h"
#include "ConversationClient.h"
#include "IConfig.h"
#include "IConversationClient.h"

TEST(InterfaceTest, ConfigImplementsIConfig) {
    IConfig* config = Config::getInstance();  // Should compile if compliant
    config->set("key", "value");
    EXPECT_EQ(config->get("key"), "value");
}

TEST(InterfaceTest, ConversationClientImplementsIConversationClient) {
    IConversationClient* client = new ConversationClient();
    EXPECT_TRUE(client != nullptr);

    delete client;
}
