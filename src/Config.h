#ifndef CONFIG_H
#define CONFIG_H

#include "IConfig.h"
#include <unordered_map>
#include <string>

class Config : public IConfig {
private:
    static Config* instance;
    std::unordered_map<std::string, std::string> settings;

    Config() = default;

public:
    static Config* getInstance();

    void set(const std::string& key, const std::string& value) override;
    std::string get(const std::string& key) const override;

    
    void clear(); //for testing

    // Prevent copying
    Config(const Config&) = delete;
    void operator=(const Config&) = delete;
};

#endif // CONFIG_H
