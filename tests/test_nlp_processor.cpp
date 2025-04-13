#include "NLPProcessor.h"
#include <gtest/gtest.h>
#include <string>

TEST(NLPProcessorTest, PreprocessInputTransformsCorrectly) {
    NLPProcessor nlp;
    std::string processed = nlp.preprocessInput("  Hello, AI!  ");
    EXPECT_EQ(processed, "hello, ai!"); // Expect lower-case and trimmed output
}

TEST(NLPProcessorTest, PostprocessOutputFormatsCorrectly) {
    NLPProcessor nlp;
    std::string postprocessed = nlp.postprocessOutput("HELLO FROM AI");
    EXPECT_EQ(postprocessed, "Hello from AI."); // Expect sentence case with a period appended
}

