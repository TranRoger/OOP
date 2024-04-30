#include "pj2.h"

int main() {
    if (WrongPassword("162534Hh")) {
        cout << "Logged in!" << endl;
        system("pause");
        system("cls");
        cout << "Hello World!" << endl;
    }

    system("pause");
    return 0;
}

bool WrongPassword(string check) {
    int count = 3;
    while (count) {
        cout << "Password: ";
        string password;
        getline(cin, password);
        if (password.size() == 0) {
            cout << "Input cannot be left blank!" << endl;
        } else if (password != check) {
            count--;
            cout << "Wrong password! You have " << count << " try/tries left." << endl;
        } else return true;
    }
    cout << "You have enter wrong password 3 times. This program will be closed." << endl;
    return false;
}