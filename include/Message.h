#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <chrono>

struct Message {
    std::string sender;
    std::string content;
    std::chrono::system_clock::time_point timestamp;
};

#endif // MESSAGE_H
