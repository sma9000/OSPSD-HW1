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

├── src/                             # Empty in HW2, will contain implementation in HW3

├── tests/                           # Unit tests for interface behavior

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




### CircleCI Links


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