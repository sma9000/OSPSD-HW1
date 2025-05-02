// Error.h
#ifndef ERROR_H
#define ERROR_H

#include <stdexcept>
#include <string>

/**
 * @brief Base class for all errors in the conversation client.
 */
class Error : public std::runtime_error {
public:
    /**
     * @brief Constructs a general Error with a message.
     * @param msg Description of the error.
     */
    explicit Error(const std::string& msg)
            : std::runtime_error("Error: " + msg) {}
};

/**
 * @brief Represents errors related to network or API connectivity.
 */
class NetworkError : public Error {
public:
    /**
     * @brief Constructs a NetworkError with a message.
     * @param msg Description of the network error.
     */
    explicit NetworkError(const std::string& msg)
            : Error("Network Error: " + msg) {}
};

/**
 * @brief Represents errors related to input/output operations.
 */
class IOError : public Error {
public:
    /**
     * @brief Constructs an IOError with a message.
     * @param msg Description of the IO error.
     */
    explicit IOError(const std::string& msg)
            : Error("IO Error: " + msg) {}
};

/**
 * @brief Represents errors related to data parsing or interpretation.
 */
class ParseError : public Error {
public:
    /**
     * @brief Constructs a ParseError with a message.
     * @param msg Description of the parsing error.
     */
    explicit ParseError(const std::string& msg)
            : Error("Parse Error: " + msg) {}
};

/**
 * @brief Represents errors caused by invalid user input.
 */
class InputError : public Error {
public:
    /**
     * @brief Constructs an InputError with a message.
     * @param msg Description of the input error.
     */
    explicit InputError(const std::string& msg)
            : Error("Input Error: " + msg) {}
};

/**
 * @brief Represents errors due to operations exceeding time limits.
 */
class TimeoutError : public Error {
public:
    /**
     * @brief Constructs a TimeoutError with a message.
     * @param msg Description of the timeout error.
     */
    explicit TimeoutError(const std::string& msg)
            : Error("Timeout Error: " + msg) {}
};

/**
 * @brief Represents errors related to dependent services.
 */
class ServiceError : public Error {
public:
    /**
     * @brief Constructs a ServiceError with a message.
     * @param msg Description of the service error.
     */
    explicit ServiceError(const std::string& msg)
            : Error("Service Error: " + msg) {}
};

#endif // ERROR_H
