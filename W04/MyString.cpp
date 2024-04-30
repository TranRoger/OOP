#include <iostream>
using namespace std;

#include "MyString.h"
#include <string.h>

// Constructor
MyString::MyString() {
    pString = new char;
    pString[0] = '\0';
}

// Destructor
MyString::~MyString() {
    delete[] pString;
    pString = nullptr;
}

// Accessor
char* MyString::getPString() {
    return pString;
}

// Operation
void MyString::input() {
    cout << "Input: ";
    char* buffer = new char[1000];
    cin.getline(buffer, 1000);
    int size = strlen(buffer);
    delete[] pString;
    pString = new char[size];
    strcpy(pString, buffer);
}

bool MyString::operator == (const MyString &someString) {
    return strcmp(pString, someString.pString) == 0;
}

MyString &MyString::operator+=(const MyString &someString) {
    strcat(this->pString, someString.pString);
    return *this;
}

MyString &MyString::operator=(const MyString &someString) {
    strcpy(this->pString, someString.pString);
    return *this;
}

ostream& operator<<(ostream& os, const MyString& string) {
    for (int i = 0; i < strlen(string.pString); i++) {
        os << string.pString[i];
    }
    return os;
}