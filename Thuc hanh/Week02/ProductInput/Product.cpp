#include <iostream>
using namespace std;

#include "Product.h"
// Constructor
Product::Product() {
    _ID = "<No data>";
    _name = "<No data>";
    _price = 0;
}

// Accessor
string Product::getID() {
    return _ID;
}

string Product::getName() {
    return _name;
}

float Product::getPrice() {
    return _price;
}

Date Product::getExpiryDate() {
    return _expiryDate;
}

void Product::setID(string data) {
    _ID = data;
}

void Product::setName(string data) {
    _ID = data;
}

void Product::setPrice(float data) {
    _price = data;
}

void Product::setExpiryDate(Date data) {
    _expiryDate = data;
}

// Operation
void Product::input() {
    cout << "ID: ";
    getline(cin, _ID);
    cout << "Name: ";
    getline(cin, _name);
    cout << "Price: ";
    cin >> _price;
    Date data;
    data.input();
    _expiryDate = data;
}

void Product::output() {
    cout << "Product ID: " << _ID << endl;
    cout << "Product name: " << _name << endl;
    cout << "Price: " << _price << endl;
    cout << "Expiry date: ";
    _expiryDate.output();
    cout << endl;
}