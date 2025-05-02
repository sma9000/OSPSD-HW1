#ifndef CONVERSATION_CLIENT_H
#define CONVERSATION_CLIENT_H

#include "IConversationClient.h"
#include "ConversationHistory.h"
#include "IMessage.h"

#include <string>

class ConversationClient : public IConversationClient {
public:
    void startConversation() override;
    bool sendMessage(const std::string& input) override;
    std::string receiveResponse() override;
    void endConversation() override;

private:
    ConversationHistory history;
};

#endif // CONVERSATION_CLIENT_H
