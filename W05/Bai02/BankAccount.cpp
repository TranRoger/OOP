#include "BankAccount.h"

// constructor
BankAccount::BankAccount() : _balance(0) {
    cout << "Bank account created." << endl;
}

BankAccount::BankAccount(const string &cccd, const string &fullName, const int &balance) : _cccd(cccd), _fullName(fullName), _balance(balance) {
    cout << "Bank account created." << endl;
}

// operation
void BankAccount::deposit(const unsigned int &money) {
    this->_balance += money;
    cout << "Transaction succeeded. Balance fluctuation: +" << money << " vnd. ";
    checkBalance();
}

void BankAccount::withdraw(const unsigned int &money) {
    if (money > this->_balance) {
        cout << "Transaction failed due to insufficient account balance." << endl;
        return;
    }
    this->_balance -= money;
    cout << "Transaction succeeded. Balance fluctuation: -" << money << " vnd. ";
    checkBalance();
}

void BankAccount::checkBalance() {
    cout << "Your balance: " << _balance << " vnd." << endl;
}