cmake_minimum_required(VERSION 3.10)
project(AIConversationClient)

set(CMAKE_CXX_STANDARD 17)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Include directories for headers specified in the README structure
include_directories(src)

enable_testing()

# Add executables for all test files
add_executable(test_config tests/test_config.cpp src/Config.cpp)
add_executable(test_conversation_client tests/test_converstation_client.cpp src/ConversationClient.cpp src/Config.cpp)
add_executable(test_conversation_history tests/test_converstation_history.cpp src/ConversationHistory.cpp src/Config.cpp)
add_executable(test_error tests/test_error.cpp src/Error.cpp src/Config.cpp)
add_executable(test_message tests/test_message.cpp src/Message.cpp src/Config.cpp)
add_executable(test_nlp_processor tests/test_nlp_processor.cpp src/NLPProcessor.cpp src/Config.cpp)
add_executable(test_response_formatter tests/test_response_formatter.cpp src/ResponseFormatter.cpp src/Config.cpp)

# Link Google Test and source files for all tests
target_link_libraries(test_config GTest::gtest_main)
target_link_libraries(test_conversation_client GTest::gtest_main)
target_link_libraries(test_conversation_history GTest::gtest_main)
target_link_libraries(test_error GTest::gtest_main)
target_link_libraries(test_message GTest::gtest_main)
target_link_libraries(test_nlp_processor GTest::gtest_main)
target_link_libraries(test_response_formatter GTest::gtest_main)

# Register tests
add_test(NAME ConfigTests COMMAND test_config)
add_test(NAME ConversationClientTests COMMAND test_conversation_client)
add_test(NAME ConversationHistoryTests COMMAND test_conversation_history)
add_test(NAME ErrorTests COMMAND test_error)
add_test(NAME MessageTests COMMAND test_message)
add_test(NAME NLPProcessorTests COMMAND test_nlp_processor)
add_test(NAME ResponseFormatterTests COMMAND test_response_formatter)
