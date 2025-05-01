cmake_minimum_required(VERSION 3.10)
project(AIConversationClient)

set(CMAKE_CXX_STANDARD 17)

# Include the header files in the include folder
include_directories(include)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

# Add test executables directly from the tests folder
add_executable(test_config tests/test_config.cpp)
add_executable(test_conversation_client tests/test_conversation_client.cpp)
add_executable(test_conversation_history tests/test_conversation_history.cpp)
add_executable(test_error tests/test_error.cpp)
add_executable(test_message tests/test_message.cpp)
add_executable(test_nlp_processor tests/test_nlp_processor.cpp)
add_executable(test_response_formatter tests/test_response_formatter.cpp)

# Link Google Test to the test executables
target_link_libraries(test_config GTest::gtest_main)
target_link_libraries(test_conversation_client GTest::gtest_main)
target_link_libraries(test_conversation_history GTest::gtest_main)
target_link_libraries(test_error GTest::gtest_main)
target_link_libraries(test_message GTest::gtest_main)
target_link_libraries(test_nlp_processor GTest::gtest_main)
target_link_libraries(test_response_formatter GTest::gtest_main)

# Register the tests
add_test(NAME ConfigTests COMMAND test_config)
add_test(NAME ConversationClientTests COMMAND test_conversation_client)
add_test(NAME ConversationHistoryTests COMMAND test_conversation_history)
add_test(NAME ErrorTests COMMAND test_error)
add_test(NAME MessageTests COMMAND test_message)
add_test(NAME NLPProcessorTests COMMAND test_nlp_processor)
add_test(NAME ResponseFormatterTests COMMAND test_response_formatter)
