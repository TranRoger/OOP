#include <iostream>
using namespace std;

#include <conio.h>
#include "Fraction\Fraction.h"
#include "KeyboardProvider\FractionKeyboardProvider.h"
#include "OutputMenu\Menu.h"
#include "Converter\NumberFormat.h"
#include "Converter\FractionToDecimalConverter.h"
#include "Converter\FractionToPercentageConverter.h"

enum Keys : int {
    Arrow = 224,
    Left = 75,
    Right = 77,
    Escape = 27,
    Enter = 13
};

int main() {
    cout << "Enter some fraction." << endl;

    FractionKeyboardProvider scanner;
    Fraction fraction = scanner.next();
    Menu menu;
    int selecting = 0;
    do {
        system("cls");
        menu.display(selecting);
        cout << "Result = ";
        if (selecting == 0) {
            fraction.lowestTerm();
            cout << fraction.toString() << endl;
        }
        else if (selecting == 1) {
            NumberFormat format(" ", ",", 3);
            FractionToDecimalConverter dcm(format);
            cout << dcm.convert(fraction) << endl;
        }
        else {
            NumberFormat format(" ", ",", 1);
            FractionToPercetageConverter pct(format);
            cout << pct.convert(fraction) << endl;
        }
        cout << "Use <- & -> to choose. Esc to Exit. Enter to enter a new fraction." << endl;
        unsigned char key = _getch();

        if (Keys::Arrow == key) {
            unsigned char arrow = _getch();

            switch (arrow)
            {
            case Keys::Left: {
                if (selecting > 0) selecting--;
                break;
            }
            case Keys::Right: {
                if (selecting < 2) selecting++;
                break;
            }
            
            default:
                break;
            }
        }
        else {
            if (Keys::Enter == key) {
                system("cls");
                fraction = scanner.next();
            }
            if (Keys::Escape == key) break;
        }
    } while (true);

    return 0;
}