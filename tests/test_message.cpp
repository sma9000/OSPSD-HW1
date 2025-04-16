#include "Message.h"
#include <gtest/gtest.h>
#include <chrono>

TEST(MessageTest, ConstructorInitializesCorrectly) {
    auto now = std::chrono::system_clock::now();
    Message message = {"UserA", "Hello!", now};

    EXPECT_EQ(message.sender, "UserA");
    EXPECT_EQ(message.content, "Hello!");
    EXPECT_EQ(message.timestamp, now);
}

TEST(MessageTest, TimestampIsSetCorrectly) {
    auto now = std::chrono::system_clock::now();
    Message message = {"UserA", "Testing timestamp", now};

    EXPECT_GE(message.timestamp, now); // Timestamp should be equal or after the creation time
}

