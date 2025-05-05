
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
├── .circleci/                        # CI/CD configuration
│   └── config.yml                    # CircleCI pipeline
├── .github/ISSUE_TEMPLATE/          # GitHub issue templates
├── extern/                          # External dependencies (e.g., interfaces)
├── include/                         # Public C++ header files (interfaces)
│   ├── Config.h
│   ├── ConversationClient.h
│   ├── ConversationHistory.h
│   ├── Error.h
│   ├── IMessage.h
│   ├── IConfig.h
│   ├── IConversationClient.h
│   └── IConversationHistory.h
├── mail-client/
│   └── mail_gmail_impl/
│       └── gmail_client.py
├── scripts/
│   └── run_pipeline.py              # Fetches Gmail emails to and runs pipeline
├── src/
│   ├── Config.cpp
│   ├── ConversationClient.cpp
│   ├── ConversationHistory.cpp
│   ├── Message.cpp
│   └── integrate.cpp
├── tests/
│   ├── test_config.cpp
│   ├── test_conversation.cpp
│   ├── test_conversation_client.cpp
│   ├── test_conversation_history.cpp
│   ├── test_error.cpp
│   ├── test_message.cpp
│   ├── test_integration.cpp
│   ├── test_interfaces.cpp
│   ├── test_endpoint.cpp
│   └── test_e2e.cpp
├── .gitignore
├── .gitmodules
├── CMakeLists.txt
├── README.md
├── interface.md
└── pull_request_template.md
```

## Features

- AI conversation flow (mocked and configurable)
- Message history tracking
- Singleton config manager
- Unit-tested components (GTest)
- Static analysis via clang-tidy and clang-format
- Continuous Integration with CircleCI

---

## Project Scope

This milestone focuses on integrating external email input with AI-driven spam classification. It builds on the interface scaffolding created in earlier steps and connects it to real-world data via the Gmail API and OpenAI’s endpoints.

### Step 1: Mail Client Setup

- Connected inbox component using Git submodule  
- Ran Python script `run_pipeline.py` to crawl Gmail and create `emails.csv`  
- Gmail OAuth configured with personal Gmail account

### Step 2: Integration

- Implemented `integrate.cpp` which:
  - Loads `emails.csv`
  - Sends email content to OpenAI’s API
  - Extracts response (e.g., spam probability) and saves to `results.csv`

### Step 3: End-to-End Testing

- Final testing of the entire pipeline (email crawl → integration → AI response)  
- Added new test files to validate system behavior across boundaries  
- Ensured any test failure triggers E2E failure in CircleCI pipeline

---

## Setup & Installation

```bash
git clone https://github.com/sma9000/OSPSD-HW1.git
cd hw4-step3
git checkout hw4-step3
```

### OpenAI API Setup

1. Visit https://platform.openai.com/
2. Create or reuse your API key
3. Export the key in your terminal:

```bash
export OPENAI_API_KEY="your-key-here"
```

### Required Tools

- CMake
- vcpkg
- Clang
- gcov

### Install C++ Dependencies

```bash
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg integrate install
./vcpkg/vcpkg install gtest cpr nlohmann-json
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
```

Or system-wide:

```bash
brew install cpr nlohmann-json         # macOS
sudo apt install libcpr-dev nlohmann-json3-dev  # Linux
```

### Install Python Libraries

```bash
pip install pandas html2text
pip install --upgrade google-api-python-client google-auth-httplib2
```

### Gmail OAuth Setup

- Visit: https://console.cloud.google.com/
- Create a new project
- Enable Gmail API under “APIs & Services > Library”
- Go to Credentials > OAuth Consent Screen
- Choose External and add your Gmail as a test user
- Go to Credentials > Create Credentials > OAuth Client ID > Desktop App
- Download the credentials JSON and rename it to `credentials.json`
- Place it in the project root

---

## Interface Usage (Preview)

*To be defined in a future update.*

---

## Running Tests

```bash
# Step 1: Fetch emails using Gmail client
python scripts/run_pipeline.py

# Step 2: Build system
rm -rf build/
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="$(pwd)/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build

# Step 3: Run integration logic
./build/integrate

# Step 4: Run E2E and Unit Tests
cmake --build . --config Release
ctest -C Release --output-on-failure
```

Example format of `results.csv`:

```csv
mail_id,Pct_spam
123abc,0.72
456def,0.10
```

---

## Static Analysis & Formatting

```bash
clang-tidy include/*.h -- -Iinclude
clang-format -i include/*.h tests/*.cpp
```

---

## API Reference

### Config

- `static Config* getInstance()`  
- `void set(key, value)`  
- `std::string get(key)`  
- `void clear()`  

### ConversationClient

- `void startConversation()`  
- `bool sendMessage(input)`  
- `std::string receiveResponse()`  
- `void endConversation()`  

### ConversationHistory

- `void addMessage(const Message&)`  
- `std::vector<Message> getMessages() const`  

### Message

- `std::string sender`  
- `std::string content`  
- `std::chrono::system_clock::time_point timestamp`  

### Error classes

- Base: `Error`
- Subclasses: `ServiceError`, `InputError`, `NetworkError`, etc.

---

## Continuous Integration

CircleCI is used for:

- Building the project
- Installing dependencies
- Running unit and integration tests
- Running static code checks (clang-tidy)
- Code formatting checks (clang-format)
- Code coverage with gcov/lcov

Example links:

- ❌ Failed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/161/workflows/7b238ae2-3bdf-4711-a491-9dda1fa8ecc2/jobs/184)  
- ✅ Passed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/165/workflows/ef341b0a-fa8e-4b8c-a713-0f3ec9ab2c33)

---

## Contributing

1. Fork the repository  
2. Create a new branch: `git checkout -b feature/your-feature`  
3. Make your changes  
4. Commit: `git commit -m 'Add feature'`  
5. Push: `git push origin feature/your-feature`  
6. Open a pull request  

---

## License

This project is licensed under the MIT License.
