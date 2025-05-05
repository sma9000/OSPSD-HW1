
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
├── .circleci/
│   └── config.yml
├── .github/ISSUE_TEMPLATE/
├── extern/
├── include/
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
│   └── run_pipeline.py
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
│   └── test_message.cpp
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

**In Scope:**

This milestone is focused on integrating external email input with AI-driven spam classification. It builds on the interface scaffolding created in previous steps and connects it to real-world data via the Gmail API and OpenAI’s endpoints.

Step 1: Mail Client Setup  
- Connected inbox component using Git submodule  
- Ran Python script `run_pipeline.py` to crawl Gmail and create `emails.csv`  
- Gmail OAuth configured with personal Gmail account  

Step 2: Integration  
- Implemented `integrate.cpp` which:
  - Loads `emails.csv`
  - Sends email content to OpenAI’s API
  - Extracts response (e.g., spam probability) and saves to `results.csv`

**Out of Scope:**

Step 3: End-to-End Testing  
- Final test pass/fail logic  
- CircleCI test coverage thresholds  
- E2E integration validation

---

## Setup & Installation

```bash
git clone https://github.com/sma9000/OSPSD-HW1.git
cd hw4-step2
git checkout hw4-step2
```

### OpenAI API Setup

1. Log into https://platform.openai.com/
2. Create or reuse an API key
3. Export the key in your terminal:

```bash
export OPENAI_API_KEY="your-key-here"
```

### Tools Needed

- CMake
- vcpkg
- Clang
- gcov

### Install Dependencies

```bash
./vcpkg/bootstrap-vcpkg.sh
./vcpkg/vcpkg integrate install
./vcpkg/vcpkg install gtest cpr nlohmann-json
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
```

System-wide (alternative):

```bash
brew install cpr nlohmann-json
sudo apt install libcpr-dev nlohmann-json3-dev
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
- Create Credentials > OAuth Client ID > Desktop App
- Download the JSON file and rename it to `credentials.json`
- Place it in your project’s root directory

---

## Interface Usage (Preview)

_To be added in a future release._

---

## Running Tests

### Running Integration Pipeline

```bash
# Step 1: Generate emails.csv
python scripts/run_pipeline.py

# Step 2: Build and run integration logic
rm -rf build/
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="$(pwd)/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build
./build/integrate
```

What It Does:
- Sends each email’s body to OpenAI using the API key
- Receives a classification response
- Saves to `results.csv` like this:

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

### Errors

- Base class: `Error`
- Subclasses: `ServiceError`, `InputError`, `NetworkError`, etc.

---

## Continuous Integration

This project uses CircleCI to:

- Build with CMake
- Run tests
- Run static analysis (clang-tidy)
- Run format check (clang-format)
- Generate code coverage reports with gcov/lcov

### CircleCI Links

- ❌ Failed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/161/workflows/7b238ae2-3bdf-4711-a491-9dda1fa8ecc2/jobs/184)  
- ✅ Passed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/165/workflows/ef341b0a-fa8e-4b8c-a713-0f3ec9ab2c33)

---

## Contributing

1. Fork the repository  
2. Create a branch: `git checkout -b feature/your-feature`  
3. Make changes  
4. Commit: `git commit -m 'Add feature'`  
5. Push: `git push origin feature/your-feature`  
6. Open a pull request

---

## License

This project is licensed under the MIT License.
