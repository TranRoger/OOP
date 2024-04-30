#include <iostream>
using namespace std;

#include "FractionToDecimalConverter.h"
#include <sstream>
#include <string>
#include <iomanip>

FractionToDecimalConverter::FractionToDecimalConverter(NumberFormat format) {
    _config = format;
}

string FractionToDecimalConverter::convert(const Fraction &fraction) {
    double number = (double)fraction.numerator() / (double)fraction.denominator();
    stringstream builder;
    builder << setprecision(_config.getPrecision()) << fixed << number;
    string result = builder.str();
    return result;
}