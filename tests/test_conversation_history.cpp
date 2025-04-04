#include "ConversationHistory.h"
#include "Message.h"
#include <gtest/gtest.h>

TEST(ConversationHistoryTest, AddMessageIncreasesSize) {
    ConversationHistory history;
    Message msg = {"UserA", "Hello", std::chrono::system_clock::now()};

    history.addMessage(msg);
    EXPECT_EQ(history.getMessages().size(), 1);
}

TEST(ConversationHistoryTest, GetMessagesReturnsCorrectData) {
    ConversationHistory history;
    Message msg1 = {"UserA", "Hello", std::chrono::system_clock::now()};
    Message msg2 = {"UserB", "Hi there", std::chrono::system_clock::now()};

    history.addMessage(msg1);
    history.addMessage(msg2);

    auto messages = history.getMessages();
    EXPECT_EQ(messages.size(), 2);
    EXPECT_EQ(messages[0].content, "Hello");
    EXPECT_EQ(messages[1].content, "Hi there");
}

