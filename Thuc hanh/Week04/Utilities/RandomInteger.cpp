#include <iostream>
using namespace std;

#include "RandomInteger.h"

// operation
int RandomInteger::next() {
    srand(time(nullptr));
    int result = rand();
    while (result < 0 || result > 65535) {
        result = rand();
    }
    return result;
}

int RandomInteger::next(int max) {
    srand(time(nullptr));
    int result = rand();
    while (result < 0 || result > max) {
        result = rand();
    }
    return result;
}

int RandomInteger::next(int left, int right) {
    srand(time(nullptr));
    int result = rand();
    while (result < left || result > right) {
        result = rand();
    }
    return result;
}