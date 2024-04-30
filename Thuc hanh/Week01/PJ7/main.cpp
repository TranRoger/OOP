#include "main.h"

int main() {
    Menu();

    system("pause");
    return 0;
}

void Menu() {
    int option = 1;

    int text = Color::Black;
    int background = Color::White; 
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do {
        int color = background * 16;
        SetConsoleTextAttribute(hConsole, color / 16);
        cout << "1. Categories." << endl;
        SetConsoleTextAttribute(hConsole, color);
        cout << "2. Products." << endl;
        SetConsoleTextAttribute(hConsole, color);
        cout << "3. Order." << endl;
        SetConsoleTextAttribute(hConsole, color);
        cout << "4. Reports." << endl;
        SetConsoleTextAttribute(hConsole, color);
        cout << "5. Quit." << endl;
        break;
    } while (true);
}