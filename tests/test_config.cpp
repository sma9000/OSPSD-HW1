#include "IConfig.h"
#include <gtest/gtest.h>
#include <unordered_map>

// Mock implementation
class MockConfig : public IConfig {
    std::unordered_map<std::string, std::string> storage;
public:
    void set(const std::string& key, const std::string& value) override {
        storage[key] = value;
    }

    std::string get(const std::string& key) const override {
        auto it = storage.find(key);
        return it != storage.end() ? it->second : "";
    }
};

TEST(ConfigInterfaceTest, SetAndGetReturnsExpectedShape) {
    MockConfig config;
    config.set("language", "en");

    std::string result = config.get("language");

    EXPECT_EQ(result, "en");
    EXPECT_TRUE((std::is_same<decltype(result), std::string>::value));
}