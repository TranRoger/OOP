#pragma once 

#include <iostream>
using namespace std;

#include "..\Fraction\Fraction.h"
#include "NumberFormat.h"

class FractionToPercetageConverter {
private:
    NumberFormat _config;
public:
    FractionToPercetageConverter(NumberFormat);
    string convert(const Fraction &);
};