#include <iostream>
#include "BankAccount.h"
#include "SavingAccount.h"

using namespace std;

int main() {
    BankAccount atm("1234567890", "TRAN HUNG ANH", 123456);
    atm.checkBalance();
    atm.deposit(500000);
    atm.withdraw(300000);
    cout << endl;
    SavingAccount saving("1234567891", "NGUYEN MINH ANH", 234567, 4.5, 6);
    saving.checkBalance();
    saving.setMonths(3);
    saving.deposit(30000);
    saving.withdraw(10000);
    saving.setMonths(4);
    saving.deposit(500000);
    saving.withdraw(345435);

    return 0;
}