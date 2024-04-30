#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include "IntegersTextProvider.h"

using namespace std;

class IntegerText {
private:
    vector<int> _data;
public:
    void instruction(string fileName) {
        cout << "Working with integer arrays from text files" << endl << endl;
        _data = IntegersTextProvider::read(fileName);

        vector<int> odd = findOdd();
        vector<int> even = findEven();
        vector<int> palindromic = palindrome();
        vector<int> prime = findPrime();
        vector<int> square = findSquare();
        vector<int> perfect = findPerfect();
        
        cout << endl;
        cout << "Found " << _data.size() << " numbers: ";
        for (auto s : _data) {
            cout << s;
            if (s != _data[_data.size() - 1]) {
                cout << ", ";
            }
        }
        cout << endl;

        cout << "Found " << odd.size() << " odd numbers: ";
        for (auto s : odd) {
            cout << s;
            if (s != odd[odd.size() - 1]) {
                cout << ", ";
            }
        }
        cout << endl;

        cout << "Found " << even.size() << " even numbers: ";
        for (auto s : even) {
            cout << s;
            if (s != even[even.size() - 1]) {
                cout << ", ";
            }
        }
        cout << endl;

        cout << "Found " << palindromic.size() << " palindromic numbers: ";
        for (auto s : palindromic) {
            cout << s;
            if (s != palindromic[palindromic.size() - 1]) {
                cout << ", ";
            }
        }
        cout << endl;

        cout << "Found " << prime.size() << " prime numbers: ";
        for (auto s : prime) {
            cout << s;
            if (s != prime[prime.size() - 1]) {
                cout << ", ";
            }
        }
        cout << endl;

        cout << "Found " << square.size() << " square numbers: ";
        for (auto s : square) {
            cout << s;
            if (s != square[square.size() - 1]) {
                cout << ", ";
            }
        }
        cout << endl;

        cout << "Found " << perfect.size() << " perfect numbers: ";
        for (auto s : perfect) {
            cout << s;
            if (s != perfect[perfect.size() - 1]) {
                cout << ", ";
            }
        }
        cout << endl;

        cout << "Minimum value: " << min() << endl;
        cout << "Maximum value: " << max() << endl;
        cout << "Average value: " << avg() << endl;
        cout << "Sum of all numbers: " << sum() << endl;
    }

    vector<int> findOdd() {
        vector<int> result(0);
        for (auto d : _data) {
            if (d & 1) result.push_back(d);
        }
        return result;
    }

    vector<int> findEven() {
        vector<int> result(0);
        for (auto d : _data) {
            if (!(d & 1)) result.push_back(d);
        }
        return result;
    }

    vector<int> palindrome() {
        vector<int> result(0);
        for (auto s : _data) {
            string num = to_string(s);
            bool isPalindrome = true;
            for (int i = 0; i < num.size() / 2; i++) {
                if (num[i] != num[num.size() - i - 1]) {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) result.push_back(s);
        }
        return result;
    }

    vector<int> findPrime() {
        vector<int> result(0);
        for (auto s : _data) {
            if (s < 2) continue;
            else if (s == 2) result.push_back(s);
            else {
                bool isPrime = true;
                for (int i = 2; i <= sqrt(s); i++) {
                    if (s % i == 0) {
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime) result.push_back(s);
            }
        }
        return result;
    }

    vector<int> findSquare() {
        vector<int> result(0);
        for (auto s : _data) {
            int m = sqrt(s);
            if (m * m == s) result.push_back(s);
        }
        return result;
    }

    vector<int> findPerfect() {
        vector<int> result(0);
        for (auto s : _data) {
            int d = 0;
            for (int i = 1; i < s; i++) {
                if (s % i == 0) d += i;
            }
            if (d == s) result.push_back(s);
        }
        return result;
    }

    int min() {
        int m = _data[0];
        for (auto s : _data) {
            if (m > s) {
                m = s;
            }
        }
        return m;
    }

    int max() {
        int m = _data[0];
        for (auto s : _data) {
            if (m < s) {
                m = s;
            }
        }
        return m;
    }

    double avg() {
        double sum = 0.0;
        for (auto s : _data) {
            sum += s;
        }
        return sum / double(_data.size());
    }

    int sum() {
        int result = 0;
        for (auto s : _data) {
            result += s;
        }
        return result;
    }
};