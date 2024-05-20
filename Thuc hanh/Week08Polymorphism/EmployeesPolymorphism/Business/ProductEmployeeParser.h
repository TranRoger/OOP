#pragma once 

#include <iostream>
#include "IParsable.h"
#include "../Helper/Utils.h"
#include "../Entity/ProductEmployee.h"

class ProductEmployeeParser : public IParsable {
public:
    Object* parse(std::string token) override {
        std::vector<std::string> tokens = Utils::String::split(token, ", ");
        int pc = stoi(Utils::String::split(tokens[0], "=")[1]);
        int ppp = stoi(Utils::String::split(tokens[1], "=")[1]);
        return new ProductEmployee(pc, ppp);
    }

    std::string parsedObjectName() override {
        return "ProductEmployee";
    }
};