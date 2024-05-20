#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Object.h"
#include "Utils.h"
#include "Shape.h"

using std::shared_ptr;

class IParsable {
public:
    virtual std::string parsedObjectName() = 0;
    virtual shared_ptr<Object> parse(std::string) = 0;
};

class RectangleParser : public IParsable {
public:
    std::string parsedObjectName() override;
    shared_ptr<Object> parse(std::string token);
};

class SquareParser : public IParsable {
public:
    std::string parsedObjectName() override;
    shared_ptr<Object> parse(std::string token);
};

class CircleParser : public IParsable {
public:
    std::string parsedObjectName() override ;
    shared_ptr<Object> parse(std::string token);
};
