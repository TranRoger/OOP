#include <iostream>
using namespace std;

#include "Point.h"

// Constructor
Point::Point() {
    _X = 0;
    _Y = 0;
}

// Accessor
float Point::getX() {
    return _X;
}

float Point::getY() {
    return _Y;
}

void Point::setX(float data) {
    _X = data;
} 

void Point::setY(float data) {
    _Y = data;
}

// Operation
void Point::input() {
    cout << "Enter X: ";
    cin >> _X;
    cout << "Enter Y: ";
    cin >> _Y;
}

void Point::output() {
    cout << "(" << _X << "," << _Y << ")";
}