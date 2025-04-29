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

├── .circleci/                       # CI/CD configuration (CircleCI)
│   └── config.yml                   # Pipeline configuration
├── .github/ISSUE_TEMPLATE/         # GitHub issue templates
│   └── bug_report.md               # Bug report template
├── .vscode/                        # VSCode project settings
├── data/                           # Sample data directory
│   └── sample_emails.csv           # Sample email data
├── extern/                         # External interface definitions
├── include/                        # Header files (cleaned/organized)
├── mail-client/                    # Submodule for mail client
├── scripts/                        # Scripts for email crawling, setup, etc.
│   └── save_emails.py              # Crawls Gmail and saves emails
├── src/                            # Core source files
│   ├── Config.h                    # Singleton class for global settings
│   ├── ConversationClient.h        # Entry point for the conversation system
│   ├── ConversationHistory.h       # Maintains message history
│   ├── Error.h                     # Custom error class hierarchy
│   ├── Message.h                   # Data structure representing a message
│   ├── NLPProcessor.h              # Handles input/output text processing
│   ├── ResponseFormatter.h         # Formats and decorates responses
│   └── main.cpp                    # Example usage and entry point
├── tests/                          # Unit tests
│   └── test_conversation.cpp       # Unit tests @Nabiha
├── .DS_Store                       # macOS metadata (should be gitignored)
├── .History                        # History log or backup
├── .gitignore                      # Specifies ignored files for Git
├── .gitmodules                     # Git submodules (e.g., mail-client)
├── CMakeLists.txt                  # CMake configuration file
├── Interface.md                    # Project interface definition
├── Makefile                        # Makefile for quick builds
├── README.md                       # Project documentation
├── pull_request_template.md       # Template for pull requests
└── sample_emails.csv              # (moved here from data/)


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
## Running save_emails.py
1. Install Python Dependencies
pip install pandas html2text
pip install --upgrade google-api-python-client google-auth-httplib2

2. Set Up OAuth with Gmail API
Go to https://console.cloud.google.com/
Create a new project
Enable Gmail API:
Navigate to APIs & Services > Library > Gmail API
Configure OAuth:
Go to Credentials > OAuth Consent Screen
Set up as an External app and add your Gmail as a test user
Under Credentials, create a new OAuth Client ID
App type: Desktop App
Download the credentials file (named something like client_secret_XXXXX.json)
Rename it to credentials.json

3. Run the Script
python scripts/save_emails.py
A browser window will open for Gmail sign-in.
Sign in with the Gmail account you added as a test user.
Grant permission when prompted.
If blocked, revisit the OAuth screen and ensure your Gmail is added under test users.

### Compiling and building to run integrate.cpp
1. Get the API Key:
Team members should log into the OpenAI Organization or use personal accounts: https://platform.openai.com/settings/organization/general
Create or reuse an API key.

2. Export the Key (Terminal):
export OPENAI_API_KEY="your-key-here" 

3. Install dependencies for integrate.cpp
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install cpr nlohmann-json
cd ..
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake

4. Clean build 
rm -rf build/
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="$(pwd)/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build
./build/integrate

### After running integrate.cpp
This will:

1. Load emails from emails.csv (generated by save_emails.py)

2. Send them to the AI response component

3. Extract the spam probability

4. Output the results to a CSV (e.g., results.csv)


 
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

##CircleCI Links

{

Failed Test: https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/119/workflows/f5d87104-336d-4124-942a-80c98859ef13/jobs/142 

Passed Test: https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/125/workflows/29b8382e-723c-45cd-9258-56885d1e9bb2/jobs/148
}

## License
This project is licensed under the MIT License.