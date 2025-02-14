cmake_minimum_required(VERSION 3.10)
project(OSPSD_HW1_Tests)  # You can change this name

set(CMAKE_CXX_STANDARD 17)

# Find Google Test (Ensure it's installed)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()

# Add test executable with all test files
add_executable(runTests 
  tests/test_calculator.cpp
  tests/test_logger.cpp
  tests/test_notifier.cpp
)

# Link Google Test
target_link_libraries(runTests GTest::gtest_main)


add_test(NAME CalculatorTests COMMAND runTests)
add_test(NAME LoggerTests COMMAND runTests)
add_test(NAME NotifierTests COMMAND runTests)

