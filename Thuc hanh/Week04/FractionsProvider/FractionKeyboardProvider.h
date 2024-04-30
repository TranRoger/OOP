#pragma once

#include <iostream>
using namespace std;

#include "..\Utilities\Result.h"
#include "Fraction.h"

class FractionKeyboardProvider {
public:
    Result<Fraction> next();
};