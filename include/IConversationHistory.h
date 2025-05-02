#ifndef ICONVERSATION_HISTORY_H
#define ICONVERSATION_HISTORY_H

#include "IMessage.h"
#include <vector>

/**
 * @brief Interface for storing and retrieving conversation history.
 *
 * This interface allows components to log messages during an AI conversation
 * session and access the full history when needed.
 */
class IConversationHistory {
public:
  /**
   * @brief Adds a message to the conversation history.
   * @param msg The message to add.
   */
  virtual void addMessage(const Message &msg) = 0;

  /**
   * @brief Retrieves all messages in the current conversation session.
   * @return A vector containing all stored messages.
   */
  virtual std::vector<Message> getMessages() const = 0;

  /**
   * @brief Virtual destructor.
   */
  virtual ~IConversationHistory() = default;
};

#endif // ICONVERSATION_HISTORY_H
