#include "calculator.h"
#include <gtest/gtest.h>

// Test fixture for Calculator, sets up a Calculator instance for each test
class CalculatorTests : public ::testing::Test {
protected:
    Calculator calc;  // Calculator instance used for all tests
};

// Test case for addition
TEST_F(CalculatorTests, HandlesAddition) {
    EXPECT_DOUBLE_EQ(5.0, calc.add(2, 3));
    EXPECT_DOUBLE_EQ(-1.0, calc.add(-3, 2));
    EXPECT_DOUBLE_EQ(0.0, calc.add(-2, 2));
}

// Test case for subtraction
TEST_F(CalculatorTests, HandlesSubtraction) {
    EXPECT_DOUBLE_EQ(-1.0, calc.subtract(2, 3));
    EXPECT_DOUBLE_EQ(-5.0, calc.subtract(-3, 2));
    EXPECT_DOUBLE_EQ(-4.0, calc.subtract(-2, 2));
}

// Test case for multiplication
TEST_F(CalculatorTests, HandlesMultiplication) {
    EXPECT_DOUBLE_EQ(6.0, calc.multiply(2, 3));
    EXPECT_DOUBLE_EQ(-6.0, calc.multiply(-3, 2));
    EXPECT_DOUBLE_EQ(4.0, calc.multiply(-2, -2));
}

// Test case for division
TEST_F(CalculatorTests, HandlesDivision) {
    EXPECT_DOUBLE_EQ(0.6666666666666666, calc.divide(2, 3));
    EXPECT_THROW(calc.divide(2, 0), const char*);
    EXPECT_DOUBLE_EQ(-1.5, calc.divide(-3, 2));
}

// Main function running all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
