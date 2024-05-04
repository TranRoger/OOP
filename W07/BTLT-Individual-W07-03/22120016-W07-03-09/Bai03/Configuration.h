#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Class.h"

using namespace std;

class Configuration {
private:
    unsigned int _maxCount; // if student's count > maxCount, that student will not be on the board
    vector<pair<int, int>> _rate; // rate of student count
    vector<pair<int, int>> _configRate; // rate by config.txt
public:
    // constructor
    Configuration();
    // accessor
    int getSeed();
    vector<pair<int, int>> getRate();
    vector<pair<int, int>> getConfig();
    bool callOnce();
    // operation
    void loadConfig();
    void setCallOnce();
    bool find(const int &);
    void sort(const int &, const int &);
    void calculate(Class &);
};