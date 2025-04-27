#include "Message.h"
#include "ConversationClient.h"
#include "NLPProcessor.h"
#include "ResponseFormatter.h"
#include <gtest/gtest.h>
#include <chrono>
#include <string>

// Integration test that focuses on processing a Message object directly using the NLPProcessor and ResponseFormatter
TEST(MessageFlowIntegration, ProcessAndFormatMessage) {
    Message sampleMsg;
    sampleMsg.sender = "User";
    sampleMsg.content = "Hello, how's the weather today?";
    sampleMsg.timestamp = std::chrono::system_clock::now();

    NLPProcessor nlp;

    // Preprocess input
    std::string preprocessed = nlp.preprocessInput(sampleMsg.content);

    // Postprocess output
    std::string postprocessed = nlp.postprocessOutput(preprocessed);

    // Initialize static tags (needed for formatting)
    ResponseFormatter::initializeTags();

    // Format the processed output
    std::string formatted = ResponseFormatter::formatResponse(postprocessed, "info");
    formatted = ResponseFormatter::addNewLineIfNeeded(formatted);

    // Define the expected output.
    // (Note: Adjust this expected value based on the actual behavior of NLPProcessor and ResponseFormatter)
    std::string expectedOutput = "Hello, how's the weather today?";  

    // Validate that the formatted output includes the expected result
    EXPECT_NE(formatted.find(expectedOutput), std::string::npos);
}

// Integration test using the ConversationClient, which internally calls NLPProcessor and ResponseFormatter
TEST(MessageFlowIntegration, FullConversationClientProcessing) {
    // Here assume that ConversationClient works in mock mode
    // Make sure that your global configuration (via Config) is set up to enable MOCK_MODE 
    
    ConversationClient client;
    
    // Send a test message
    bool success = client.sendMessage("Test message for conversation");
    EXPECT_TRUE(success);

    // Retrieve the processed AI response
    std::string response = client.receiveResponse();

    // Validate that the response contains the known mock reply
    // In ConversationClient implementation, if MOCK_MODE is enabled, the response is set to "Expected AI response" after formatting
    EXPECT_NE(response.find("Expected AI response"), std::string::npos);
}
