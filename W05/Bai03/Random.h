#pragma once

#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include "Configuration.h"
#include "Class.h"
#include "Student.h"

using namespace std;

class Random {
private:
    Configuration _config;
public:
    // constructor
    Random();
    // operation
    Student next(Class &);
    vector<Student> getGroup(const vector<Student> &, const int &);
};