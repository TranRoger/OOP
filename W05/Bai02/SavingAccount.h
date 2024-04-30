#pragma once

#include <iostream>
#include "BankAccount.h"

using namespace std;

class SavingAccount : private BankAccount {
private:
    double _interestRate;
    int _term;
    int _monthsOfDeposit;
public:
    // constructor
    SavingAccount();
    SavingAccount(const string &, const string &, const int &, const double &, const int &);
    // operation
    int interest();
    void setMonths(const unsigned int &);
    void deposit(const unsigned int &);
    void withdraw(const unsigned int &);
    void checkBalance();
private:
    bool settle();
};