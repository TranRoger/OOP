#pragma once 

#include <iostream>
#include <vector>
#include "Car.h"

using namespace std;

class SortBySellingPrice {
public:
    static void sort(vector<Car> &carSales) {
        for (int i = 0; i < carSales.size(); i++) {
            int max = i;
            for (int j = i + 1; j < carSales.size(); j++) {
                if (carSales[max].getSellingPrice() < carSales[j].getSellingPrice()) {
                    max = j;
                }
            }
            swap(carSales[i], carSales[max]);
        }
    }
};