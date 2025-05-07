#include <gtest/gtest.h>
#include "ConversationClient.h"
#include "Config.h"

TEST(EndpointTest, OpenAIRespondsWithValidPercentage) {
    auto config = Config::getInstance();

    const char* key = std::getenv("OPENAI_API_KEY");
    if (!key) {
        GTEST_SKIP() << "OPENAI_API_KEY not set. Skipping live endpoint test.";
    }

    config->set("OPENAI_API_KEY", key);
    config->set("OPENAI_API_ENDPOINT", "https://api.openai.com/v1/chat/completions");

    ConversationClient client;
    std::string prompt = "How likely is this email spam? Return a number between 0 and 100.";

    ASSERT_TRUE(client.sendMessage(prompt));
    std::string response = client.receiveResponse();

    int score = std::stoi(response);
    EXPECT_GE(score, 0);
    EXPECT_LE(score, 100);
}
