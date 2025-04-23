# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project information
project(ConversationClientProject VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Homebrew's prefix to CMAKE_PREFIX_PATH
# CMake can locate packages from /opt/homebrew easily.
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")

# Find the Homebrew-installed libraries:
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Create the ConversationClient library from your source files.
add_library(ConversationClient STATIC
    src/ConversationClient.cpp
    src/ConversationHistory.cpp
    src/NLPProcessor.cpp
    src/ResponseFormatter.cpp
)

# Setup include directories for your library.
target_include_directories(ConversationClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(ConversationClient PUBLIC "/opt/homebrew/Cellar/nlohmann-json/3.12.0/include")

# Link Homebrew-installed dependencies to your library.
target_link_libraries(ConversationClient PRIVATE cpr::cpr nlohmann_json::nlohmann_json) # does not work sometimes?
target_link_libraries(ConversationClient PRIVATE nlohmann_json::nlohmann_json)

# Add the main executable.
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE ConversationClient)

# Add the test executable (include your test sources as needed).
add_executable(tests
    tests/test_config.cpp
    tests/test_conversation_client.cpp
    tests/test_conversation_history.cpp
    tests/test_error.cpp
    tests/test_message.cpp
    tests/test_nlp_processor.cpp
    tests/test_response_formatter.cpp
    tests/test_conversation.cpp
    tests/test_ai_conversation_client_integration.cpp
)
target_link_libraries(tests PRIVATE ConversationClient cpr::cpr nlohmann_json::nlohmann_json)

# Fetch and link GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.12.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
target_link_libraries(tests PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND tests)
