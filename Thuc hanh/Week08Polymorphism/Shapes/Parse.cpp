#include "Parse.h"

// RectangleParser
std::string RectangleParser::parsedObjectName() {
    return "Rectangle";
}

shared_ptr<Object> RectangleParser::parse(std::string token) {
    std::vector<std::string> t = Utils::String::split(token, ", ");
    double w = std::stod(Utils::String::split(t[0], "=")[1]);
    double h = std::stod(Utils::String::split(t[1], "=")[1]);
    return shared_ptr<Rectangle> (new Rectangle(w, h));
}

// SquareParser
std::string SquareParser::parsedObjectName() {
    return "Square";
}

shared_ptr<Object> SquareParser::parse(std::string token) {
    double a = std::stod(Utils::String::split(token, "=")[1]);
    return shared_ptr<Square> (new Square(a));
}

// CircleParser
std::string CircleParser::parsedObjectName() {
    return "Circle";
}

shared_ptr<Object> CircleParser::parse(std::string token) {
    double r = std::stod(Utils::String::split(token, "=")[1]);
    return shared_ptr<Circle> (new Circle(r));
}