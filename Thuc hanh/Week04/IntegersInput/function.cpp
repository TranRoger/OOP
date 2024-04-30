#include <iostream>
using namespace std;

#include "IntegersInput.h"
#include <math.h>

bool isPrime(const int& number) {
    if (number < 2) return false;
    if (number == 2) return true;
    for (int i = 2; i <= sqrt(number); i++) {
        if (0 == number % i) return false;
    }
    return true;
}