#include <iostream>
using namespace std;

#include "Line.h"

int main() {
    cout << "Enter a line: " << endl;
    Line line;
    line.input();

    cout << "Line: ";
    line.output();
    cout << endl;

    system("pause");
    return 0;
}