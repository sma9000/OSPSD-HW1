# AI Conversation Client

Welcome to the AI Conversation Client! This project is a lightweight, extensible C++ client designed for managing AI-driven conversations based on the template repository configured previously. It simulates natural language interactions by processing user input, generating responses, maintaining conversation history, and handling various error and formatting scenarios. It is a draft/starting point with future feature updates to come. 

## Table of Contents

- [Overview](#overview)
  - [Project Structure](#project-structure)
- [Features](#features)
- [Project Scope](#project-scope)
- [Setup & Installation](#setup--installation)
- [Interface Usage (Preview)](#interface-usage-preview)
- [Running Tests](#running-tests)
- [Static Analysis & Formatting](#static-analysis--formatting)
- [API Reference](#api-reference)
- [Continuous Integration](#continuous-integration)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

This repository provides an interface-level C++ structure for developing an AI conversation system, including NLP processing, message handling, formatting, and configuration management. 

### Project Structure

```plaintext
├── include/                         # Header interfaces for each component
│   ├── IConfig.h
│   ├── IConversationClient.h
│   ├── IConversationHistory.h
│   ├── IMessage.h
│   ├── INLPProcessor.h
│   └── IResponseFormatter.h
├── src/                             # Empty in HW2, will contain implementation in HW3

├── tests/                           # Unit tests for interface behavior
│   ├── test_config.cpp
│   ├── test_conversation.cpp
│   ├── test_conversation_client.cpp
│   ├── test_conversation_history.cpp
│   ├── test_error.cpp
│   ├── test_message.cpp
│   ├── test_response_formatter.cpp

├── .circleci/                       # Continuous integration setup
│   └── config.yml

├── interface.md                     # Interface definitions and documentation
├── pull_request_template.md         # GitHub PR template for contributors
├── CMakeLists.txt                   # Build configuration
├── .gitignore                       # Ignore rules
├── README.md                        # Project overview and instructions
```

This repository provides a full-stack C++ template for developing AI-driven conversation systems with:
- **Natural Language Processing**: Preprocesses and postprocesses input and output.
- **Message Handling**: Stores and tracks conversations.
- **Custom Errors**: Granular error types for cleaner exception handling.
- **Response Formatting**: Timestamping, tagging, and output styling.
- **Singleton Configuration**: Centralized settings management.

### Features
- Interface-only architecture  
- Mock-based tests with GoogleTest  
- Static analysis support via `clang-tidy`  
- Code formatting with `clang-format`  
- CI-ready with CircleCI config included

---

## Project Scope

**In Scope:**
- Header files defining core component APIs
- Mock-based unit tests to validate interface contracts
- Documentation: `README.md`, `component.md`, `interface.md`

**Out of Scope:**
- API implementation  
- Real input/output processing  
- Persistent storage  
- Full integration/testing  

---

## Setup & Installation

```bash
git clone https://github.com/sma9000/OSPSD-HW1.git
cd interface-definition-finalmod
git checkout interface-definition-finalmod
```

Make sure you have the following tools installed:
- [CMake](https://cmake.org/)
- [vcpkg](https://github.com/microsoft/vcpkg)
- [Clang](https://clang.llvm.org/)
- [gcov](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html)

Install dependencies using `vcpkg` and install GoogleTest:

```bash
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg integrate install
./vcpkg/vcpkg install gtest
```

---

## Interface Usage (Preview)

Below is a hypothetical example of how an external user might use the interfaces once implemented (for HW3):

```cpp
#include "IConversationClient.h"

int main() {
    // This is just illustrative — implementation does not exist yet
    IConversationClient* client; // Assume this is initialized via dependency injection
    client->startConversation();
    client->sendMessage("Hello, world!");
    std::string response = client->receiveResponse();
    client->endConversation();
    return 0;
}
```

---

## Running Tests

## Testing Locally
-This project uses Google Test and CMake for unit testing.
-Prerequisites
CMake >= 3.10
g++ or clang++
GoogleTest (installed via vcpkg or system-wide)
Project dependencies installed (see setup instructions)

# Build and Run Tests

```bash
# From the root directory
mkdir -p build && cd build
cmake ..
make
ctest --output-on-failure
```

What It Does:
1. Compiles the test files in /tests/
2. Runs them using ctest
3. Outputs failures (if any) for easy debugging

---

## Static Analysis & Formatting

### Run static analysis using Clang-Tidy:

```bash
clang-tidy include/*.h -- -Iinclude
```

### Format code with Clang-Format:

```bash
clang-format -i include/*.h tests/*.cpp
```

### Code Coverage:
Not applicable in this phase. Since this repo only defines interfaces without implementation,
there is no source code to analyze for coverage.


---

## API Reference

Below is a summary of the interfaces defined in the project. These interfaces specify the public methods and expected behavior for each component. Implementation is out of scope for this phase.

### IConfig
**Purpose**: Manages global configuration settings.  
**Methods**:
- `static IConfig* getInstance()`
- `void set(const std::string& key, const std::string& value)`
- `std::string get(const std::string& key)`

---

### IConversationClient
**Purpose**: Manages the flow of an AI conversation.  
**Methods**:
- `void startConversation()`
- `bool sendMessage(const std::string& input)`
- `std::string receiveResponse()`
- `void endConversation()`

---

### IConversationHistory
**Purpose**: Stores and retrieves conversation history.  
**Methods**:
- `void addMessage(const IMessage& message)`
- `std::vector<IMessage> getMessages() const`

---

### IMessage
**Purpose**: Defines the structure of a message object.  
**Attributes / Methods**:
- `std::string getSender() const`
- `std::string getContent() const`
- `std::string getTimestamp() const`

---

### INLPProcessor
**Purpose**: Handles natural language input/output processing.  
**Methods**:
- `std::string preprocessInput(const std::string& input)`
- `std::string postprocessOutput(const std::string& output)`

---

### IResponseFormatter
**Purpose**: Provides formatting utilities for response output.  
**Methods**:
- `std::string formatResponse(const std::string& raw, const std::string& tag, const std::string& suffix)`
- `std::string addTimestamp(const std::string& response)`
- `std::string toUpperCase(const std::string& response)`
- `std::string addNewLineIfNeeded(const std::string& response)`

---

## Continuous Integration

This repository is configured to use CircleCI for continuous integration. The CircleCI configuration file is located at `.circleci/config.yml`. It includes steps for building the project, running tests, performing static analysis, and generating code coverage reports.
What CircleCI Does:
- Builds the project using CMake and a clean environment each time changes are pushed.
- Installs dependencies like GoogleTest via vcpkg.
- Runs unit tests and reports their success or failure.
- Performs static code analysis using clang-tidy to catch code quality and correctness issues.
- Checks code formatting with clang-format to ensure consistent style.
- Generates code coverage reports using lcov and gcov to track tested vs. untested lines of code.
- Stores artifacts and test results for further inspection or documentation.



### CircleCI Links

- ❌ Failed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/32/workflows/b957f89b-208f-4729-9ece-e86ee0d02898/jobs/53)  
- ✅ Passed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/33/workflows/ded46d0c-9381-468b-9828-83327ac59a48/jobs/56)

---

## Contributing

We welcome contributions! Please follow these guidelines:

1. Fork the repository  
2. Create a new branch: `git checkout -b feature/your-feature`  
3. Make your changes  
4. Commit: `git commit -m 'Add some feature'`  
5. Push: `git push origin feature/your-feature`  
6. Open a pull request  

---

## License

This project is licensed under the MIT License.