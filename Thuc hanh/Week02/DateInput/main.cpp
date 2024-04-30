#include <iostream>
using namespace std;

#include "Date.h"

int main() {    
    cout << "Enter date." << endl;
    Date date;
    date.input();

    cout << "Date: ";
    date.output();
    cout << endl;

    system("pause");
    return 0;
}