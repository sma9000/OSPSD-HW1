//
// Created by Salma Awan on 2/12/25.
//
#include <gtest/gtest.h>
#include "notifier.h"

using namespace std;

TEST(NotifierTest, ThresholdExceeded) {
Notifier notifier(100.0);
EXPECT_TRUE(notifier.sendAlert(150.0)); //non-fatal assertion
}

TEST(NotifierTest, ThresholdNotExceeded) {
Notifier notifier(100.0);
EXPECT_FALSE(notifier.sendAlert(50.0));
}

TEST(NotifierTest, ThresholdExact) {
Notifier notifier(100.0);
EXPECT_FALSE(notifier.sendAlert(100.0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "======================" << std::endl;
    std::cout << "Running Google Tests!" << std::endl;
    std::cout << "======================" << std::endl;

    // Force Google Test to show detailed output
    ::testing::GTEST_FLAG(output) = "xml";  // Enables test result logging
    ::testing::GTEST_FLAG(also_run_disabled_tests) = true;
    ::testing::GTEST_FLAG(print_time) = true; // Show test execution time

    return RUN_ALL_TESTS();

}
