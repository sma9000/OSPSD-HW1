#include <gtest/gtest.h>
#include "calculator.h"
#include "logger.h"
#include "notifier.h"

TEST(EndToEndTest, TestE2E) {
    Calculator calc;
    Logger logger;
    Notifier notifier(10);

    int result = calc.add(5, 6);
    testing::internal::CaptureStdout();
    logger.log("Result: " + std::to_string(result));
    notifier.notify(result);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Result: 11\nThreshold exceeded\n");
}
