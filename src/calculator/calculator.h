// calculator.h

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    // Constructor
    Calculator();

    // Method to add two numbers
    double add(double a, double b);

    // Method to subtract the second number from the first
    double subtract(double a, double b);

    // Method to multiply two numbers
    double multiply(double a, double b);

    // Method to divide the first number by the second
    double divide(double a, double b);

    // Destructor
    ~Calculator();
};

#endif // CALCULATOR_H
