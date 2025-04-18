#include "ResponseFormatter.h"
#include <gtest/gtest.h>

TEST(ResponseFormatterTest, FormatResponseAppendsTagAndSuffix) {
    std::string formatted = ResponseFormatter::formatResponse("Hello", "[TAG]", "!");
    EXPECT_EQ(formatted, "Hello [TAG]!");
}

TEST(ResponseFormatterTest, AddTimestampAppendsCorrectly) {
    std::string response = "Hello";
    std::string timestamped = ResponseFormatter::addTimestamp(response);
    EXPECT_TRUE(timestamped.find("Hello") != std::string::npos);
    EXPECT_TRUE(timestamped.find("2025") != std::string::npos); // Example timestamp
}

TEST(ResponseFormatterTest, ToUpperCaseTransformsCorrectly) {
    std::string uppercased = ResponseFormatter::toUpperCase("hello");
    EXPECT_EQ(uppercased, "HELLO");
}

TEST(ResponseFormatterTest, AddNewLineIfNeededEnsuresNewline) {
    std::string response = "Hello";
    std::string withNewline = ResponseFormatter::addNewLineIfNeeded(response);
    EXPECT_EQ(withNewline, "Hello\n");
}
