#pragma once

#include <string>
#include "..\DateInput\Date.h"

using std::string;

class Student {
private:
    string _ID;
    string _fullName;
    string _address;
    string _email;
    Date _DOB;

public:
    // Constructor
    Student();

    // Accessor
    string getID();
    string getFullName();
    string getAddress();
    string getEmail();
    Date getDOB();
    void setID(string);
    void setFullName(string);
    void setAddress(string);
    void setEmail(string);
    void setDOB(Date);

    // Operation
    void input();
    void output();
};