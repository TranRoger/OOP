#pragma once

#include <iostream>

class IFace {
public:
    virtual void show() = 0;
    virtual IFace *clone() = 0;
    virtual ~IFace() {

    }
};

class Face : public IFace {
private:
    std::string shape;
protected:
    std::string getShape() { return shape; };
public:
    Face() : shape("No shape") {

    }

    Face(std::string sh) : shape(sh) {

    }

    virtual void show() {
        std::cout << "Shape: " << shape << std::endl;
    }

    virtual IFace* clone() {
        IFace *f = new Face(shape);
        return f;
    }
    virtual ~Face() {
    }
};

class EyedFace : public Face {
private:
    int eyes;
public:
    static int objCount;

    EyedFace(std::string sh, int e) : Face(sh), eyes(e) {
        EyedFace::objCount++;
    }

    void show() {
        Face::show();
        std::cout << "Eyes: " << eyes << std::endl;
    }

    IFace *clone() override {
        IFace *c = new EyedFace(getShape(), eyes);
        return c;
    }
    
    ~EyedFace() {
        EyedFace::objCount--;
    }
};