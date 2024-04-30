#pragma once

#include <iostream>
#include <string>

using namespace std;

class Integer {
public:
	static int parse(string info) {
        try {
            return stoi(info);
        } catch (exception ex) {
            ex.what();
        }
    }
};