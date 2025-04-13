#include "ResponseFormatter.h"
#include <gtest/gtest.h>
#include <string>

TEST(ResponseFormatterTest, FormatResponseAppendsTagAndSuffix) {
    // Using a tag that is not predefined will append the tag after the message.
    std::string formatted = ResponseFormatter::formatResponse("Hello", "[TAG]", "!");
    EXPECT_EQ(formatted, "Hello [TAG]!");
}

TEST(ResponseFormatterTest, AddTimestampAppendsCorrectly) {
    std::string response = "Hello";
    std::string timestamped = ResponseFormatter::addTimestamp(response);
    EXPECT_TRUE(timestamped.find("Hello") != std::string::npos);
    // Since the actual year may vary, we check that a typical year appears in the timestamp.
    EXPECT_TRUE(timestamped.find("2025") != std::string::npos || timestamped.find("202") != std::string::npos);
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

