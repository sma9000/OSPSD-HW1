#include <iostream>
#include "notifier.h"
using namespace std;

Notifier::Notifier(double t) : threshold(t) {}

bool Notifier::sendAlert(double value) const {
    return value > threshold;
}

void Notifier::notify(double value) const {
    if (sendAlert(value)) {
        std::cout << "Threshold exceeded\n";
    }
}
