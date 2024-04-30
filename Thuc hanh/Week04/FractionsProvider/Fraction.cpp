#include <iostream>
using namespace std;

#include <sstream>
#include <algorithm>
#include <numeric>
#include "Fraction.h"

// Constructor
Fraction::Fraction() {
    _num = 0;
    _den = 1;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        cout << "Denominator cannot be zero!" << endl;
        _num = 0;
        _den = 1;
    }
    else {
        _num = num;
        _den = den;
    }
    lowestTerm();
}

// Accessor
int Fraction::numerator() const {
    return _num;
}

int Fraction::denominator() const {
    return _den;
}

void Fraction::setNumerator(int value) {
    _num = value;
}

void Fraction::setDenominator(int value) {
    if (value == 0) {
        cout << "Denominator cannot be zero!" << endl;
        return;
    }

    _den = value;
}

// Operation
string Fraction::toString() {
    stringstream builder;
    if (_den == 1) {
        builder << _num;
    }
    else if ((double)_num / (double)_den > 1.0) {
        int d = _num / _den, r = _num % _den;
        builder << d << " " << r << "/" << _den;
    }
    else {  
        builder << _num << "/" << _den;
    }
    string result = builder.str();
    return result;
}

void Fraction::lowestTerm() {
    int common = gcd(_num, _den);
    _num /= common;
    _den /= common;
}