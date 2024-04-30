#include <iostream>
using namespace std;

#include "Student.h"

// Constructor
Student::Student() {
    _ID = "<No Data>";
    _fullName = "<No Data>";
    _address = "<No Data>";
    _email = "<No Data>";
}

// Accessor
string Student::getID() {
    return _ID;
}

string Student::getFullName() {
    return _fullName;
}

string Student::getAddress() {
    return _address;
}

string Student::getEmail() {
    return _email;

}

Date Student::getDOB() {
    return _DOB;
}

void Student::setID(string data) {
    _ID = data;
}

void Student::setFullName(string data) {
    _fullName = data;
}

void Student::setAddress(string data) {
    _address = data;
}

void Student::setEmail(string data) {
    _email = data;
}

void Student::setDOB(Date data) {
    _DOB =data;
}

// Operation
void Student::input() {
    cout << "Enter ID: ";
    getline(cin, _ID);
    cout << "Enter full name: ";
    getline(cin, _fullName);
    cout << "Enter address: ";
    getline(cin, _address);
    cout << "Enter email: ";
    getline(cin, _email);
    Date date;
    date.input();
    _DOB = date;
}

void Student::output() {
    cout << "Student ID: " << _ID << endl;
    cout << "Student full name: " << _fullName << endl;
    cout << "Student address: " << _address << endl;
    cout << "Student email: " << _email << endl;
    cout << "Student date of birth: ";
    _DOB.output();
    cout << endl;
}