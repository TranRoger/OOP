#include <iostream>
using namespace std;

#include "NumberFormat.h"

NumberFormat::NumberFormat() {
    _thousandSeperator = " ";
    _decimalSeperator = ",";
    _precision = 2;
}

NumberFormat::NumberFormat(string thousand, string decimal, int precision) {
    _thousandSeperator = thousand;
    _decimalSeperator = decimal;
    _precision = precision;
}

// Accessor
string NumberFormat::getThousandSeperator() const {
    return _thousandSeperator;
}

string NumberFormat::getDecimalSeperator() const {
    return _decimalSeperator;
}

int NumberFormat::getPrecision() const {
    return _precision;
}