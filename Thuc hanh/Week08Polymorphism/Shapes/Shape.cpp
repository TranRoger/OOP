#include "Shape.h"

// Rectangle
// constructor
Rectangle::Rectangle() : _width(1), _height(1) { }

Rectangle::Rectangle(const int &w, const int &h) : _width(w), _height(h) { }
// methods
std::string Rectangle::toString() {
    std::stringstream builder;
    builder << "Rectangle w=" << _width << ", h=" << _height;
    return builder.str();
}

double Rectangle::area() {
    return _width * _height;
}

double Rectangle::perimeter() {
    return 2 * (_width + _height);
}

// Square
// constructor
Square::Square() : _a(1) { }

Square::Square(const int &a) : _a(a) { }
// method implementation
std::string Square::toString() {
    std::stringstream builder;
    builder << "Square a=" << _a;
    return builder.str();
}

double Square::area() {
    return _a * _a;
}

double Square::perimeter() {
    return 4 * _a;
}

// Circle
// constructor
Circle::Circle() : _radius(1) { }

Circle::Circle(const int &r) : _radius(r) { }
// method implementation
std::string Circle::toString() {
    std::stringstream builder;
    builder << "Circle r=" << _radius;
    return builder.str();
}

double Circle::area() {
    return 3.14 * _radius * _radius;
}

double Circle::perimeter() {
    return 2 * _radius * 3.14;
}