#ifndef CONVERSATION_CLIENT_H
#define CONVERSATION_CLIENT_H

#include <string>
#include "Message.h"
#include "ConversationHistory.h"
#include "NLPProcessor.h"

class ConversationClient {
public:
    void startConversation();
    bool sendMessage(const std::string& input);
    std::string receiveResponse();
    void endConversation();

private:
    ConversationHistory history;
    NLPProcessor nlp;
};

#endif // CONVERSATION_CLIENT_H
