#pragma once

#include <iostream>
#include "Prince.h"
using namespace std;

class Gate {
public:
    static int _numberOfGates;
public:
    virtual bool passTheGate(Prince &) = 0; // pure virtual function
};

class AcademicGate : public Gate {
private:
    int _iqScore;
public:
    // constructor
    AcademicGate() : _iqScore(0) {};
    AcademicGate(int iqScore) : _iqScore(iqScore) {}
    // operation
    bool passTheGate(Prince &prince) override {
        if (prince.getIQ() < _iqScore) {
            return false;
        } 
        else {
            return true;
        }
    }
};

class BusinessGate : public Gate {
private:
    int _qty;
    int _price;
public:
    // constructor
    BusinessGate() : _qty(0), _price(0) {}
    BusinessGate(int qty, int price) : _qty(qty), _price(price) {}
    // operation
    int total() {
        return _qty * _price;
    }
    bool passTheGate(Prince &prince) override {
        if (prince.getMoney() < total()) {
            return false;
        }
        else {
            prince.pay(total());
            return true;
        }
    }
};

class PowerGate : public Gate {
private:
    int _powerScore;
public:
    // constructor
    PowerGate() : _powerScore(0) {}
    PowerGate(int powerScore) : _powerScore(powerScore) {}
    // operation
    bool passTheGate(Prince &prince) override {
        if (prince.getStrength() < _powerScore) {
            return false;
        }
        else {
            prince.decreaseStrength(_powerScore);
            return true;
        }
    }
};