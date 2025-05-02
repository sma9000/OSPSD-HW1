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


# Link Google Test to the test executables
target_link_libraries(test_config GTest::gtest_main)
target_link_libraries(test_conversation_client GTest::gtest_main)
target_link_libraries(test_conversation_history GTest::gtest_main)
target_link_libraries(test_error GTest::gtest_main)
target_link_libraries(test_message GTest::gtest_main)
target_link_libraries(test_response_formatter GTest::gtest_main)

# Register the tests

