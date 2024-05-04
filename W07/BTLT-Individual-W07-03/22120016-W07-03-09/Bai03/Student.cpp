#include "Student.h"

// constructor
Student::Student() : _id(""), _count(0) {

}

Student::Student(const string &id, const unsigned int &count) : _id(id), _count(count) {

}

// accessor
string Student::getID() {
    return _id;
}

void Student::addCount() {
    _count++;
}

unsigned int Student::getCount() {
    return _count;
}