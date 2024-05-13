#pragma once

#include <iostream>
#include <sstream>
#include "Object.h"

class IShape : public Object {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual ~IShape() { }
};

class Rectangle : public IShape {
private:
    double _width;
    double _height;
public:
    Rectangle() : _width(1), _height(1) { }
    Rectangle(const int &w, const int &h) : _width(w), _height(h) { }
    // method implementation
    std::string toString() override {
        std::stringstream builder;
        builder << "Rectangle w=" << _width << ", h=" << _height;
        return builder.str();
    }

    double area() override {
        return _width * _height;
    }

    double perimeter() override {
        return 2 * (_width + _height);
    }
};

class Square : public IShape {
private:
    double _a;
public:
    Square() : _a(1) { }
    Square(const int &a) : _a(a) { }
    // method implementation
    std::string toString() override {
        std::stringstream builder;
        builder << "Square a=" << _a;
        return builder.str();
    }

    double area() override {
        return _a * _a;
    }

    double perimeter() override {
        return 4 * _a;
    }
};

class Circle : public IShape {
private:
    double _radius;
public:
    Circle() : _radius(1) { }
    Circle(const int &r) : _radius(r) { }
    // method implementation
    std::string toString() override {
        std::stringstream builder;
        builder << "Circle r=" << _radius;
        return builder.str();
    }

    double area() override {
        return 3.14 * _radius * _radius;
    }

    double perimeter() override {
        return 2 * _radius * 3.14;
    }
};
