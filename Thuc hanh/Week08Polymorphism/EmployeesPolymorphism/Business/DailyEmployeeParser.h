#pragma once 

#include <iostream>
#include <vector>
#include "IParsable.h"
#include "../Helper/Utils.h"
#include "../Entity/DailyEmployee.h"

class DailyEmployeeParser : public IParsable {
public:
    Object* parse(std::string token) override {
        std::vector<std::string> tokens = Utils::String::split(token, ", ");
        int dc = stoi(Utils::String::split(tokens[0], "=")[1]);
        int ppd = stoi(Utils::String::split(tokens[1], "=")[1]);
        return new DailyEmployee(dc, ppd);
    }

    std::string parsedObjectName() override {
        return "DailyEmployee";
    }
};