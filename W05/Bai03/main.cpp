#include <iostream>
#include <conio.h>
#include <string>
#include "Random.h"
#include "Class.h"
#include "Student.h"

int main() {
    cout << "--RANDOM STUDENT GENERATOR--" << endl << endl;
    cout << "Class data file name or file path: ";
    string fileName = "Students.csv";
    getline(cin, fileName);
    Class ctt2(fileName);
    Random rand; 
    system("cls");
    
    do {
        cout << "--RANDOM STUDENT GENERATOR--" << endl << endl << "Press Enter to generate random student's id. Esc to exit." << endl << endl;
        Student choosen = rand.next(ctt2);
        cout << "Student's id: " << choosen.getID() << endl;
        if (_getch() != 13) break;
        system("cls");
    } while (ctt2._notOnBoard.size() > 0);
    cout << "Session ended." << endl;
    ctt2.exportToFile(fileName);
    system("pause");
    return 0;
}