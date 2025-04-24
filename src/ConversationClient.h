#ifndef CONVERSATION_CLIENT_H
#define CONVERSATION_CLIENT_H

#include "IConversationClient.h"
#include "ConversationHistory.h"
#include "NLPProcessor.h"
#include "Message.h"

#include <string>

class ConversationClient : public IConversationClient {
public:
    void startConversation() override;
    bool sendMessage(const std::string& input) override;
    std::string receiveResponse() override;
    void endConversation() override;

private:
    ConversationHistory history;
    NLPProcessor nlp;
};

#endif // CONVERSATION_CLIENT_H
