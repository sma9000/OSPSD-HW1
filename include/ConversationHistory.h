#ifndef CONVERSATION_HISTORY_H
#define CONVERSATION_HISTORY_H

#include <vector>
#include "Message.h"

class ConversationHistory {
public:
    void addMessage(const Message& msg);
    std::vector<Message> getMessages() const;

private:
    std::vector<Message> history;
};

#endif // CONVERSATION_HISTORY_H
