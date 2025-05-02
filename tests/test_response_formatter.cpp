#include "IResponseFormatter.h"
#include <algorithm>
#include <ctime>
#include <gtest/gtest.h>
#include <string>

class MockResponseFormatter : public IResponseFormatter {
public:
  std::string formatResponse(const std::string &raw, const std::string &tag,
                             const std::string &suffix) override {
    return raw + " " + tag + suffix;
  }

  std::string addTimestamp(const std::string &response) override {
    return "[2025-04-16] " + response;
  }

  std::string toUpperCase(const std::string &response) override {
    std::string upper = response;
    std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    return upper;
  }

  std::string addNewLineIfNeeded(const std::string &response) override {
    return (response.back() != '\n') ? response + "\n" : response;
  }
};

TEST(ResponseFormatterTest, FormatResponseAppendsTagAndSuffix) {
  MockResponseFormatter formatter;
  std::string formatted = formatter.formatResponse("Hello", "[TAG]", "!");
  EXPECT_EQ(formatted, "Hello [TAG]!");
}

TEST(ResponseFormatterTest, AddTimestampAppendsCorrectly) {
  MockResponseFormatter formatter;
  std::string result = formatter.addTimestamp("Hello");
  EXPECT_TRUE(result.find("Hello") != std::string::npos);
  EXPECT_TRUE(result.find("2025") != std::string::npos); // Approximate
}

TEST(ResponseFormatterTest, ToUpperCaseTransformsCorrectly) {
  MockResponseFormatter formatter;
  std::string result = formatter.toUpperCase("hello");
  EXPECT_EQ(result, "HELLO");
}

TEST(ResponseFormatterTest, AddNewLineIfNeededEnsuresNewline) {
  MockResponseFormatter formatter;
  std::string result = formatter.addNewLineIfNeeded("Hello");
  EXPECT_EQ(result, "Hello\n");
}