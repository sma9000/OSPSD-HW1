# AI Conversation Client

Welcome to the AI Conversation Client! This project is a lightweight, extensible C++ client designed for managing AI-driven conversations based on the template repository configured previously. It simulates natural language interactions by processing user input, generating responses, maintaining conversation history, and handling various error and formatting scenarios. It is a draft/starting point with future feature updates to come. 

## Table of Contents
- [Overview](#overview)
  - [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Basic Usage](#basic-usage)
- [API Reference](#api-reference)
  - [Config](#config)
  - [ConversationClient](#conversationclient)
  - [ConversationHistory](#conversationhistory)
  - [Error Classes](#error-classes)
  - [Message](#message)
  - [NLPProcessor](#nlpprocessor)
  - [ResponseFormatter](#responseformatter)
- [Contributing](#contributing)
- [CircleCI Links](#circleci-links)
- [License](#license)

## Overview

This repository provides a full-stack C++ template for developing AI-driven conversation systems with:
- **Natural Language Processing**: Preprocesses and postprocesses input and output.
- **Message Handling**: Stores and tracks conversations.
- **Custom Errors**: Granular error types for cleaner exception handling.
- **Response Formatting**: Timestamping, tagging, and output styling.
- **Singleton Configuration**: Centralized settings management.

### Project Structure

```plaintext
├── src
│   ├── Config.h                   # Singleton class for global settings
│   ├── ConversationClient.h       # Entry point for the conversation system
│   ├── ConversationHistory.h      # Maintains message history
│   ├── Error.h                    # Custom error class hierarchy
│   ├── Message.h                  # Data structure representing a message
│   ├── NLPProcessor.h             # Handles input/output text processing
│   ├── ResponseFormatter.h        # Formats and decorates responses
│   └── main.cpp                   # Example usage and entry point
├── tests
│   └── test_conversation.cpp      # Unit tests @Nabiha 
├── CMakeLists.txt                 # CMake configuration file
├── Makefile                       # Makefile for quick builds
└── README.md                      # Project documentation

```

## Getting Started

### Prerequisites

Make sure you have the following tools installed:
- [CMake](https://cmake.org/)
- [vcpkg](https://github.com/microsoft/vcpkg)
- [Clang](https://clang.llvm.org/)
- [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html)

### Installation

Clone the repository and install dependencies using `vcpkg`:

```bash
git clone https://github.com/yourusername/advanced-cpp-template-repo.git
cd advanced-cpp-template-repo
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg integrate install
./vcpkg/vcpkg install gtest
```

## Usage

### Basic Usage

Here is a basic example of starting a conversation using the `ConversationClient`:

```cpp
#include "ConversationClient.h"

int main() {
    ConversationClient client;
    client.startConversation();
    client.sendMessage("Hello, world!");
    std::string response = client.receiveResponse();
    client.endConversation();
    return 0;
}
```
@nabha update here?{
  ### Building the Project
  Configure and build the project using CMake:

  ```bash
  cmake -Bbuild -H.
  cmake --build build
  ```
  ### Running Tests
  Run the unit tests using the Google Test framework:


  ```bash
  ./build/tests
  ```

  ### Static Analysis
  Run static analysis using ClangTidy:

  ```bash
  clang-tidy src/*.cpp
  ```

  ### Code Coverage
  Generate code coverage reports using gcov:

  ```bash
  gcov src/*.cpp
  
  ```
}
## Components

# API Reference

Detailed description of the API functionalities provided by each header.

---

## Config

**Purpose**: Manages configuration settings as a singleton.

### Functions:

- `static Config* getInstance()`: Retrieves the singleton instance.
- `void set(const std::string& key, const std::string& value)`: Sets a configuration parameter.
- `std::string get(const std::string& key) const`: Retrieves a configuration value.

---

## ConversationClient

**Purpose**: Handles the flow of conversation.

### Functions:

- `void startConversation()`: Initializes a conversation.
- `bool sendMessage(const std::string& input)`: Sends a message to the conversation.
- `std::string receiveResponse()`: Receives a response from the conversation.
- `void endConversation()`: Ends the conversation.

---

## ConversationHistory

**Purpose**: Stores messages within a conversation.

### Functions:

- `void addMessage(const Message& msg)`: Adds a message to the history.
- `std::vector<Message> getMessages() const`: Retrieves all messages from the history.

---

## Error Classes

**Purpose**: Defines various error types for robust error handling.

### Types:

- `NetworkError`
- `IOError`
- `ParseError`
- `InputError`
- `TimeoutError`
- `ServiceError`

These are custom exception types for handling specific error scenarios.

---

## Message

**Purpose**: Represents a message structure.

### Details:

- Contains `sender`, `content`, and `timestamp`.

---

## NLPProcessor

**Purpose**: Processes natural language input and output.

### Functions:

- `std::string preprocessInput(const std::string& input)`: Preprocesses the input text.
- `std::string postprocessOutput(const std::string& output)`: Postprocesses the output text.

---

## ResponseFormatter

**Purpose**: Formats and manipulates response strings.

### Functions:

- `static std::string formatResponse(const std::string &rawResponse, const std::string &tag, const std::string &suffix)`: Formats a response with tags and suffix.
- `static std::string addTimestamp(const std::string &response)`: Appends a timestamp to the response.
- `static std::string toUpperCase(const std::string &response)`: Converts the response to uppercase.
- `static std::string addNewLineIfNeeded(const std::string &response)`: Ensures the response ends with a newline.
### Further features will have updates here

## Continuous Integration
This repository is configured to use CircleCI for continuous integration. The CircleCI configuration file is located at .circleci/config.yml. It includes steps for building the project, running tests, performing static analysis, and generating code coverage reports.

## Contributing
We welcome contributions! Please follow these guidelines when contributing to this project:

1. Fork the repository.

2. Create a new branch (git checkout -b feature/your-feature).

3. Make your changes.

4. Commit your changes (git commit -m 'Add some feature').

5. Push to the branch (git push origin feature/your-feature).

6. Open a pull request.

## CircleCI Links

Failed Test: https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/94/workflows/219c0286-71d3-487f-8578-4462571db7cf/jobs/117 

Passed Test: https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/97/workflows/c594cb81-ccf3-4cd1-adaa-fe5b6dea1cbc/jobs/120
}

## License
This project is licensed under the MIT License.
