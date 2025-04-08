#include "logger.h"
#include "notifier.h"
#include <gtest/gtest.h>

TEST(LoggerNotifierIntegrationTest, TestThresholdNotification) {
    // Arrange
    double threshold = 10.0;
    Notifier notifier(threshold);
    Logger logger;

    double value = 12.0;

    // Act
    logger.log("Sending value to Notifier");
    bool alertSent = notifier.sendAlert(value);

    // Assert
    ASSERT_TRUE(alertSent); // Should exceed threshold
    notifier.notify(value); // Manually check notification output
}
