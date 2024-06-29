/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */

#include <gtest/gtest.h>
#include "Complex.hpp"
#include <iostream>

// Test default constructor
TEST(ComplexTest, DefaultConstructor) {
    Complex c;
    EXPECT_EQ(c.to_string(), "0.0+0.0i");
}

// Test parameterized constructor
TEST(ComplexTest, ParameterizedConstructor) {
    Complex c(3.1, 4.2);
    EXPECT_EQ(c.to_string(), "3.1+4.2i");
}

// Test magnitude calculation
TEST(ComplexTest, Magnitude) {
    Complex c(3.0, 4.0);
    EXPECT_DOUBLE_EQ(c.magnitude(), 5.0);
}

// Test comparison operators
TEST(ComplexTest, ComparisonOperators) {
    Complex c1(3.0, 4.0);
    Complex c2(6.0, 8.0);
    Complex c3(3.0, 4.0);

    EXPECT_TRUE(c1 < c2);
    EXPECT_TRUE(c1 <= c2);
    EXPECT_TRUE(c2 > c1);
    EXPECT_TRUE(c2 >= c1);
    EXPECT_TRUE(c1 == c3);
    EXPECT_FALSE(c1 == c2);
}

// Test less than or equal to
TEST(ComplexTest, LessThanOrEqual) {
    Complex c1(3.0, 4.0);
    Complex c2(3.0, 4.0);
    Complex c3(5.0, 0.0);

    EXPECT_TRUE(c1 <= c2);
    EXPECT_TRUE(c1 <= c3);
}

// Test greater than or equal to
TEST(ComplexTest, GreaterThanOrEqual) {
    Complex c1(3.0, 4.0);
    Complex c2(3.0, 4.0);
    Complex c3(5.0, 0.0);

    EXPECT_TRUE(c1 >= c2);
    EXPECT_TRUE(c3 >= c1);
}

// Test output stream operator
TEST(ComplexTest, OutputStreamOperator) {
    Complex c1(3.0, -4.0);
    Complex c2(3.0, 4.0);

    std::ostringstream oss1;
    oss1 << c1;
    EXPECT_EQ(oss1.str(), "3 - 4i");

    std::ostringstream oss2;
    oss2 << c2;
    EXPECT_EQ(oss2.str(), "3 + 4i");
}

