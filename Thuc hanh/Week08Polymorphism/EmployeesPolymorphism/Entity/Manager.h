#pragma once

#include <iostream>
#include "Employee.h"

class Manager : public Employee {
private:
    int _employeeCount;
    int _paymentPerEmployee;
    int _baseSalary;
public:
    Manager(const int &ec, const int &ppe, const int &bs) :
        _employeeCount(ec), _paymentPerEmployee(ppe), _baseSalary(bs) { }
    
    std::string toString() override {
        return "Manager";
    }

    int salary() override {
        return _baseSalary;
    }
};