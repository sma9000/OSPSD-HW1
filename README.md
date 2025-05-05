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
│   ├── Config.h                     # Implementation header
│   ├── ConversationClient.h         # Implementation header
│   ├── ConversationHistory.h        # Implementation header
│   ├── Error.h                      # Error class definitions
│   ├── IMessage.h                   # Interface: Message contract
│   ├── IConfig.h                    # Interface: Config contract
│   ├── IConversationClient.h        # Interface: Conversation client contract
│   └── IConversationHistory.h       # Interface: History contract
├── mail-client/                     # Git submodule for Gmail integration
│   └── mail_gmail_impl/             # Python implementation for Gmail API
│       └── gmail_client.py
├── scripts/                         # Project scripts
│   └── fetch_emails.py               # Fetches Gmail emails to emails.csv
├── src/                             # C++ implementation source files
│   ├── Config.cpp
│   ├── ConversationClient.cpp
│   ├── ConversationHistory.cpp
│   ├── Message.cpp
│   └── integrate.cpp
│
├── tests/                           # Unit tests for all components
│    ├── test_config.cpp
│   ├── test_conversation.cpp
│   ├── test_conversation_client.cpp
│   ├── test_conversation_history.cpp
│   ├── test_error.cpp
│   ├── test_message.cpp
│   ├── test_integration.cpp
│   ├── test_interfaces.cpp
│   ├── test_endpoint.cpp
│   └── test_e2e.cpp
├── .gitignore                       # Files ignored by Git
├── .gitmodules                      # Submodule tracking configuration
├── CMakeLists.txt                   # Main CMake build configuration
├── README.md                        # Main documentation
├── interface.md                     # Interface design description
└── pull_request_template.md         # PR structure for GitHub

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


This milestone is focused on integrating external email input with AI-driven spam classification. It builds on the interface scaffolding created in previous steps and connects it to real-world data via the Gmail API and OpenAI’s endpoints.

Step 1: Mail Client Setup  
- Connected inbox component using Git submodule  
- Ran Python script `fetch_emails.py` to crawl Gmail and create `emails.csv`  
- Gmail OAuth configured with personal Gmail account  

Step 2: Integration  
- Implemented `integrate.cpp` which:
  - Loads `emails.csv`
  - Sends email content to OpenAI’s API
  - Extracts response (e.g., spam probability) and saves to `results.csv`
Step 3: End-to-End Testing  
- Final testing of the entire pipeline (email crawl → integration → AI response)
- Added new test files to validate system behavior across boundaries
- Ensured any test failure triggers E2E failure in CircleCI pipeline


## Setup & Installation

```bash
git clone https://github.com/sma9000/OSPSD-HW1.git
cd hw4-step3
git checkout hw4-step3
```


### OpenAI API Setup

### 1. Get the API Key
For shared organizations, each team member can:
- Log into https://platform.openai.com/
- Create a new API key or reuse an existing one

### 2. Export the API Key in Terminal
```bash
export OPENAI_API_KEY="your-key-here"
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
cd vcpkg
./bootstrap-vcpkg.sh
./vcpkg install cpr nlohmann-json
cd ..
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
```
System-wide Alternative:
```bash
brew install cpr nlohmann-json         # macOS
sudo apt install libcpr-dev nlohmann-json3-dev  # Linux
```

Install Required Python Libraries
```bash
pip install pandas                  # For saving data as CSV
pip install html2text              # To convert HTML emails to readable text
pip install --upgrade google-api-python-client google-auth-httplib2
```

Set up Gmail OAuth with Your Personal Gmail:
-Visit: https://console.cloud.google.com/welcome?project=nyu-data-454619
-Create a new project
-Enable the Gmail API under “APIs & Services > Library”
-Go to Credentials > OAuth Consent Screen
   Choose External
   Add your Gmail as a test user
   Go to Credentials > Create Credentials > OAuth Client ID
   Choose “Desktop App”
-Download the JSON file and rename it to credentials.json
-Place it in your project’s root directory (next to scripts/)


### Running Tests (Unit + End-to-End)

### Full End-to-End Test Pipeline

To validate the complete system workflow:

```bash
# Step 1: Fetch emails using Gmail client
python scripts/fetch_emails.py

# Step 2: Build system
rm -rf build/
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="$(pwd)/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build

# Step 3: Run integration logic
./build/integrate

# Step 4: Run E2E and Unit Tests
cmake --build . --config Release
ctest -C Release --output-on-failure


What It Does:
This pipeline validates the complete system behavior from input ingestion (Gmail) to AI classification and result persistence by chaining together all major components:
1. Crawls Emails
Uses the Gmail client (Python) to fetch emails and saves them to emails.csv.

2. Runs Integration Logic
The C++ program integrate.cpp loads the emails.csv, sends each email’s content to the OpenAI API (via your OPENAI_API_KEY), and receives a spam classification response.

3. Stores Results
The spam classification responses are parsed, and the results are written to results.csv in the following format:
```csv
mail_id,Pct_spam
123abc,0.72
456def,0.10
...
```

4. Runs All Tests
Finally, all test files (unit + E2E) are executed using ctest. These include:
  Component-level tests (e.g., test_config.cpp, test_error.cpp)
  Integration tests (e.g., test_integration.cpp)
  End-to-end tests (e.g., test_e2e.cpp)
If any test fails, the E2E pipeline is considered a failure.


## Unit & End-to-End Testing
This project uses Google Test and CMake for unit testing.
-Prerequisites
CMake >= 3.10
g++ or clang++
GoogleTest (installed via vcpkg or system-wide)
Project dependencies installed (see setup instructions)

To Build and Run All Tests:
```bash
# From project root
cmake --build . --config Release
ctest -C Release --output-on-failure
```


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


### Code Coverage:
Coverage is partially applicable in this phase.
While interface files are not covered, the integrate.cpp component includes executable logic that can be measured using gcov or lcov.
CircleCI is configured to generate these reports.




## Continuous Integration

This repository is configured to use CircleCI for continuous integration. The CircleCI configuration file is located at `.circleci/config.yml`. It includes steps for building the project, running tests, performing static analysis, and generating code coverage reports. CircleCI is configured to automatically run the full pipeline, ensuring any failed test (including test_e2e.cpp) blocks the build.

What CircleCI Does:
- Builds the project using CMake and a clean environment each time changes are pushed.
- Installs dependencies like GoogleTest via vcpkg.
- Runs unit tests and reports their success or failure.
- Performs static code analysis using clang-tidy to catch code quality and correctness issues.
- Checks code formatting with clang-format to ensure consistent style.
- Generates code coverage reports using lcov and gcov to track tested vs. untested lines of code.
- Stores artifacts and test results for further inspection or documentation.



### CircleCI Links

- ❌ Failed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/161/workflows/7b238ae2-3bdf-4711-a491-9dda1fa8ecc2/jobs/184)  
- ✅ Passed Test: [Link](https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/165/workflows/ef341b0a-fa8e-4b8c-a713-0f3ec9ab2c33)

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