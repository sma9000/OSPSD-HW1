#include "NLPProcessor.h"

#include <algorithm>
#include <cctype>
#include <sstream>

// Helper: Trim leading/trailing whitespace
static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    return (start == std::string::npos || end == std::string::npos)
        ? ""
        : str.substr(start, end - start + 1);
}

// Helper: Lowercase a string
static std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

std::string NLPProcessor::preprocessInput(const std::string& input) {
    std::string cleaned = trim(input);
    cleaned = toLower(cleaned);
    return cleaned;
}

std::string NLPProcessor::postprocessOutput(const std::string& output) {
    std::string cleaned = trim(output);

    return cleaned;
}
