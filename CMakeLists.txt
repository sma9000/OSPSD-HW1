cmake_minimum_required(VERSION 3.10)
project(AIConversationClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POLICY_DEFAULT_CMP0074 NEW)  # Make find_package work better with vcpkg

# Enable testing support
enable_testing()

# Automatically locate dependencies installed by vcpkg
find_package(GTest CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Add include directories for your own headers
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src)

# Optional: if gtest headers still give issues, uncomment the next lines:
# get_target_property(GTEST_INCLUDE_DIR GTest::gtest INTERFACE_INCLUDE_DIRECTORIES)
# include_directories(${GTEST_INCLUDE_DIR})

# Your implementation source files (excluding NLPProcessor.cpp as requested)
set(SOURCE_FILES
    src/Config.cpp
    src/ConversationClient.cpp
    src/ConversationHistory.cpp
)

# Define all test targets
set(TEST_TARGETS
    test_config
    test_conversation_client
    test_conversation_history
    test_error
    test_message
)

foreach(target IN LISTS TEST_TARGETS)
    add_executable(${target} tests/${target}.cpp ${SOURCE_FILES})
    target_link_libraries(${target}
        GTest::gtest
        GTest::gtest_main
        cpr::cpr
        nlohmann_json::nlohmann_json
    )
    add_test(NAME ${target} COMMAND ${target})
endforeach()
