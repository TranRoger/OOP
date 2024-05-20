#pragma once

#include <iostream>
#include "Object.h"

class Employee : public Object {
public:
    virtual int salary() = 0;
};