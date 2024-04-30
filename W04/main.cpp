#include <iostream>
#include <string.h>
using namespace std;

#include "MyString.h"

int main() {
    MyString a, b;
    cout << "String a. ";
    a.input();
    cout << "String b. ";
    b.input();
    cout << a << endl << b << endl;
    if (a == b) {
        cout << a << " giong " << b << endl;
    }
    else {
        cout << a << " khac " << b << endl;
    }

    cout << a << " += " << b << " -> a = ";
    a += b;
    cout << a << endl;

    cout << a << " = " << b << " -> a = ";
    a = b;
    cout << a << endl;
    system("pause");
    return 0;
}