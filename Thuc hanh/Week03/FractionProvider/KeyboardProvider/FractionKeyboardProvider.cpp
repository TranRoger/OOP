#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include "FractionKeyboardProvider.h"
using namespace std;

Fraction FractionKeyboardProvider::next() {
    string buffer; // handle user input
    regex fractionPattern("\\d+/\\d+"); // fraction pattern
    string num, den;
    do { // create an infinite loop to handle input
        system("cls");
        cout << "Enter fraction: ";
        getline(cin, buffer);
        if (buffer.size() == 0) { // if user enter nothing, require entering again
            cout << "Cannot leave blank!" << endl;
            system("pause");
            continue;
        }
        bool match = regex_match(buffer, fractionPattern); // check if user input is in right pattern
        if (!match) {
            cout << "Invalid input! Your input: " << buffer << endl;
            cout << "Valid input pattern: a/b" << endl;
            system("pause");
            continue;
        }

        int seperator = buffer.find('/'); // find '/' in buffer to seperate numerator and denominator
        num = buffer.substr(0, seperator);
        den = buffer.substr(seperator + 1, buffer.size() - seperator - 1);
        if (stoi(den) == 0) {
            cout << "Denominator cannot be zero." << endl;
            system("pause");
            continue;
        }
        else break;
    } while (true);

    Fraction result(stoi(num), stoi(den));
    return result;
}