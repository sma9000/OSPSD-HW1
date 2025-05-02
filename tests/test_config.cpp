#include "Config.h"
#include <gtest/gtest.h>
#include <type_traits>

TEST(ConfigTest, SetAndGetReturnsExpectedValue) {
  Config *config = Config::getInstance();
  config->clear();

  config->set("language", "en");

  std::string result = config->get("language");

  EXPECT_EQ(result, "en");
  EXPECT_TRUE((std::is_same<decltype(result), std::string>::value));
}

TEST(ConfigTest, ReturnsEmptyStringIfKeyIsMissing) {
  Config *config = Config::getInstance();
  config->clear();

  EXPECT_EQ(config->get("this_key_does_not_exist"), "");
}