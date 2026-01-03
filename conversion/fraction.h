#ifndef __FRACTION__
#define __FRACTION__

#include <stdio.h>
#include <iostream>
#include <string>

class Fraction {
public:
    Fraction(int num, int denominator=1) : m_numerator(num), m_denominator(denominator) {}

    operator double() const {
        return (double)(1.0 * m_numerator / m_denominator);
    }

    operator std::string() const {
        return std::to_string(m_numerator) + "/" + std::to_string(m_denominator);
    }

private:
    int m_numerator;
    int m_denominator;
};

#endif