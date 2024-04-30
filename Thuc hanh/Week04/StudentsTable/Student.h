#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string _id;
    string _fullname;
    string _email;
public:
    Student();
    Student(string, string, string);
};

class StudentProvider {
public:
    static vector<Student> getAll();
};
