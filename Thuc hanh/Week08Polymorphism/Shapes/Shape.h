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
    Rectangle();
    Rectangle(const int &, const int &);
    // method implementation
    std::string toString() override;
    double area() override ;
    double perimeter() override ;
};

class Square : public IShape {
private:
    double _a;
public:
    Square();
    Square(const int &);
    // method implementation
    std::string toString() override;
    double area() override;
    double perimeter() override;
};

class Circle : public IShape {
private:
    double _radius;
public:
    Circle();
    Circle(const int &r);
    // method implementation
    std::string toString() override;
    double area() override;
    double perimeter() override;
};
