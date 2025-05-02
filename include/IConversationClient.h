// IConversationClient.h
#ifndef ICONVERSATION_CLIENT_H
#define ICONVERSATION_CLIENT_H

#include <string>

/**
 * @brief Interface for managing AI conversation sessions.
 *
 * Defines methods for starting, managing, and terminating a conversation lifecycle,
 * as well as sending and receiving messages from the AI system.
 */
class IConversationClient {
public:
    /**
     * @brief Starts a new AI conversation session.
     */
    virtual void startConversation() = 0;

    /**
     * @brief Sends a user message to the conversation system.
     * @param input The message content to send.
     * @return True if the message was successfully sent and processed.
     */
    virtual bool sendMessage(const std::string& input) = 0;

    /**
     * @brief Retrieves the latest AI-generated response.
     * @return The response string from the conversation system.
     */
    virtual std::string receiveResponse() = 0;

    /**
     * @brief Ends the current conversation session.
     */
    virtual void endConversation() = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~IConversationClient() {}
};

#endif // ICONVERSATION_CLIENT_H
