#ifndef IRESPONSEFORMATTER_H
#define IRESPONSEFORMATTER_H

#include <string>

/**
 * @brief Interface for formatting AI conversation responses.
 *
 * This interface defines methods for formatting responses,
 * such as adding tags, timestamps, and ensuring consistent output.
 */
class IResponseFormatter {
public:
    /**
     * @brief Formats a raw response string with a tag and optional suffix.
     * @param raw The raw response text.
     * @param tag A prefix or label to categorize the response.
     * @param suffix Optional suffix to be appended.
     * @return A formatted string combining tag, content, and suffix.
     */
    virtual std::string formatResponse(const std::string& raw,
                                       const std::string& tag,
                                       const std::string& suffix) = 0;

    /**
     * @brief Appends a timestamp to the response string.
     * @param response The original response.
     * @return The response with a timestamp added.
     */
    virtual std::string addTimestamp(const std::string& response) = 0;

    /**
     * @brief Converts the response string to uppercase.
     * @param response The original response.
     * @return The response in uppercase.
     */
    virtual std::string toUpperCase(const std::string& response) = 0;

    /**
     * @brief Ensures the response ends with a newline character.
     * @param response The original response.
     * @return The response with a newline appended if needed.
     */
    virtual std::string addNewLineIfNeeded(const std::string& response) = 0;

    virtual ~IResponseFormatter() = default;
};

#endif // IRESPONSEFORMATTER_H
