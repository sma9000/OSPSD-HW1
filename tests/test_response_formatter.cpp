#include "ResponseFormatter.h"
#include <gtest/gtest.h>
#include <string>
#include <ctime>
#include <algorithm>

TEST(ResponseFormatterTest, FormatResponseUsesTagPrefix) {
    ResponseFormatter::initializeTags();  
    std::string result = ResponseFormatter::formatResponse("Hello", "info", "!");
    EXPECT_EQ(result, "[INFO] Hello!");
}

TEST(ResponseFormatterTest, FormatResponseFallbacksToInlineTag) {
    ResponseFormatter::initializeTags();
    std::string result = ResponseFormatter::formatResponse("Hello", "custom", "!");
    EXPECT_EQ(result, "Hello custom!");
}

TEST(ResponseFormatterTest, AddTimestampIncludesMessage) {
    std::string result = ResponseFormatter::addTimestamp("Hello");
    EXPECT_TRUE(result.find("Hello") != std::string::npos);
    EXPECT_TRUE(result.find("[") == 0); // Timestamp prefix
}

TEST(ResponseFormatterTest, ToUpperCaseConvertsCorrectly) {
    std::string result = ResponseFormatter::toUpperCase("hello");
    EXPECT_EQ(result, "HELLO");
}

TEST(ResponseFormatterTest, AddNewLineAppendsIfMissing) {
    std::string result = ResponseFormatter::addNewLineIfNeeded("Hello");
    EXPECT_EQ(result, "Hello\n");
}

TEST(ResponseFormatterTest, AddNewLineDoesNothingIfPresent) {
    std::string result = ResponseFormatter::addNewLineIfNeeded("Hello\n");
    EXPECT_EQ(result, "Hello\n");
}
