#pragma once

#include <iostream>
using namespace std;

class Prince {
private:
    int _money;
    int _iq;
    int _strength;

public:
    // parameterized constructor
    Prince(int money, int iq, int strength) : _money(money), _iq(iq), _strength(strength) { }
    // getter
    int getMoney() {
        return _money;
    }
    int getIQ() {
        return _iq;
    }
    int getStrength() {
        return _strength;
    }
    // operation
    void decreaseStrength(const int &amount) {
        this->_strength -= amount;
    }
    void pay(const int &cost) {
        this->_money -= cost;
    }
    void stats() {
        cout << "Money: " << _money << endl;
        cout << "IQ: " << _iq << endl;
        cout << "Strength: " << _strength << endl;
    }
};