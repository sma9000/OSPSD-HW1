// Calculator.cpp
#include "Calculator.h"

Calculator::Calculator() {
    // Constructor
}

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return a / b;
}

Calculator::~Calculator() {
    // Destructor
}
