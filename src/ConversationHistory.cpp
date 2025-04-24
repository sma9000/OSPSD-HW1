#include "ConversationHistory.h"

void ConversationHistory::addMessage(const Message& msg) {
    history.push_back(msg);
}

std::vector<Message> ConversationHistory::getMessages() const {
    return history;
}
