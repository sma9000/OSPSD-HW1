#include "Config.h"
#include "ConversationClient.h"
#include <gtest/gtest.h>
#include <string>

// Test fixture for Config tests.
class ConfigTest : public ::testing::Test {
protected:
    // Called before every test
    void SetUp() override {
        // Clear to ensure a clean state
        Config::getInstance()->clear();
    }
};

TEST_F(ConfigTest, DefaultSettingsAreSetAndRetrieved) {
    Config* config = Config::getInstance();

    // Set default values for testing.
    config->set("MOCK_MODE", "true");
    config->set("OPENAI_API_KEY", "dummy_api_key");
    config->set("OPENAI_API_ENDPOINT", "http://dummyapi.local/");

    // Verify that the values can be fetched correctly.
    EXPECT_EQ(config->get("MOCK_MODE"), "true");
    EXPECT_EQ(config->get("OPENAI_API_KEY"), "dummy_api_key");
    EXPECT_EQ(config->get("OPENAI_API_ENDPOINT"), "http://dummyapi.local/");
}

TEST_F(ConfigTest, ConversationClientUsesConfigDefaults) {
    Config* config = Config::getInstance();

    // Set the configuration needed for the ConversationClient
    config->set("MOCK_MODE", "true");
    config->set("OPENAI_API_KEY", "dummy_api_key");
    config->set("OPENAI_API_ENDPOINT", "http://dummyapi.local/");

    ConversationClient client;
    
    // Calling sendMessage should check the MOCK_MODE branch in your code
    // Should not perform a real HTTP call, but simply register an expected fixed reply
    bool success = client.sendMessage("Test message");
    EXPECT_TRUE(success);

    // Retrieve the response using the conversation client
    std::string response = client.receiveResponse();

    // Since in MOCK_MODE the AI response is set as "Expected AI response" (after formatting)
    // verify that the response contains this expected text
    EXPECT_NE(response.find("Expected AI response"), std::string::npos);
}

