// IConfig.h
#ifndef ICONFIG_H
#define ICONFIG_H

#include <string>

/**
 * @brief Interface for accessing and modifying configuration settings.
 *
 * This interface defines methods for setting and retrieving key-value
 * configuration parameters. It is designed to be implemented as a singleton or
 * injected dependency.
 */
class IConfig {
public:
  /**
   * @brief Sets a configuration value.
   * @param key The name of the configuration setting.
   * @param value The value to associate with the key.
   */
  virtual void set(const std::string &key, const std::string &value) = 0;

  /**
   * @brief Retrieves a configuration value.
   * @param key The name of the configuration setting to retrieve.
   * @return The value associated with the given key.
   */
  virtual std::string get(const std::string &key) const = 0;

  /**
   * @brief Virtual destructor.
   */
  virtual ~IConfig() {}
};

#endif // ICONFIG_H