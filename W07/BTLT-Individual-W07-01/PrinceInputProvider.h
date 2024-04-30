#pragma once

#include <iostream>
#include "IntegerInputProvider.h"
#include "Prince.h"

using namespace std;

class PrinceInputProvider {
public:
    static Prince next() {
        system("clear");
        cout << "Enter stats for prince" << endl << endl;
        cout << "Money: ";
        int money = IntegerInputProvider::next();
        cout << "IQ: ";
        int iq = IntegerInputProvider::next();
        cout << "Strength: ";
        int strength = IntegerInputProvider::next();
        Prince result(money, iq, strength);
        return result;
    }
};