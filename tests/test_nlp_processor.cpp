#include "NLPProcessor.h"
#include <gtest/gtest.h>

TEST(NLPProcessorTest, PreprocessInputTransformsCorrectly) {
    NLPProcessor nlp;
    std::string processed = nlp.preprocessInput("  Hello, AI!  ");
    EXPECT_EQ(processed, "hello, ai!"); // Example transformation
}

TEST(NLPProcessorTest, PostprocessOutputFormatsCorrectly) {
    NLPProcessor nlp;
    std::string postprocessed = nlp.postprocessOutput("HELLO FROM AI");
    EXPECT_EQ(postprocessed, "Hello from AI."); // Example transformation
}
