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
├── .circleci
│   └── config.yml                # CircleCI configuration file for CI/CD setup
├── .github/ISSUE_TEMPLATE
│   ├── bug_report.md             # Template for reporting bugs
│   └── feature_request.md        # Template for requesting new features
├── extern
│   └── googletest @ c00fd25      # External dependency: GoogleTest framework
├── src                           # Folder for source files (.cpp) and headers (.h)
│   ├── calculator                # Folder for Calculator component
│   │   ├── calculator.cpp        # Source file for Calculator component
│   │   ├── calculator.h          # Source file for Calculator component
│   │   └── test_calculator.cpp   # Unit tests for Calculator component
│   ├── logger                    # Folder for Logger component
│   │   ├── logger.cpp            # Source file for Logger component
│   │   ├── logger.h              # Source file for Logger component
│   │   └── test_logger.cpp       # Unit tests for Logger component
│   └── notifier                  # Folder for Notifier component
│       ├── notifier.cpp          # Source file for Notifier component
│       ├── notifier.h            # Source file for Notifier component
│       └── test_notifier.cpp     # Unit tests for Notifier component
├── tests                         # Folder for test files
│   └── test_e2e.cpp              # End to end tests
├── .DS_Store                     # macOS specific file to store custom folder attributes
├── .gitmodules                   # Configuration file for git submodules
├── CMakeLists.txt                # CMake configuration file for building the project
├── Makefile                      # Makefile for building the project using `make`
├── README.md                     # Documentation file for the repository
├── component.md                  # Documentation file for components
└── pull_request_template.md      # Template for pull requests
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

## License
This project is licensed under the MIT License.
