#include "Error.h"
#include <gtest/gtest.h>

TEST(ErrorTest, BaseErrorMessageIsCorrect) {
  Error error("Generic error occurred");
  EXPECT_STREQ(error.what(), "Error: Generic error occurred");
}

TEST(ErrorTest, NetworkErrorMessageIsCorrect) {
  NetworkError networkError("Failed to connect to server");
  EXPECT_STREQ(networkError.what(),
               "Error: Network Error: Failed to connect to server");
}

TEST(ErrorTest, IOErrorMessageIsCorrect) {
  IOError ioError("File not found");
  EXPECT_STREQ(ioError.what(), "Error: IO Error: File not found");
}

TEST(ErrorTest, ParseErrorMessageIsCorrect) {
  ParseError parseError("Invalid JSON format");
  EXPECT_STREQ(parseError.what(), "Error: Parse Error: Invalid JSON format");
}

TEST(ErrorTest, InputErrorMessageIsCorrect) {
  InputError inputError("Empty input provided");
  EXPECT_STREQ(inputError.what(), "Error: Input Error: Empty input provided");
}

TEST(ErrorTest, TimeoutErrorMessageIsCorrect) {
  TimeoutError timeoutError("Operation timed out");
  EXPECT_STREQ(timeoutError.what(),
               "Error: Timeout Error: Operation timed out");
}

TEST(ErrorTest, ServiceErrorMessageIsCorrect) {
  ServiceError serviceError("Service unavailable");
  EXPECT_STREQ(serviceError.what(),
               "Error: Service Error: Service unavailable");
}