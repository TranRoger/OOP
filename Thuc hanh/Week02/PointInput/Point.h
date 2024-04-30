#pragma once

class Point {
private:
    float _X;
    float _Y;

public:
    // Constructor
    Point();

    // Accessor
    float getX();
    float getY();
    void setX(float);
    void setY(float);

    // Operation
    void input();
    void output();
};