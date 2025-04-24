#ifndef CONVERSATION_HISTORY_H
#define CONVERSATION_HISTORY_H

#include "IConversationHistory.h"
#include "Message.h"
#include <vector>

class ConversationHistory : public IConversationHistory {
public:
    void addMessage(const Message& msg) override;
    std::vector<Message> getMessages() const override;

private:
    std::vector<Message> history;
};

#endif // CONVERSATION_HISTORY_H
