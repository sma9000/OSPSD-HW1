#include "gtest/gtest.h"
#include "logger.h"
#include <sstream>
#include <iostream>

class LoggerTest : public ::testing::Test {
protected:
    std::streambuf* orig_buf;
    std::stringstream test_buf;
    
    void SetUp() override {
        orig_buf = std::cout.rdbuf(test_buf.rdbuf()); // Redirect std::cout to test_buf
    }
    
    void TearDown() override {
        std::cout.rdbuf(orig_buf); // Restore original buffer
    }
};

TEST_F(LoggerTest, LogOperation) {
    Logger logger;
    logger.log("add", 5);
    
    std::string output = test_buf.str();
    EXPECT_NE(output.find("Operation: add, Result: 5"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
