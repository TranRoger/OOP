#include <iostream>
using namespace std;

#include "FractionToPercentageConverter.h"
#include <string>
#include <sstream>
#include <iomanip>

FractionToPercetageConverter::FractionToPercetageConverter(NumberFormat format) {
    _config = format;
}

string FractionToPercetageConverter::convert(const Fraction &fraction) {
    double number = (double)fraction.numerator() / (double)fraction.denominator();
    number *= 100.0;
    stringstream builder;
    builder << setprecision(_config.getPrecision()) << fixed << number << "%";
    string result = builder.str();
    return result;
}