#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Object.h"
#include "Utils.h"

using std::shared_ptr;

class IParsable {
public:
    virtual std::string parsedObjectName() = 0;
    virtual shared_ptr<Object> parse(std::string) = 0;
};