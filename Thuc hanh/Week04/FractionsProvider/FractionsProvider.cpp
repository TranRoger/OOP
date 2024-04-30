#include <iostream>
using namespace std;

#include "FractionKeyboardProvider.h"
#include "..\Utilities\DynamicArray.h"
#include "..\Utilities\RandomInteger.h"

int main() {
    RandomInteger random;
    int n = random.next(10, 20);
    DynamicArray<Fraction> array;
    cout << "FractionsProvider project" << endl << endl;
    cout << "Please enter " << n << " fractions from the keyboard" << endl;
    FractionKeyboardProvider scanner;
    for (int i = 0; i < n; i++) {
        cout << "Fraction" << i + 1 << ": ";
        array.push(scanner.next().data);
    }
    cout << endl << "All entered fractions: ";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i].toString();
        if (i < array.size() - 1) {
            cout << " , ";
        }
    }
    cout << endl;
    return 0;
}