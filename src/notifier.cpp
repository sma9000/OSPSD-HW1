#include <iostream>
#include "notifier.h"
using namespace std;

Notifier::Notifier(double t) : threshold(t) {}

bool Notifier::sendAlert(double value) const {
    return value > threshold;
}

