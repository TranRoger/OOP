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
    bool _byConfig;
    bool _callOnce;
public:
    // constructor
    Random(bool, bool);
    // operation
    Student next(Class &);
    vector<Student> getGroup(const vector<Student> &, const int &);
};