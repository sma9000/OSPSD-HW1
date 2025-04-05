# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project information
project(ConversationClientProject VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify source files for the project
add_library(ConversationClient
    src/ConversationClient.h
    src/ConversationHistory.h
    src/Config.h
    src/Error.h
    src/Message.h
    src/NLPProcessor.h
    src/ResponseFormatter.h
    src/main.cpp
)

# Add executable for the main entry point
add_executable(main src/main.cpp)

# Link the ConversationClient library to the main executable
target_link_libraries(main ConversationClient)

# Add unit test executable
add_executable(tests
    tests/test_config.cpp
    tests/test_conversation_client.cpp
    tests/test_conversation_history.cpp
    tests/test_error.cpp
    tests/test_message.cpp
    tests/test_nlp_processor.cpp
    tests/test_response_formatter.cpp
    tests/test_conversation.cpp
)

# Link the ConversationClient library to the test executable
target_link_libraries(tests ConversationClient)

# Add Google Test if available
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.0.zip
)
FetchContent_MakeAvailable(googletest)

# Link Google Test to the tests executable
target_link_libraries(tests gtest gtest_main)
enable_testing()

# Add test targets
add_test(NAME AllTests COMMAND tests)

