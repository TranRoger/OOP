#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Class.h"

using namespace std;

class Configuration {
private:
    unsigned int _maxCount; // if student's count > maxCount, that student will not be on the board
    int _seed; // random seed
    vector<pair<int, int>> _rate; // rate of student count
public:
    // constructor
    Configuration();
    // accessor
    int getSeed();
    vector<pair<int, int>> getRate();
    // operation
    void loadConfig();
    bool find(const int &);
    void sort(const int &, const int &);
    void calculate(Class &);
};