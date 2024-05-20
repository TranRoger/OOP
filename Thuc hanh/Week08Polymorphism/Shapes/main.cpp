#include <iostream>
#include <vector>
#include <memory>
#include "Shape.h"
#include "ParserFactory.h"
#include "Utils.h"
#include "Parse.h"

using namespace std;

ParserFactory *ParserFactory::instance = nullptr;
int main() {
    vector<string> lines = {
        "Square: a=12",
        "Circle: r=12",
        "Square: a=7",
        "Rectangle: w=3, h=4",
        "Rectangle: w=6, h=8",
        "Circle: r=5",
        "Square: a=8"
    };

    ParserFactory *factory = ParserFactory::getInstance();
    factory->registerWith(shared_ptr<RectangleParser> (new RectangleParser()));
	factory->registerWith(shared_ptr<SquareParser> (new SquareParser()));
	factory->registerWith(shared_ptr<CircleParser> (new CircleParser()));

    vector<shared_ptr<IShape>> shapes;
        
    for (auto& line : lines) {
        // Example: line = "Square: a=12"
        vector<string> tokens = Utils::String::split(line, ": ");
        shared_ptr<IParsable> parser = factory->create(tokens[0]); // "Square"=> SquareParser
        shared_ptr<IShape> shape = dynamic_pointer_cast<IShape>(parser->parse(tokens[1])); // "a=12" => Square(_a = 12)
        shapes.push_back(shape);
    }

    for (auto& shape : shapes) { // Polymorphism
        cout << shape->toString() << ": area=" 
            << shape->area() << ", perimeter=" 
            << shape->perimeter() << endl;
    }
}