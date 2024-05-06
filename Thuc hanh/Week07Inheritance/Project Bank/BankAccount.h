#pragma once

#include <iostream>

class BankAccount {
protected:
    std::string _name;
    int _balance;
public:
    std::string name() const { return _name; }
    BankAccount() { _name = ""; _balance = 0; }
    BankAccount(std::string name, int balance) : 
        _name(name), _balance(balance) {}
        
    int withdraw(int amount) {
        if (_balance >= amount) {
					_balance -= amount;
					return amount;
				}
				return 0;
		}
};

auto getAllAccounts() {
    return std::vector<BankAccount> {
			BankAccount("Alice", 60000),
			BankAccount("Bob", 100000),
			BankAccount("Charlie", 100000),
			BankAccount("David", 200000),
			BankAccount("Eve", 300000),
		};
}