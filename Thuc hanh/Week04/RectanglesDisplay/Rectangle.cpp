#include <iostream>
#include "Rectangle.h"
#include <string>
#include <sstream>

using namespace std;

int Rectangle::width() const {
    return _width;
}

int Rectangle::height() const {
    return _height;
}

string Rectangle::toString() const {
    stringstream builder;
    builder << "Rectangle Width=" << _width << ", Height=" << _height;
    string result = builder.str();
    return result; 
}