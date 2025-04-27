cmake_minimum_required(VERSION 3.14)
project(ConversationClientProject VERSION 1.0 LANGUAGES CXX)

# C++ Standard and Compiler Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find dependencies
find_package(cpr REQUIRED)
find_package(nlohmann_json REQUIRED)

# Project structure configuration
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# Main executable with ALL implementation files
add_executable(integrate
    ${SOURCE_DIR}/integrate.cpp
    ${SOURCE_DIR}/ConversationClient.cpp
    ${SOURCE_DIR}/Config.cpp
    ${SOURCE_DIR}/NLPProcessor.cpp
    ${SOURCE_DIR}/ConversationHistory.cpp
    ${SOURCE_DIR}/ResponseFormatter.cpp
    # Add any other .cpp files your project needs
)

target_include_directories(integrate PRIVATE
    ${INCLUDE_DIR}
    ${SOURCE_DIR}
)

target_link_libraries(integrate PRIVATE
    cpr::cpr
    nlohmann_json::nlohmann_json
)

# Installation rules (optional)
install(TARGETS integrate DESTINATION bin)
install(DIRECTORY ${INCLUDE_DIR}/ DESTINATION include)