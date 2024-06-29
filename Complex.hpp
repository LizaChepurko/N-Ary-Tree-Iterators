/*
 * ID: 211548268
 * Mail: lizachep@gmail.com
 */
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

class Complex
{
    double re, im;

public:
    // Default constructor
    Complex() : re(0.0), im(0.0) {}

    Complex(double re, double im) : re(re), im(im) {}

    // Returnning string with precision of one number after the dot
    std::string to_string()
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << re << "+" << std::fixed << std::setprecision(1) << im << "i";
        return oss.str();
    }

    double magnitude() const
    {
        return sqrt(re * re + im * im);
    }

    bool operator<=(const Complex &other) const
    {
        return magnitude() <= other.magnitude();
    }

    bool operator<(const Complex &other) const
    {
        return magnitude() < other.magnitude();
    }

    bool operator>(const Complex &other) const
    {
        return magnitude() > other.magnitude();
    }

    bool operator>=(const Complex &other) const
    {
        return magnitude() >= other.magnitude();
    }

    bool operator==(const Complex &other) const
    {
        return re == other.re && im == other.im;
    }

    friend std::ostream &operator<<(std::ostream &out, const Complex &c)
    {
        if (c.im < 0)
        {
            out << c.re << " - " << -c.im << "i";
        }
        else
        {
            out << c.re << " + " << c.im << "i";
        }
        return out;
    }
};

#endif // COMPLEX_HPP
