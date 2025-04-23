// Error.h
#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

// Base class for all errors in conversation client
class Error : public std::runtime_error {
public:
    Error(const std::string& msg)
        : std::runtime_error("Error: " + msg) {}
};

// Errors related to network or API connectivity
class NetworkError : public Error {
public:
    NetworkError(const std::string& msg)
        : Error("Network Error: " + msg) {}
};

// Errors specifically for handling input/output operations
class IOError : public Error {
public:
    IOError(const std::string& msg)
        : Error("IO Error: " + msg) {}
};

// Errors with parsing or interpreting data
class ParseError : public Error {
public:
    ParseError(const std::string& msg)
        : Error("Parse Error: " + msg) {}
};

// Errors from invalid or unexpected user input
class InputError : public Error {
public:
    InputError(const std::string& msg)
        : Error("Input Error: " + msg) {}
};
// Error for operations where response time limit is exceeded
class TimeoutError : public Error {
public:
    TimeoutError(const std::string& msg)
        : Error("Timeout Error: " + msg) {}
};

// Errors that involve any services that are relied on
class ServiceError : public Error {
public:
    ServiceError(const std::string& msg)
        : Error("Service Error: " + msg) {}
};


#endif // ERROR_H
