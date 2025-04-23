#ifndef RESPONSEFORMATTER_H
#define RESPONSEFORMATTER_H

#include <string>
#include <ctime>
#include <algorithm>
#include <map>

class ResponseFormatter {
private:
    static std::map<std::string, std::string> tags;

public:
    static void initializeTags();

    static std::string formatResponse(const std::string &rawResponse,
                                      const std::string &tag = "general",
                                      const std::string &suffix = "");

    static std::string addTimestamp(const std::string &response);

    static std::string toUpperCase(const std::string &response);

    static std::string addNewLineIfNeeded(const std::string &response);
};

#endif // RESPONSEFORMATTER_H
