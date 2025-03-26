//
// Created by Salma Awan on 2/12/25.
//

#ifndef OPENSOURCEHW1_NOTIFIER_H
#define OPENSOURCEHW1_NOTIFIER_H

class Notifier {
private:
    double threshold;  // Threshold value for notifications
public:
    explicit Notifier(double t);  // Constructor
    bool sendAlert(double value) const;  // Check if alert should be sent
};

#endif //OPENSOURCEHW1_NOTIFIER_H
