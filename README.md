# Advanced C++ Template Repository

Welcome to the Advanced C++ Template Repository! This repository serves as a foundation for designing and developing C++ projects. It is fully equipped for immediate use and includes features for build management, unit testing, continuous integration, static analysis, code style adherence, and component specification.

## Table of Contents
- [Overview](#overview)
  - [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Building the Project](#building-the-project)
  - [Running Tests](#running-tests)
  - [Static Analysis](#static-analysis)
  - [Code Coverage](#code-coverage)
- [Components](#components)
  - [Calculator](#calculator)
  - [Logger](#logger)
  - [Notifier](#notifier)
- [Continuous Integration](#continuous-integration)
- [Contributing](#contributing)
- [License](#license)

## Overview

This repository provides a template for C++ projects, with a pre-configured setup for:
- **Build Management**: Uses CMake for build configuration.
- **Unit Testing**: Uses Google Test framework.
- **Continuous Integration**: Configured with CircleCI.
- **Static Analysis**: Uses ClangTidy for code analysis.
- **Code Formatting**: Uses ClangFormat for code style adherence.
- **Code Coverage**: Uses gcov for code coverage reporting.

### Project Structure

```plaintext
├── .circleci/
│   └── config.yml                 # CircleCI configuration for CI/CD
├── .github/ISSUE_TEMPLATE/
│   ├── bug_report.md              # GitHub issue template: bug reports
│   └── feature_request.md         # GitHub issue template: feature requests
├── build/                         # Build output directory (created by CMake)
├── scripts/
│   └── hooks/
│       └── pre-commit             # Git pre-commit hook (formatting & testing)
├── src/
│   ├── calculator/
│   │   ├── calculator.cpp         # Calculator logic
│   │   ├── calculator.h           # Calculator header
│   │   └── test_calculator.cpp    # Unit tests for Calculator
│   ├── logger/
│   │   ├── logger.cpp             # Logger implementation
│   │   ├── logger.h               # Logger header
│   │   └── test_logger.cpp        # Unit tests for Logger
│   └── notifier/
│       ├── notifier.cpp           # Notifier implementation
│       ├── notifier.h             # Notifier header
│       └── test_notifier.cpp      # Unit tests for Notifier
├── tests/
│   └── test_e2e.cpp               # End-to-end integration tests
├── vcpkg/                         # vcpkg dependency manager (cloned)
├── CMakeLists.txt                 # CMake configuration file
├── Makefile                       # Optional makefile for simple builds
├── component.md                   # Additional component documentation
├── pull_request_template.md       # PR template for contributors
└── README.md                      # This file
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

# Clone and bootstrap vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
cd ..

# Install GoogleTest
./vcpkg/vcpkg install gtest
```

## Usage

### Building the Project
Use CMake with the vcpkg toolchain to configure and build the project:

```bash
cmake -Bbuild -S. -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
```
### Running Tests
Run unit tests via ctest or directly through test binaries:

```bash
cd build
ctest --output-on-failure
```
Or run specific tests manually:

```bash
./test_calculator
./test_logger
./test_notifier
```

### Static Analysis
Run static analysis using ClangTidy:

```bash
find src -name '*.cpp' | xargs clang-tidy -- -I./src
```

### Code Coverage
Generate code coverage reports using gcov (after building and running tests with coverage flags):

```bash
gcov src/**/*.cpp
```

Or use gcovr for a clean HTML summary:

```bash
gcovr -r . --html-details -o coverage.html
```

## Pre-commit Hook
This project includes a Git pre-commit hook that formats staged C++ files using clang-format and runs unit tests before committing.

To enable the hook:

```bash
cp scripts/hooks/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
```

## Components

### Calculator
Performs basic arithmetic operations like addition, subtraction, and multiplication.

### Logger
Records operations performed by the calculator.

### Notifier
Sends an alert when the result exceeds a given threshold.

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

## ircleCI Links

Failed Test: https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/32/workflows/b957f89b-208f-4729-9ece-e86ee0d02898/jobs/53 

Passed Test: https://app.circleci.com/pipelines/github/sma9000/OSPSD-HW1/33/workflows/ded46d0c-9381-468b-9828-83327ac59a48/jobs/56

## License
This project is licensed under the MIT License.
