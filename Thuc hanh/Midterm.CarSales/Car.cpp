#include "Car.h"

// setter
void Car::setName(const string &name) {
    this->_name = name;
}

void Car::setYear(const int &year) {
    this->_year = year;
}

void Car::setSellingPrice(const int &sellingPrice) {
    this->_sellingPrice = sellingPrice;
}

void Car::setKmDriven(const int &kmDriven) {
    this->_kmDriven = kmDriven;
}

void Car::setFuel(const string &fuel) {
    this->_fuel = fuel;
}

void Car::setSellerType(const string &sellerType) {
    this->_sellerType = sellerType;
}

void Car::setTransmission(const string &transmission) {
    this->_transmission = transmission;
}

void Car::setOwner(const string &owner) {
    this->_owner = owner;
}

void Car::setMileage(const double &mileage) {
    this->_mileage = mileage;
}

void Car::setEngine(const int &engine) {
    this->_engine = engine;
}

void Car::setMaxPower(const double &maxPower) {
    this->_maxPower = maxPower;
}

void Car::setSeats(const int &seats) {
    this->_seats = seats;
}


// getter
string Car::getName() const {
    return this->_name;
}

int Car::getYear() const {
    return this->_year;
}

int Car::getSellingPrice() const {
    return this->_sellingPrice;
}

int Car::getKmDriven() const {
    return this->_kmDriven;
}

string Car::getFuel() const {
    return this->_fuel;
}

string Car::getSellerType() const {
    return this->_sellerType;
}

string Car::getTransmission() const {
    return this->_transmission;
}

string Car::getOwner() const {
    return this->_owner;
}

double Car::getMileage() const {
    return this->_mileage;
}

int Car::getEngine() const {
    return this->_engine;
}

double Car::getMaxPower() const {
    return this->_maxPower;
}

int Car::getSeats() const {
    return this->_seats;
}