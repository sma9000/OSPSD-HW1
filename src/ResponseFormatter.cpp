// ResponseFormatter.cpp
#include "ResponseFormatter.h"
#include <string>

// Define the static member variable.
std::map<std::string, std::string> ResponseFormatter::tags;

// Initializes predefined tags.
void ResponseFormatter::initializeTags() {
    tags["info"] = "[INFO] ";
    tags["warning"] = "[WARNING] ";
    tags["error"] = "[ERROR] ";
    tags["general"] = ""; // Default tag with no prefix.
}

// Formats response with optional tag and suffix.
std::string ResponseFormatter::formatResponse(const std::string &rawResponse,
                                                const std::string &tag,
                                                const std::string &suffix) {
    // If the tag exists in the map and its value is nonempty, use that prefix
    if (tags.find(tag) != tags.end() && !tags[tag].empty()) {
        return tags[tag] + rawResponse + suffix;
    } else {
        // Otherwise, append the tag as text after the raw response
        return rawResponse + " " + tag + suffix;
    }
}


