#include <iostream>
#include "FractionsText.h"

int main() {
    cout << "Working with fraction arrays from text files" << endl << endl;
    FractionsText::instruction("input.txt");
    cout << endl << "Program is exiting. Press enter to quit..." << endl;
    system("pause");
    return 0;
}
