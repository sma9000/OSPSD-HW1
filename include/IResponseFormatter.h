// IResponseFormatter.h
#ifndef IRESPONSEFORMATTER_H
#define IRESPONSEFORMATTER_H

#include <string>

class IResponseFormatter {
public:
    virtual std::string formatResponse(const std::string &rawResponse,
                                       const std::string &tag = "general",
                                       const std::string &suffix = "") = 0;

    virtual std::string addTimestamp(const std::string &response) = 0;
    virtual std::string toUpperCase(const std::string &response) = 0;
    virtual std::string addNewLineIfNeeded(const std::string &response) = 0;

    virtual ~IResponseFormatter() {}
};

#endif // IRESPONSEFORMATTER_H