#include <iostream>
using namespace std;

#include "Line.h"

// Constructor
Line::Line() {
    _X1 = 0;
    _Y1 = 1;
    _X2 = 1;
    _Y2 = 0;
}

// Accessor
float Line::getX1() {
    return _X1;
}

float Line::getX2() {
    return _X2;
}

float Line::getY1() {
    return _Y1;
}

float Line::getY2() {
    return _Y2;
}

void Line::setX1(float data) {
    _X1 = data;
}

void Line::setX2(float data) {
    _X2 = data;
}

void Line::setY1(float data) {
    _Y1 = data;
}

void Line::setY2(float data) {
    _Y2 = data;
}

// Operation
void Line::input() {
    cout << "Enter X1: ";
    cin >> _X1;
    cout << "Enter Y1: ";
    cin >> _Y1;
    cout << "Enter X2: ";
    cin >> _X2;
    cout << "Enter Y2: ";
    cin >> _Y2;
}

void Line::output() {
    cout << "p1(" << _X1 << "," << _Y1 << ") p2(" << _X2 << "," << _Y2 << ")";
}