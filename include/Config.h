// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <unordered_map>

class Config {
private:
    static Config* instance;
    std::unordered_map<std::string, std::string> settings;

    
    Config() {}

public:

    static Config* getInstance() {
        if (instance == nullptr) {
            instance = new Config();
        }
        return instance;
    }

    // Set a configuration setting
    void set(const std::string& key, const std::string& value) {
        settings[key] = value;
    }

    // Get a configuration setting
    std::string get(const std::string& key) const {
        auto it = settings.find(key);
        if (it != settings.end()) {
            return it->second;
        }
        return "";  // Return empty if key not found
    }

    // Prevent copying singleton instance
    Config(Config const&) = delete;
    void operator=(Config const&) = delete;
};

Config* Config::instance = nullptr; 

#endif // CONFIG_H
