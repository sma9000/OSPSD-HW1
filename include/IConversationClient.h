// IConversationClient.h
#ifndef ICONVERSATION_CLIENT_H
#define ICONVERSATION_CLIENT_H

#include <string>

class IConversationClient {
public:
    virtual void startConversation() = 0;
    virtual bool sendMessage(const std::string& input) = 0;
    virtual std::string receiveResponse() = 0;
    virtual void endConversation() = 0;

    virtual ~IConversationClient() {}
};

#endif // ICONVERSATION_CLIENT_H