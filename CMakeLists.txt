cmake_minimum_required(VERSION 3.10)
project(DemoTests)

set(CMAKE_CXX_STANDARD 17)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Ensure test files can find the header files
include_directories(${CMAKE_SOURCE_DIR}/include)

enable_testing()

# Add test executable (include all test files)
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

