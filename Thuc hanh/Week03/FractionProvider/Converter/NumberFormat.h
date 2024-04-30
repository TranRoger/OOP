#pragma once

#include <iostream>
using namespace std;

#include <string>

class NumberFormat {
private:
    string _thousandSeperator;
    string _decimalSeperator;
    int _precision;
public:
    NumberFormat();
    NumberFormat(string, string, int);

    // Accessor
    string getThousandSeperator() const;
    string getDecimalSeperator() const;
    int getPrecision() const;
};