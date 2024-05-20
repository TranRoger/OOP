#pragma once

#include <iostream>
#include "Employee.h"

class DailyEmployee : public Employee {
private:
    int _dayCount;
    int _paymentPerDay;
public:
    DailyEmployee(const int &dc, const int &ppd) :
        _dayCount(dc), _paymentPerDay(ppd) { }

    std::string toString() override {
        return "Daily Employee";
    }

    int salary() override {
        return _dayCount * _paymentPerDay;
    }
};