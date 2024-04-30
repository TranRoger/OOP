#pragma once

#include <iostream>
using namespace std;

class RandomInteger {
public:
    // constructor
    RandomInteger() {};
    // operation
    int next(); // [0, 65535]
	int next(int); // [0, max-1]
	int next(int left, int right); // [left, right]
};