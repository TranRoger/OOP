#pragma once

#include <iostream>
#include "Employee.h"

class ProductEmployee : public Employee {
private:
    int _productCount;
    int _paymentPerProduct;
public:
    ProductEmployee(const int &pc, const int &ppp) :
        _productCount(pc), _paymentPerProduct(ppp) { }
    
    std::string toString() override {
        return "Product Employee";
    }

    int salary() override {
        return _productCount * _paymentPerProduct;
    }
};