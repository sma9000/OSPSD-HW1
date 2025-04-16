#include "INLPProcessor.h"
#include <gtest/gtest.h>
#include <algorithm>

// Mock NLP implementation
class MockNLPProcessor : public INLPProcessor {
public:
    std::string preprocessInput(const std::string& input) override {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    std::string postprocessOutput(const std::string& output) override {
        return output + ".";
    }
};

TEST(NLPInterfaceTest, PreprocessReturnsLowercaseString) {
    MockNLPProcessor nlp;
    std::string result = nlp.preprocessInput("Hello, AI");

    EXPECT_EQ(result, "hello, ai");
    EXPECT_TRUE((std::is_same<decltype(result), std::string>::value));
}

TEST(NLPInterfaceTest, PostprocessReturnsProperShape) {
    MockNLPProcessor nlp;
    std::string output = nlp.postprocessOutput("hi");
    EXPECT_EQ(output, "hi.");
}
