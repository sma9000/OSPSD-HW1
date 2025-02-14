cmake_minimum_required(VERSION 3.14) 
project(YourProjectName)

# Enable testing functionalities
enable_testing()

# Add Google Test as a subdirectory so it will be built
add_subdirectory(extern/googletest)

# Include Google Test's functionalities
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Define your executable that includes the tests
add_executable(your_test_executable_name test/test_calculator.cpp)

# Link Google Test to your test executable
target_link_libraries(your_test_executable_name gtest gtest_main)

#Ensure CMakeLists.txt References Google Test Correctly
add_subdirectory(extern/googletest)
include_directories(extern/googletest/googletest/include)

# Add tests to the project
add_test(NAME all_tests COMMAND your_test_executable_name)

