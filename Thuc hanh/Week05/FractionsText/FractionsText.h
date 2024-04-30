#pragma once

#include <iostream>
#include "FractionsTextProvider.h"
#include "FractionToDecimalConverter.h"
#include "FractionToPercentageConverter.h"
#include "NumberFormat.h"

using namespace std;

class FractionsText {
public:
    static void instruction(string fileName) {
        vector<Fraction> data = FractionsTextProvider::read(fileName);

        cout << endl;
        cout << "Found " << data.size() << " fractions: ";
        for (auto s : data) {
            cout << s.toString() << ", ";
        }

        vector<Fraction> lowestTerm = data;
        cout << "Lowest term: ";
        for (auto s : lowestTerm) {
            s.lowestTerm();
            cout << s.toString() << ", ";
        }

        NumberFormat decimal(" ", ".", 2);
        FractionToDecimalConverter toDec(decimal);
        cout << "Decimal: ";
        for (auto s : data) {
            cout << toDec.convert(s) << ", ";
        }

        NumberFormat percentage(" ", ".", 0);
        FractionToPercetageConverter toPer(percentage);
        cout << "Percentage: ";
        for (auto s : data) {
            cout << toPer.convert(s) << ", ";
        }
    }
};