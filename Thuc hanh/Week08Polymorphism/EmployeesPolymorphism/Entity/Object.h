#pragma once

#include <iostream>

class Object { // interface
public:
    virtual std::string toString() = 0;
};