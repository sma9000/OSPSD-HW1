#include "Config.h"

Config* Config::instance = nullptr;

Config* Config::getInstance() {
    if (instance == nullptr) {
        instance = new Config();
    }
    return instance;
}

void Config::set(const std::string& key, const std::string& value) {
    settings[key] = value;
}

std::string Config::get(const std::string& key) const {
    auto it = settings.find(key);
    return (it != settings.end()) ? it->second : "";
}

// 🧽 Clear stored settings (for test isolation)
void Config::clear() {
    settings.clear();
}
