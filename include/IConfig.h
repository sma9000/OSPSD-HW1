// IConfig.h
#ifndef ICONFIG_H
#define ICONFIG_H

#include <string>

class IConfig {
public:
    virtual void set(const std::string& key, const std::string& value) = 0;
    virtual std::string get(const std::string& key) const = 0;

    virtual ~IConfig() {}
};

#endif // ICONFIG_H
