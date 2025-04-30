#include "ResponseFormatter.h"
#include <sstream>

std::map<std::string, std::string> ResponseFormatter::tags;

void ResponseFormatter::initializeTags() {
    tags["info"] = "[INFO] ";
    tags["warning"] = "[WARNING] ";
    tags["error"] = "[ERROR] ";
    tags["general"] = "";
}

std::string ResponseFormatter::formatResponse(const std::string &rawResponse,
                                              const std::string &tag,
                                              const std::string &suffix) {
    if (tags.find(tag) != tags.end() && !tags[tag].empty()) {
        return tags[tag] + rawResponse + suffix;
    } else {
        return rawResponse + " " + tag + suffix;
    }
}

std::string ResponseFormatter::addTimestamp(const std::string &response) {
    std::time_t result = std::time(nullptr);
    std::string timestamp = std::asctime(std::localtime(&result));
    timestamp.pop_back(); // remove newline
    return "[" + timestamp + "] " + response;
}

std::string ResponseFormatter::toUpperCase(const std::string &response) {
    std::string upperResponse = response;
    std::transform(upperResponse.begin(), upperResponse.end(), upperResponse.begin(), ::toupper);
    return upperResponse;
}

std::string ResponseFormatter::addNewLineIfNeeded(const std::string &response) {
    if (!response.empty() && response.back() != '\n') {
        return response + "\n";
    }
    return response;
}
