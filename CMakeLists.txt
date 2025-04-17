cmake_minimum_required(VERSION 3.14)

project(ConversationClientProject VERSION 1.0 LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# vcpkg toolchain support (optional, picked up via CLI automatically)
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
#     CACHE STRING "Vcpkg toolchain file")

# Enable testing
enable_testing()

# GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.0.zip
)
# Prevent GoogleTest from overriding compiler/linker flags
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(tests
    tests/test_config.cpp
    tests/test_conversation_client.cpp
    tests/test_conversation_history.cpp
    tests/test_error.cpp
    tests/test_message.cpp
    tests/test_nlp_processor.cpp
    tests/test_response_formatter.cpp
)

# Include path to headers/interfaces
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link GoogleTest
target_link_libraries(tests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
)

# Discover each TEST() case individually for ctest
include(GoogleTest)
gtest_discover_tests(tests)
