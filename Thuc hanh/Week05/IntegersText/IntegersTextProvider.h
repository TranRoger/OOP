#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Integer.h"

using namespace std;

class IntegersTextProvider {
public:
	static vector<int> read(string fileName) {
        ifstream fin;
        fin.open(fileName, ios::in);
        if (!fin.good()) {
            throw runtime_error("File not found");
        }
        cout << "Reading data from " << fileName << "." << endl;
        string buffer;
        getline(fin, buffer);
        int size = Integer::parse(buffer);
        vector<int> result;
        cout << "Expected to find " << size << " numbers." << endl;
        while (size--) {
            getline(fin, buffer);
            int num = Integer::parse(buffer);
            result.push_back(num);
        }
        fin.close();
        return result;
    }
};