cmake_minimum_required(VERSION 3.14)
project(AIConversationClient VERSION 1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies via vcpkg
find_package(GTest CONFIG REQUIRED)
find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Directories
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(TEST_DIR ${PROJECT_SOURCE_DIR}/tests)

# Copy sample_emails.csv to build directory
configure_file(
    ${PROJECT_SOURCE_DIR}/sample_emails.csv
    ${CMAKE_BINARY_DIR}/emails.csv
    COPYONLY
)

# Main app: run_pipeline
add_executable(run_pipeline
    ${SOURCE_DIR}/integrate.cpp
    ${SOURCE_DIR}/Config.cpp
    ${SOURCE_DIR}/ConversationClient.cpp
    ${SOURCE_DIR}/ConversationHistory.cpp
)

target_include_directories(run_pipeline PRIVATE
    ${INCLUDE_DIR}
    ${SOURCE_DIR}
)

target_link_libraries(run_pipeline PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
)

# Define unit/integration tests
enable_testing()

set(TEST_TARGETS
    test_config
    test_conversation_client
    test_conversation_history
    test_error
    test_message
)

foreach(target IN LISTS TEST_TARGETS)
    add_executable(${target} ${TEST_DIR}/${target}.cpp ${SOURCE_DIR}/Config.cpp ${SOURCE_DIR}/ConversationClient.cpp ${SOURCE_DIR}/ConversationHistory.cpp)
    target_include_directories(${target} PRIVATE ${INCLUDE_DIR} ${SOURCE_DIR})
    target_link_libraries(${target}
        GTest::gtest
        GTest::gtest_main
        cpr::cpr
        nlohmann_json::nlohmann_json
        pthread
    )
    add_test(NAME ${target} COMMAND ${target})
endforeach()

# Install (optional)
install(TARGETS run_pipeline DESTINATION bin)
install(DIRECTORY ${INCLUDE_DIR}/ DESTINATION include)
