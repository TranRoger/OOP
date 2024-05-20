#pragma once 

#include <iostream>
#include "IParsable.h"
#include "../Helper/Utils.h"
#include "../Entity/Manager.h"

class ManagerParser : public IParsable {
public:
    Object* parse(std::string token) override {
        std::vector<std::string> tokens = Utils::String::split(token, ", ");
        int ec = stoi(Utils::String::split(tokens[0], "=")[1]);
        int ppe = stoi(Utils::String::split(tokens[1], "=")[1]);
        int bs = stoi(Utils::String::split(tokens[2], "=")[1]);
        return new Manager(ec, ppe, bs);
    }

    std::string parsedObjectName() override {
        return "Manager";
    }
};