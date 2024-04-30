#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include "Car.h"

using namespace std;

class CarToTableConverter {
private:
    vector<std::string> _headers;
    vector<int> _columnSizes;
    int _top;
public:
    CarToTableConverter() { }
    CarToTableConverter(vector<string> headers, vector<int> columnSizes, const int &top) : _headers(headers), _columnSizes(columnSizes), _top(top) {   }

    string convert(vector<Car> cars) {
        if (cars.size() < _top) _top = cars.size();
        stringstream builder;
        for (int i = 0; i < _headers.size(); i++) {
            builder << "|" << setw(_columnSizes[i]) << left << _headers[i];
        }
        builder << "|";
        int width = builder.str().size();
        builder << endl << setw(width) << setfill('-') << "-" << endl << setfill(' ');
        for (int i = 0; i < _top; i++) {
            builder << "|" << setw(_columnSizes[0]) << left << i + 1;
            CarToRowConverter row(_columnSizes);
            builder << row.convert(cars[i]) << endl;
        }
        string result = builder.str();
        return result;
    }

private: // Inner class
    class CarToRowConverter {
    private:
        vector<int> _columnSizes;
    public:
        CarToRowConverter() {   }
        CarToRowConverter(std::vector<int> columnSizes) : _columnSizes(columnSizes) {   }
        string convert(Car car) {
            stringstream builder;
            builder << "|" << setw(_columnSizes[1]) << left << car.getName()
                    << "| & " << setw(_columnSizes[2] - 3) << left << car.getSellingPrice() << "|";
            string result = builder.str();
            return result;
        }
    };
};