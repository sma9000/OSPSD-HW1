#include "NLPProcessor.h"
#include <gtest/gtest.h>
#include <algorithm>
#include <type_traits>

TEST(NLPProcessorTest, PreprocessReturnsTrimmedLowercaseString) {
    NLPProcessor nlp;
    std::string result = nlp.preprocessInput("  Hello, AI  ");

    // Should be lowercase and trimmed
    EXPECT_EQ(result, "hello, ai");
    EXPECT_TRUE((std::is_same<decltype(result), std::string>::value));
}

TEST(NLPProcessorTest, PostprocessRemovesWhitespaceAndFormats) {
    NLPProcessor nlp;
    std::string result = nlp.postprocessOutput("  response with spacing  ");
    
    EXPECT_EQ(result, "response with spacing");
}
