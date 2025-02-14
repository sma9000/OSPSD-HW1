cmake_minimum_required(VERSION 3.10)
project(DemoTests)

set(CMAKE_CXX_STANDARD 17)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Ensure test files can find header files
include_directories(${CMAKE_SOURCE_DIR}/include)

enable_testing()

# Add separate executables for each test file
add_executable(test_calculator tests/test_calculator.cpp src/calculator.cpp)
add_executable(test_logger tests/test_logger.cpp src/logger.cpp)
add_executable(test_notifier tests/test_notifier.cpp src/notifier.cpp)

# Link Google Test and source files
target_link_libraries(test_calculator GTest::gtest_main)
target_link_libraries(test_logger GTest::gtest_main)
target_link_libraries(test_notifier GTest::gtest_main)

# Register tests
add_test(NAME CalculatorTests COMMAND test_calculator)
add_test(NAME LoggerTests COMMAND test_logger)
add_test(NAME NotifierTests COMMAND test_notifier)