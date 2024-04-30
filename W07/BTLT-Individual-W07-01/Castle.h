#pragma once

#include <iostream>
#include <vector>
#include "Gate.h"

class Castle {
private: 
    vector<Gate*> _gates;
    int _numberOfGates;
public:
    Castle(vector<Gate*> gates, int numberOfGates) : _gates(gates), _numberOfGates(numberOfGates) {}
    vector<Gate*> gates() {
        return _gates;
    }
    int numberOfGates() {
        return _numberOfGates;
    }
};