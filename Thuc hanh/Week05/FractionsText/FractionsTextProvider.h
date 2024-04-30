#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Fraction.h"

using namespace std;

class FractionsTextProvider {
public:
    static vector<Fraction> read(string fileName) {
        ifstream fin;
        fin.open(fileName, ios::in);
        if (!fin.good()) {
            throw runtime_error("File not found");
        }
        cout << "Reading data from " << fileName << "." << endl;
        string buffer;
        int size;
        getline(fin, buffer);
        size = stoi(buffer);
        cout << "Expected to find " << size << " fractions." << endl;
        vector<Fraction> result;
        while (size--) {
            getline(fin, buffer);
            int sep = buffer.find('/');
            string num = buffer.substr(0, sep), den = buffer.substr(sep + 1, buffer.size() - sep);
            Fraction f(stoi(num), stoi(den));
            result.push_back(f);
        }
        return result;
    }
}