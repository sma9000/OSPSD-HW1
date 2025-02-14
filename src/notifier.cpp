#include <iostream>
#include "Notifier.h"
using namespace std;

Notifier::Notifier(double t) : threshold(t) {}

bool Notifier::sendAlert(double value) const {
    return value > threshold;
}

