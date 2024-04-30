#pragma once 

#include <iostream>
using namespace std;
#include <string>

class Fraction {
private:
    int _num;
    int _den;

public:
    // Constructor
    Fraction();
    Fraction(int, int);

    // Accessor
    int numerator() const;
    int denominator() const;
    void setNumerator(int);
    void setDenominator(int);

    // Operation
    string toString();
    void lowestTerm();
};