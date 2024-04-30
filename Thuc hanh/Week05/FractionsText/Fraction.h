#pragma once

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

class Fraction {
private:
    int _num;
    int _den;
public:
    Fraction(const int &num, const int &den) : _num(num), _den(den) {}

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

    void lowestTerm() {
        int common = gcd(_num, _den);
        _num /= common;
        _den /= common;
    }
};