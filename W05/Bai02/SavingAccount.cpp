#include "SavingAccount.h"

// constructor
SavingAccount::SavingAccount() : _interestRate(0) {
    cout << "Saving account created." << endl;
}

SavingAccount::SavingAccount(const string &cccd, const string &fullName, const int &balance, const double &interestRate, const int &term) : BankAccount(cccd, fullName, balance), _interestRate(interestRate), _term(term), _monthsOfDeposit(0) {
    cout << "Saving account created." << endl;
}

// operation
int SavingAccount::interest() {
    return _balance * (_interestRate / 12) * _monthsOfDeposit;
}

void SavingAccount::setMonths(const unsigned int &months) {
    this->_monthsOfDeposit += months;
    cout << "Months of deposit updated." << endl;
}

void SavingAccount::deposit(const unsigned int &money) {
    if (false == settle()) {
        cout << "Transaction failed due to not reaching the term." << endl;
        return;
    } 
    BankAccount::deposit(money);
}

void SavingAccount::withdraw(const unsigned int &money) {
    if (false == settle()) {
        cout << "Transaction failed due to not reaching the term." << endl;
        return;
    }
    BankAccount::withdraw(money);
}

void SavingAccount::checkBalance() {
    settle();
    BankAccount::checkBalance();
}

bool SavingAccount::settle() {
    // if months before term does not reach term return false
    if (_monthsOfDeposit < _term) {
        return false;
    }
    // else top up the money and return true
    _balance += interest();
    return true;
}