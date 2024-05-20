#pragma once

#include <iostream>
#include "../Entity/Object.h"

class IValueConverter {
public:
    virtual std::string convert(Object*) = 0;
};