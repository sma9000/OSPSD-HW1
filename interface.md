# Interface Definition

## Overview

This document formally defines the public interfaces for the AIConversation System. Each interface file under `include/` provides a pure abstract class with well-documented methods using Doxygen-style docstrings. No concrete implementations are provided at this stage.

These interfaces ensure loose coupling, test ability, and modular development. All implementations will be completed in implmentation.


## Overview

This document outlines the component architecture of the **AIConversation System**. Each component encapsulates specific functionality and interacts with others through well-defined interfaces. The design promotes modularity, reusability, and maintainability.
> All public methods in the interface headers are documented using Doxygen-style comments as required.


## Component Definition

A component in this project is an independent, reusable module that implements a defined interface and encapsulates its state and behavior. Components can be classes, services, or functional units.

### Directory Structure
```bash
include/
│   ├── IConfig.h                 # Interface for configuration
│   ├── IConversationClient.h    # Interface for AI conversation management
│   ├── IConversationHistory.h   # Interface for message history
│   ├── IMessage.h               # Interface representing a message
│   ├── IResponseFormatter.h     # Interface for formatting output

tests/
│   ├── test_config.cpp
│   ├── test_conversation.cpp
│   ├── test_conversation_client.cpp
│   ├── test_conversation_history.cpp
│   ├── test_error.cpp
│   ├── test_message.cpp
│   ├── test_nlp_processor.cpp
│   └── test_response_formatter.cpp
component.md
interface.md
README.md
```


## Key Principles

- **Encapsulation**: Each component manages its own state and behavior.
- **Reusability**: Components are designed to be reused across the system.
- **Interoperability**: Interfaces define contracts for interaction, minimizing tight coupling.

## Component List and Descriptions

### 1. `IConfig`

- **Purpose**: Provides configuration management across the system.
- **Interactions**:
  - Used by most components for accessing settings or parameters.

- **Files**: `IConfig.h`, `test_config.cpp`

### 2. `IConversationClient`

- **Purpose**: Acts as the main interface to handle conversations between users and the chatbot.
- **Interactions**:
  - Uses `IMessage`, `INLPProcessor`, `IResponseFormatter`.
  - Stores and retrieves data from `IConversationHistory`.
- **Files**: `IConversationClient.h`, `test_conversation_client.cpp`

### 3. `IConversationHistory`

- **Purpose**: Maintains history of the conversation sessions.
- **Interactions**:
  - Accessed by `IConversationClient` to retrieve previous context.
- **Files**: `IConversationHistory.h`, `test_conversation_history.cpp`

### 4. `IMessage`

- **Purpose**: Defines the structure and handling of messages in the chatbot.
- **Interactions**:
  - Used by `IConversationClient` to process inputs and responses.
- **Files**: `IMessage.h`, `test_message.cpp`


### 5. `IResponseFormatter`

- **Purpose**: Formats bot responses into a user-friendly format.
- **Interactions**:
  - Receives response payload from `INLPProcessor` or `IConversationClient`, returns formatted output.
- **Files**: `IResponseFormatter.h`, `test_response_formatter.cpp`

### 6. `Error`

- **Purpose**: Handles error codes and exception definitions for the application.
- **Interactions**:
  - Used by all components for robust error reporting.
- **Files**: `Error.h`, `test_error.cpp`

## Testing

Test files are located in the `tests/` directory. Each component has a corresponding test file:

- `test_config.cpp`
- `test_conversation_client.cpp`
- `test_conversation_history.cpp`
- `test_conversation.cpp`
- `test_message.cpp`
- `test_nlp_processor.cpp`
- `test_response_formatter.cpp`
- `test_error.cpp`

These tests ensure correctness and reliability of each individual module.

## Guidelines for Adding New Components

1. **Define the Component**: Clarify purpose, inputs, outputs, and dependencies.
2. **Create Interfaces**: Design clear, minimal interfaces for external access.
3. **Implement and Document**: Place code in `include/` and source in `src/` with appropriate documentation.
4. **Test Thoroughly**: Add test files in `tests/` with comprehensive unit tests.

## Conclusion

This architecture supports a clean and maintainable AI chatbot system. The use of interfaces ensures flexibility and scalability, making it easy to extend functionality or switch implementations.
