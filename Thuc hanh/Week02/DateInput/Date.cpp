#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

#include "Date.h"

// Constructor
Date::Date() {
    time_t info = time(NULL);
    tm now;
    localtime_s(&now, &info);

    _day = now.tm_mday;
    _month = now.tm_mon + 1;
    _year = now.tm_year + 1900;
}

// Accessor
int Date::getDay() {
    return _day;
}

int Date::getMonth() {
    return _month;
}

int Date::getYear() {
    return _year;
}

void Date::setDay(int data) {
    _day = data;
}

void Date::setMonth(int data) {
    _month = data;
}

void Date::setYear(int data) {
    _year = data;
}

// Operation
void Date::input() {
    cout << "Enter day: ";
    cin >> _day;
    cout << "Enter month: ";
    cin >> _month;
    cout << "Enter Year: ";
    cin >> _year;
}

void Date::output() {
    cout << setw(2) << setfill('0') << _day << "/" << setw(2) << _month << "/" << setw(4) << _year;
}