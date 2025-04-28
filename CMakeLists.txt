cmake_minimum_required(VERSION 3.14)
project(ConversationClientProject VERSION 1.0 LANGUAGES CXX)

# C++ settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

# Source directories
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/tests)

# Copy sample_emails.csv to build directory as emails.csv (important for tests)
configure_file(
    ${PROJECT_SOURCE_DIR}/sample_emails.csv
    ${CMAKE_BINARY_DIR}/emails.csv
    COPYONLY
)

# Main application executable
add_executable(integrate
    ${SOURCE_DIR}/integrate.cpp
    ${SOURCE_DIR}/ConversationClient.cpp
    ${SOURCE_DIR}/Config.cpp
    ${SOURCE_DIR}/NLPProcessor.cpp
    ${SOURCE_DIR}/ConversationHistory.cpp
    ${SOURCE_DIR}/ResponseFormatter.cpp
)

target_include_directories(integrate PRIVATE
    ${INCLUDE_DIR}
    ${SOURCE_DIR}
)

target_link_libraries(integrate PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
)

# Unit and Integration Tests executable
add_executable(runTests
    ${TEST_DIR}/test_config.cpp
    ${TEST_DIR}/test_conversation_client.cpp
    ${TEST_DIR}/test_conversation_history_integration.cpp
    ${TEST_DIR}/test_conversation_history.cpp
    ${TEST_DIR}/test_conversation.cpp
    ${TEST_DIR}/test_end_to_end.cpp
    ${TEST_DIR}/test_error_handling.cpp
    ${TEST_DIR}/test_error.cpp
    ${TEST_DIR}/test_message_flow_integration.cpp
    ${TEST_DIR}/test_message.cpp
    ${TEST_DIR}/test_nlp_processor.cpp
    ${TEST_DIR}/test_response_formatter.cpp
    ${SOURCE_DIR}/ConversationClient.cpp
    ${SOURCE_DIR}/Config.cpp
    ${SOURCE_DIR}/NLPProcessor.cpp
    ${SOURCE_DIR}/ConversationHistory.cpp
    ${SOURCE_DIR}/ResponseFormatter.cpp
)

target_include_directories(runTests PRIVATE
    ${INCLUDE_DIR}
    ${SOURCE_DIR}
)

target_link_libraries(runTests PRIVATE
    GTest::gtest
    GTest::gtest_main
    pthread
    cpr::cpr
    nlohmann_json::nlohmann_json
)

# Testing setup
enable_testing()
add_test(NAME runTests COMMAND runTests)

# Installation (optional)
install(TARGETS integrate DESTINATION bin)
install(DIRECTORY ${INCLUDE_DIR}/ DESTINATION include)
