// ResponseFormatter.h
#ifndef RESPONSEFORMATTER_H
#define RESPONSEFORMATTER_H

#include <string>
#include <ctime>
#include <algorithm>
#include <map>

class ResponseFormatter {
private:
    static std::map<std::string, std::string> tags;  // Stores predefined tags for different message types

public:
    // Initializes predefined tags
    static void initializeTags();

    // Formats response with optional tag(predefined) and suffix(message)
    static std::string formatResponse(const std::string &rawResponse, const std::string &tag = "general", const std::string &suffix = "") {
        std::string prefix = tags[tag]; // Retrieve the tag's prefix
        return prefix + rawResponse + suffix;
    }

    // Adds a timestamp to the response
    static std::string addTimestamp(const std::string &response) {
        std::time_t result = std::time(nullptr);
        std::string timestamp = std::asctime(std::localtime(&result));
        timestamp.pop_back();
        return "[" + timestamp + "] " + response;
    }

    // Converts response to uppercase
    static std::string toUpperCase(const std::string &response) {
        std::string upperResponse = response;
        std::transform(upperResponse.begin(), upperResponse.end(), upperResponse.begin(), ::toupper);
        return upperResponse;
    }
   
    // Appends a newline if the message doesn't already end with one
    static std::string addNewLineIfNeeded(const std::string &response) {
    if (!response.empty() && response.back() != '\n') {
        return response + "\n";
    }
    return response;
}
};

std::map<std::string, std::string> ResponseFormatter::tags;

// Define tags
void ResponseFormatter::initializeTags() {
    tags["info"] = "[INFO] ";
    tags["warning"] = "[WARNING] ";
    tags["error"] = "[ERROR] ";
    tags["general"] = ""; // Might not need tag name for now
}

#endif // RESPONSEFORMATTER_H
