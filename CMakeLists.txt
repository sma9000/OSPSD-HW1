cmake_minimum_required(VERSION 3.14)
project(YourProjectName)

# Enable testing
enable_testing()

# Add Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1  # You can use a different release tag
)
FetchContent_MakeAvailable(googletest)

include_directories(${gtest_SOURCE_DIR}/include)

# Define test executable
add_executable(your_test_executable_name test/test_calculator.cpp)

# Link GoogleTest
target_link_libraries(your_test_executable_name GTest::gtest_main)

# Add test
add_test(NAME all_tests COMMAND your_test_executable_name)

