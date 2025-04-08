#include "logger.h"
#include <iostream>

void Logger::log(const std::string &operation, int result) {
    std::cout << "Operation: " << operation << ", Result: " << result << std::endl;
}

void Logger::log(const std::string &message) {
    std::cout << message << std::endl;
}