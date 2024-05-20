#pragma once

#include <iostream>
#include "Object.h"

using std::string;

class Integer: public Object {
private:
	int _value;
public:
	Integer() : _value(0) { }
	Integer(const int &value) : _value(value) { }

	int value() {
        return _value;
    }

	string toString() override {
	    return "Integer";   
    }
};