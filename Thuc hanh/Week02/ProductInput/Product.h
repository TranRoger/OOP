#pragma once

#include <string>
#include "..\DateInput\Date.h"
using std::string;

class Product {
private:
    string _ID;
    string _name;
    float _price;
    Date _expiryDate;

public:
    // Constructor
    Product();

    // Accessor
    string getID();
    string getName();
    float getPrice();
    Date getExpiryDate();
    void setID(string);
    void setName(string);
    void setPrice(float);
    void setExpiryDate(Date);

    // Operation
    void input();
    void output();
};