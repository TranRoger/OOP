#pragma once

#include <iostream>
#include <sstream>
#include <regex>
#include "IValueConverter.h"
#include "../Entity/Integer.h"
#include "../Entity/NumberFormatInfo.h"

using std::string, std::stringstream, std::regex;

class IntegerToCurrencyConverter : public IValueConverter {
public:
    string convert(Object* object) override;
};