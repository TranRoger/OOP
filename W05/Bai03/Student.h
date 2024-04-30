#pragma once

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string _id;
    unsigned int _count;
public:
    // constructor
    Student();
    Student(const string &, const unsigned int &);
    // accessor
    string getID();
    void addCount();
    unsigned int getCount();
};