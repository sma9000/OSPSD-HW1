#include "ConversationHistory.h"
#include "ConversationClient.h"
#include "Message.h"
#include "Config.h"

#include <gtest/gtest.h>
#include <chrono>
#include <thread>

// Test the ConversationHistory class directly
// This verifies that messages are stored in the order they are added
TEST(ConversationHistoryDirect, AddAndRetrieveMessages) {
    ConversationHistory history;

    Message userMsg;
    userMsg.sender = "User";
    userMsg.content = "Test message from user";
    userMsg.timestamp = std::chrono::system_clock::now();
    history.addMessage(userMsg);

    Message aiMsg;
    aiMsg.sender = "AI";
    aiMsg.content = "Test AI response";
    aiMsg.timestamp = std::chrono::system_clock::now();
    history.addMessage(aiMsg);

    std::vector<Message> messages = history.getMessages();
    
    EXPECT_EQ(messages.size(), 2);
    EXPECT_EQ(messages[0].sender, "User");
    EXPECT_EQ(messages[0].content, "Test message from user");
    EXPECT_EQ(messages[1].sender, "AI");
    EXPECT_EQ(messages[1].content, "Test AI response");
}

// Integration test that verifies the ConversationClient updates its internal history
TEST(ConversationHistoryIntegration, ClientStoresAndRetrievesMessages) {
    // Configure the system for mock mode so that ConversationClient - bypasses real HTTP calls and uses a fixed AI response
    Config::getInstance()->set("MOCK_MODE", "true");
    Config::getInstance()->set("OPENAI_API_KEY", "dummy_api_key");
    Config::getInstance()->set("OPENAI_API_ENDPOINT", "http://dummyapi.local/");

    ConversationClient client;
    
    // Start the conversation (prints a startup message)
    client.startConversation();
    
    // Send a user message. In MOCK_MODE, this should add both a User message 
    // and a corresponding AI message ("Expected AI response") to the internal history
    bool sendSuccess = client.sendMessage("Hello world");
    EXPECT_TRUE(sendSuccess);

    // Retrieve the AI response using the client
    // Indirectly tests that the ConversationHistory stored the message
    std::string aiResponse = client.receiveResponse();
    EXPECT_NE(aiResponse.find("Expected AI response"), std::string::npos);
    
    client.endConversation();
}

