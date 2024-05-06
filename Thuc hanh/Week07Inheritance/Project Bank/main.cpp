#include <iostream>
#include <vector>
#include <format> // Requires C++20
#include "BankAccount.h"
#include "BankAccountV2.h"

int main() {
    auto accounts = getAllAccounts();

    for (auto& account : accounts) {
        std::cout << std::format("{} can withdraw {} \n",
            account.name(),
            account.withdraw(70000));;
	}

    std::cout << std::endl;
    auto accountsV2 = getAllAccountsV2();
    for (auto &account : accountsV2) {
        std::cout << std::format("{} can withdraw {} \n",
            account.name(),
            account.withdraw(70000));;
    }
}