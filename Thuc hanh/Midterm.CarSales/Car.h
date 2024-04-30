#pragma once

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string _name;
    int _year;
    int _sellingPrice;
    int _kmDriven;
    string _fuel;
    string _sellerType;
    string _transmission;
    string _owner;
    double _mileage;
    int _engine;
    double _maxPower;
    int _seats;

public:
    // constructor
    Car() {}

    Car(const string& name, const int &year, const int &sellingPrice, const int &kmDriven, const string &fuel, const string &sellerType, const string &transmission, const string &owner) : _name(name), _year(year), _fuel(fuel), _sellingPrice(sellingPrice), _kmDriven(kmDriven), _sellerType(sellerType), _transmission(transmission), _owner(owner) {   }

    Car(const string& name, const int &year, const int &sellingPrice, const int &kmDriven, const string &fuel, const string &sellerType, const string &transmission, const string &owner, const double &mileage, const int &engine, const double &maxPower, const int &seats) : _name(name), _year(year), _sellingPrice(sellingPrice), _kmDriven(kmDriven), _fuel(fuel), _sellerType(sellerType), _transmission(transmission), _owner(owner), _mileage(mileage), _engine(engine), _maxPower(maxPower), _seats(seats) {   }

    // setter
    void setName(const string &);
    void setYear(const int &);
    void setSellingPrice(const int &);
    void setKmDriven(const int &);
    void setFuel(const string &);
    void setSellerType(const string &);
    void setTransmission(const string &);
    void setOwner(const string &);
    void setMileage(const double &);
    void setEngine(const int &);
    void setMaxPower(const double &);
    void setSeats(const int &);

    // getter
    string getName() const;
    int getYear() const;
    int getSellingPrice() const;
    int getKmDriven() const;
    string getFuel() const;
    string getSellerType() const;
    string getTransmission() const;
    string getOwner() const;
    double getMileage() const;
    int getEngine() const;
    double getMaxPower() const;
    int getSeats() const;
};