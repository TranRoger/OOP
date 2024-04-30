#include <iostream>
#include "IntegerText.h"

using namespace std;

int main() {
    IntegerText progress;
    progress.instruction("input.txt");
    cout << endl << "Program is exiting. Press enter to quit...";
    system("pause");
    return 0;
}