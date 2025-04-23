cmake_minimum_required(VERSION 3.14)

project(ConversationClientProject VERSION 1.0 LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# GoogleTest via FetchContent
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# CPR via FetchContent (replaces find_package)
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 081771fd3ee038cf8e2f49293d92cf86a1e30a45
)
set(CPR_BUILD_TESTS OFF)
FetchContent_MakeAvailable(cpr)

# JSON (keep this if nlohmann_json is already working locally)
find_package(nlohmann_json REQUIRED)

# Gather source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Add test executable
add_executable(tests
    ${PROJECT_SOURCES}
    tests/test_config.cpp
    tests/test_conversation_client.cpp
    tests/test_conversation_history.cpp
    tests/test_error.cpp
    tests/test_message.cpp
    tests/test_nlp_processor.cpp
    tests/test_response_formatter.cpp
)

# Include paths
target_include_directories(tests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

# Link libraries
target_link_libraries(tests
    PRIVATE
    GTest::gtest
    GTest::gtest_main
    cpr::cpr
    nlohmann_json::nlohmann_json
)

# Discover tests
include(GoogleTest)
gtest_discover_tests(tests)

