#pragma once

#include <iostream>
using namespace std;

template <class T> class Result {
public:
    bool success;
    T data;
    int errorCode;
    string message;
};