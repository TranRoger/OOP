#pragma once

#include <iostream>
#include <vector>
#include "BankAccount.h"

class BankAccountV2 : private BankAccount{
private:
    int _constraint;
public:
    std::string name() { return BankAccount::name(); }
    BankAccountV2() :
        _constraint(50000) {}
    BankAccountV2(std::string name, int balance) : 
        BankAccount(name, balance), _constraint(50000) {}

    int withdraw(int amount) {
        if (_balance < amount) return 0;
        else if (_balance - amount < _constraint) return 0;

        _balance -= amount;
        return amount;
    }
};

auto getAllAccountsV2() {
    return std::vector<BankAccountV2> {
			BankAccountV2("Alice", 60000),
			BankAccountV2("Bob", 100000),
			BankAccountV2("Charlie", 100000),
			BankAccountV2("David", 200000),
			BankAccountV2("Eve", 300000),
		};
}