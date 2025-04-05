#include "Config.h"
#include <gtest/gtest.h>

TEST(ConfigTest, SingletonInstance) {
    Config* instance1 = Config::getInstance();
    Config* instance2 = Config::getInstance();

    ASSERT_EQ(instance1, instance2); // Ensures only one instance exists
}

TEST(ConfigTest, SetAndGetConfiguration) {
    Config* config = Config::getInstance();
    config->set("key", "value");

    EXPECT_EQ(config->get("key"), "value"); // Confirms value is retrieved correctly
}

TEST(ConfigTest, GetNonexistentKeyReturnsEmpty) {
    Config* config = Config::getInstance();

    EXPECT_EQ(config->get("nonexistent"), ""); // Empty string for unknown keys
}
