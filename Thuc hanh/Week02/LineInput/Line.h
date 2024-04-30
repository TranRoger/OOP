#pragma once

class Line {
private:
    float _X1;
    float _X2;
    float _Y1;
    float _Y2;

public:
    // Constructor
    Line();

    // Accessor
    float getX1();
    float getX2();
    float getY1();
    float getY2();
    void setX1(float);
    void setX2(float);
    void setY1(float);
    void setY2(float);

    // Operation
    void input();
    void output();
};