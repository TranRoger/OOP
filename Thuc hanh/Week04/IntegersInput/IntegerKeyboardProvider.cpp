#include <iostream>
using namespace std;

#include "IntegerKeyboardProvider.h"
#include <string>
#include <regex>

Result<int> IntegerKeyboardProvider::next() {
    Result<int> result;
    string buffer;
    regex intPattern("\\d+");
    getline(cin, buffer);
    if (0 == buffer.size()) {
        result.success = false;
        result.errorCode = 0;
        result.message = "Cannot leave blank.";
    }
    result.success = regex_match(buffer, intPattern);
    if (false == result.success) {
        result.errorCode = 1;
        result.message = "Invalid input.";
    }
    else {
        result.data = stoi(buffer);
    }
    return result;
}

Result<int> IntegerKeyboardProvider::next(const int &min, const int& max) {
    Result<int> result;
    string buffer;
    regex intPattern("\\d+");
    cin >> buffer;
    if (0 == buffer.size()) {
        result.success = false;
        result.errorCode = 0;
        result.message = "Cannot leave blank.";
    }
    result.success = regex_match(buffer, intPattern);
    if (false == result.success) {
        result.errorCode = 1;
        result.message = "Invalid input.";
    }
    else {
        result.data = stoi(buffer);
        if (result.data < min || result.data > max) {
            result.success = false;
            result.errorCode = 2;
            result.message = "Out of bound.";
        }
        else {
            result.success = true;
        }
    }
    return result;
}