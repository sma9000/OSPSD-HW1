# Conversation Client Project

This project demonstrates an AI conversation client built in C++ that interacts with the OpenAI API. It comprises several modules such as a configuration manager, conversation history tracker, custom error types, NLP processing, and response formatting. A full unit and integration testing suite is provided using GoogleTest.

## Features

- **Configuration Management:**  
  Uses a singleton `Config` class to ensure that configuration settings (e.g., API keys and endpoints) are managed centrally.

- **Conversation Client:**  
  Provides a simple interface to start a conversation, send messages, receive responses, and end conversations. In addition to real API calls, a "mock mode" bypasses external calls for controlled testing.

- **Conversation History:**  
  Tracks both user and AI messages in an in-memory storage that captures timestamps and message details.

- **Custom Error Handling:**  
  Implements custom error classes such as `NetworkError`, `IOError`, `ParseError`, `InputError`, `TimeoutError`, and `ServiceError` to provide detailed exception information.

- **NLP Processing:**  
  Offers basic preprocessing (e.g., trimming and lowercasing) and postprocessing of input/output. This component can be extended with more advanced NLP features.

- **Response Formatting:**  
  Formats AI responses with configurable tags, timestamps, and newlines. The formatting functionality is separated into its own module (`ResponseFormatter`).

- **Testing:**  
  The project includes a comprehensive set of unit and integration tests using GoogleTest, covering every major module and ensuring proper functionality in both real and mock modes.

## Project Structure

```plaintext
HW 2 - Implementation/
├── CMakeLists.txt                # CMake build configuration
├── README.md                     # Project documentation
├── src/                          # Source files for the conversation client
│   ├── ConversationClient.h
│   ├── ConversationClient.cpp
│   ├── ConversationHistory.h
│   ├── ConversationHistory.cpp
│   ├── Config.h
│   ├── Error.h
│   ├── Message.h
│   ├── NLPProcessor.h
│   ├── NLPProcessor.cpp
│   ├── ResponseFormatter.h
│   ├── ResponseFormatter.cpp
│   └── main.cpp                  # Main entry point for the application
└── tests/                        # GoogleTest unit and integration tests
    ├── test_config.cpp
    ├── test_conversation.cpp
    ├── test_conversation_client.cpp
    ├── test_conversation_history.cpp
    ├── test_error.cpp
    ├── test_message.cpp
    ├── test_nlp_processor.cpp
    ├── test_response_formatter.cpp
    └── test_ai_conversation_client_integration.cpp  # Integration tests for multi-turn conversations
```


## Dependencies

- **C++ Compiler:** A C++17 compliant compiler (e.g., g++, clang, MSVC).
- **CMake:** Version 3.10 or later.
- **GoogleTest:** Automatically fetched via CMake's FetchContent.
- **cpr:** For HTTP communication (if using API mode instead of mock mode).
- **nlohmann/json:** For JSON processing (if using API mode instead of mock mode).

> **Note:** This project is configured to use a "mock mode" for testing; real OpenAI API calls are bypassed unless the configuration is changed.
