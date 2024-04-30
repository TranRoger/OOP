#pragma once

#include <iostream>
using namespace std;

#include "NumberFormat.h"
#include "..\Fraction\Fraction.h"

class FractionToDecimalConverter {
private:
    NumberFormat _config;
public:
    FractionToDecimalConverter(NumberFormat);
    string convert(const Fraction &);
};