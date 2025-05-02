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
├── include/                         # Header files
│   ├── Config.h
│   ├── ConversationClient.h
│   ├── ConversationHistory.h
│   ├── Message.h
│   └── Error.h
├── src/                             # Source files (implementations)
│   ├── Config.cpp
│   ├── ConversationClient.cpp
│   ├── ConversationHistory.cpp
│   └── Message.cpp
├── tests/                           # Unit tests
│   ├── test_config.cpp
│   ├── test_conversation_client.cpp
│   ├── test_conversation_history.cpp
│   ├── test_error.cpp
│   ├── test_message.cpp
├── .circleci/                       # CircleCI pipeline
│   └── config.yml
├── CMakeLists.txt                   # Build configuration
├── README.md                        # Project documentation

```

This repository provides a full-stack C++ template for developing AI-driven conversation systems with:
- **Natural Language Processing**: Preprocesses and postprocesses input and output.
- **Message Handling**: Stores and tracks conversations.
- **Custom Errors**: Granular error types for cleaner exception handling.
- **Response Formatting**: Timestamping, tagging, and output styling.
- **Singleton Configuration**: Centralized settings management.

### Features
-AI conversation flow (mocked and configurable)
-Message history tracking
-Singleton config manager
-Unit-tested components (GTest)
-Static analysis via clang-tidy and clang-format
-Continuous Integration with CircleCI

---

## Project Scope

**In Scope:**
- Header files defining core component APIs
- Documentation: `README.md`, `component.md`, `interface.md`
-Concrete implementation of core interfaces
-Full unit test coverage
-Configurable runtime behavior via Config

**Out of Scope:**
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
# Go to your root directory
cd ~/Desktop/OSPSD-HW1

# Remove any old build files
rm -rf build
mkdir build
cd build

# Rebuild with vcpkg toolchain
cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
make -j$(sysctl -n hw.logicalcpu)

# Run all unit tests
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

These classes are now implemented (not just defined).

Config
`static Config* getInstance()`

`void set(key, value)`

`std::string get(key)`

`void clear()`

ConversationClient
`void startConversation()`

`bool sendMessage(input) (mock mode returns static response)`

`std::string receiveResponse()`

`void endConversation()`

ConversationHistory
`void addMessage(const Message&)`

`std::vector<Message> getMessages() const`

Message
`std::string sender`

`std::string content`

`std::chrono::system_clock::time_point timestamp`

Error classes
`Base class: Error`

Subclasses: ServiceError, InputError, NetworkError, etc.




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