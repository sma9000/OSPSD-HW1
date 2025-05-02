#ifndef MESSAGE_H
#define MESSAGE_H

#include <chrono>
#include <string>

/**
 * @brief Represents a message exchanged in a conversation.
 *
 * The Message struct holds metadata about the sender, the content of the
 * message, and a timestamp indicating when it was created.
 */
struct Message {
  /**
   * @brief Identifier of the message sender (e.g., "user" or "AI").
   */
  std::string sender;

  /**
   * @brief Content of the message.
   */
  std::string content;

  /**
   * @brief Timestamp indicating when the message was created.
   */
  std::chrono::system_clock::time_point timestamp;
};

#endif // MESSAGE_H
