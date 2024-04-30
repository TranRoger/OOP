#pragma once 

#include <iostream>
#include <string>
#include <regex>
using namespace std;

class IntegerInputProvider {
public:
    static int next() {
        regex numberPattern("\\d+");
        string buffer;
        do {
            cout << "Enter an integer: ";
            getline(cin, buffer);
            if (0 == buffer.size()) {
                cout << "Cannot leave blank." << endl;
                continue;
            }
            bool match = regex_match(buffer, numberPattern);
            if (!match) {
                cout << "Invalid input!" << endl;
                // buffer.clear();
                continue;
            }
            else {
                break;
            }
        } while (true);
        return stoi(buffer);
    }
};