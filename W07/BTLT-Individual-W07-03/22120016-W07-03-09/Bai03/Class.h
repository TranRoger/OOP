#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"

class Class {
private:
    vector<Student> _students;
public:
    vector<Student> _notOnBoard;
public:
    // constructor
    Class();
    Class(const string &);
    // destructor
    ~Class();
    // accessor
    int getSize();
    Student getStudent(const int &);
    void updateStudent(const string &);
    // operation
    void importFromFile(const string &);
    void exportToFile(const string &);
};