#pragma once

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string _cccd;
    string _fullName;
    int _balance;
public:
    // constructor
    BankAccount();
    BankAccount(const string &, const string &, const int &);
    // operation
    void deposit(const unsigned int &);
    void withdraw(const unsigned int &);
    void checkBalance();
};