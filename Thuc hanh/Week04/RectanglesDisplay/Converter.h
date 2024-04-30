#pragma once

#include <iostream>
#include "Rectangle.h"
#include <string>
using namespace std;

class SolidRectangleConverter {
private:
    string _fill;
public:
    SolidRectangleConverter() : _fill("*") {};
    SolidRectangleConverter(const string& fill) : _fill(fill) {};
    string convert(const Rectangle &);
};

class HollowRectangleConverter {
private:
    string _fill;
public:
    HollowRectangleConverter() : _fill("*") {};
    HollowRectangleConverter(const string& fill) : _fill(fill) {};
    string convert(const Rectangle &);
};