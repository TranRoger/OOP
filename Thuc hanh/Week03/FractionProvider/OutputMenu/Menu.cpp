#include <iostream>
using namespace std;

#define WIN32_LEAN_AND_MEAN 

#include <Windows.h>
#include "Menu.h"

Menu::Menu() {
    _menu.resize(3);
    _menu[0] = "Lowest term & mixed";
    _menu[1] = "Decimal";
    _menu[2] = "Percentage";
}

void Menu::display(int choosen) {
    int background = Color::LightBlue;
    int color = background * 16;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    cout << "          ";

    for (int i = 0; i < 3; i++) {
        if (i == choosen) {
            color = Color::White * 16;
        }
        else {
            color = background * 16;
        }
        SetConsoleTextAttribute(hConsole, color);

        cout << _menu[i];
        if (i == choosen) {
            color = background * 16;
            SetConsoleTextAttribute(hConsole, color);
        }
        cout << "          ";
    }
    color = 7 + Color::Black * 16;
    SetConsoleTextAttribute(hConsole, color);
    cout << endl;
}