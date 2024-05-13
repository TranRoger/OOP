#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Object.h"
#include "Utils.h"

class IParsable {
public:
    virtual std::string parsedObjectName() = 0;
    virtual Object* parse(std::string) = 0;
};

class RectangleParser : public IParsable {
public:
    std::string parsedObjectName() override {
        return "Rectangle";
    }

    Object* parse(std::string token) {
        std::vector<std::string> t = Utils::String::split(token, ", ");
        double w = std::stod(Utils::String::split(t[0], "=")[1]);
        double h = std::stod(Utils::String::split(t[1], "=")[1]);
        return new Rectangle(w, h);
    }
};

class SquareParser : public IParsable {
public:
    std::string parsedObjectName() override {
        return "Square";
    }

    Object* parse(std::string token) {
        double a = std::stod(Utils::String::split(token, "=")[1]);
        return new Square(a);
    }
};

class CircleParser : public IParsable {
public:
    std::string parsedObjectName() override {
        return "Circle";
    }

    Object* parse(std::string token) {
        double r = std::stod(Utils::String::split(token, "=")[1]);
        return new Circle(r);
    }
};
