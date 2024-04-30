#include <iostream>
using namespace std;

#include "Point.h"

int main() {
    cout << "Enter a 2d point." << endl;
    
    Point point;
    point.input();

    cout << "Entered 2d point: ";
    point.output();
    cout << endl;

    system("pause");
    return 0;
}