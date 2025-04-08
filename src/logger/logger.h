#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    void log(const std::string &message);
    void log(const std::string &operation, int result);
};

#endif
