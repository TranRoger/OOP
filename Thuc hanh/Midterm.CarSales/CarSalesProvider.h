#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Car.h"

using namespace std;

class CarSalesProvider {
public:
    static vector<Car> read(const string &fileName) {
        ifstream fin;
        fin.open(fileName, ios::in);
        if (!fin.good()) {
            throw runtime_error("File not found.");
        }
        string buffer;

        for (int i = 0; i < 11; i++) { // read the header
            getline(fin, buffer, ',');
        }
        getline(fin, buffer);
        buffer.erase(); // end of header

        vector<Car> carSalesList(0);

        while (!fin.eof()) {
            string name, year, sellingPrice, kmDriven, fuel, sellerType, transmission, owner, mileage, engine, maxPower, seats;
            getline(fin, name, ',');
            getline(fin, year, ',');
            getline(fin, sellingPrice, ',');
            getline(fin, kmDriven, ',');
            getline(fin, fuel, ',');
            getline(fin, sellerType, ',');
            getline(fin, transmission, ',');
            getline(fin, owner, ',');
            getline(fin, mileage, ',');
            getline(fin, engine, ',');
            getline(fin, maxPower, ',');
            getline(fin, seats);

            if (0 == mileage.size()) {
                Car car(name, stoi(year), stoi(sellingPrice), stoi(kmDriven), fuel, sellerType, transmission, owner);
                carSalesList.push_back(car);
            }
            else {
                Car car(name, stoi(year), stoi(sellingPrice), stoi(kmDriven), fuel, sellerType, transmission, owner, stod(mileage), stoi(engine), stod(maxPower), stoi(seats));
                carSalesList.push_back(car);
            }
        }
        fin.close();

        return carSalesList;
    }
};