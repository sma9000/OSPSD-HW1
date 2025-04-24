#ifndef ICONVERSATION_HISTORY_H
#define ICONVERSATION_HISTORY_H

#include <vector>
#include "Message.h"  

class IConversationHistory {
public:
    virtual void addMessage(const Message& msg) = 0;
    virtual std::vector<Message> getMessages() const = 0;

    virtual ~IConversationHistory() = default;
};

#endif // ICONVERSATION_HISTORY_H
