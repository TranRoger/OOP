#pragma once

#include <iostream>
using namespace std;

class MyString {
private:
    char* pString;
public:
    // Constructor 
    MyString();

    // Destructor
    ~MyString();

    // Accessor
    char* getPString();

    // Operation
    void input();
    bool operator == (const MyString&);
    MyString& operator += (const MyString&);
    MyString& operator = (const MyString&);
    friend ostream& operator<<(ostream&, const MyString&);
};