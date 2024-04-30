#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Rectangle {
private:
    int _width;
    int _height;
public:
    // constructor
    Rectangle() {
        _width = 1;
        _height = 1;
    }

    Rectangle(int width, int heigth) { 
        _width = width;
        _height = heigth;
    }

    // accessor
    int width() const;
    int height() const;

    // operation
    string toString() const;
};

class RectangleProvider {
public:
    static vector<Rectangle> getAll(){
        return {
            Rectangle(3, 4),
            Rectangle(4, 5),
            Rectangle(4, 8)
        };
    }
};