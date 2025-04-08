#include "calculator.h"
#include "logger.h"
#include <gtest/gtest.h>

TEST(CalculatorLoggerIntegrationTest, TestAdditionLogging) {
    // Arrange
    Calculator calculator;
    Logger logger;

    double a = 5.0, b = 3.0;
    double result = calculator.add(a, b);

    // Act and Assert (Mock or Spy Logger Output)
    logger.log("Addition", static_cast<int>(result)); // Log operation
    ASSERT_EQ(result, 8.0);
    // Verify Logger prints the correct message manually if no mock is implemented.
}
