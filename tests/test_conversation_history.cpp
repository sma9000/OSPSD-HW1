#include "IConversationHistory.h"
#include "IMessage.h"
#include <gtest/gtest.h>
#include <vector>
#include <chrono>

// Mock implementation
class MockConversationHistory : public IConversationHistory {
private:
    std::vector<Message> messages;
public:
    void addMessage(const Message& msg) override {
        messages.push_back(msg);
    }

    std::vector<Message> getMessages() const override {
        return messages;
    }
};

TEST(ConversationHistoryTest, AddMessageIncreasesSize) {
    MockConversationHistory history;
    Message msg = {"UserA", "Hello", std::chrono::system_clock::now()};

    history.addMessage(msg);
    EXPECT_EQ(history.getMessages().size(), 1);
}

TEST(ConversationHistoryTest, GetMessagesReturnsCorrectDataShape) {
    MockConversationHistory history;
    Message msg1 = {"UserA", "Hello", std::chrono::system_clock::now()};
    Message msg2 = {"UserB", "Hi there", std::chrono::system_clock::now()};

    history.addMessage(msg1);
    history.addMessage(msg2);

    auto messages = history.getMessages();
    EXPECT_EQ(messages.size(), 2);
    EXPECT_EQ(messages[0].content, "Hello");
    EXPECT_EQ(messages[1].content, "Hi there");
    EXPECT_TRUE((std::is_same<decltype(messages), std::vector<Message>>::value));
}
