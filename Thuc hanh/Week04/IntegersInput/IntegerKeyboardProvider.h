#pragma once

#include <iostream>
using namespace std;

#include "..\Utilities\Result.h"

class IntegerKeyboardProvider {
public:
    static Result<int> next();
    static Result<int> next(const int&, const int&);
};