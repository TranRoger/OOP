#include <iostream>
#include <string>
#include "Random.h"
#include "Class.h"
#include "Student.h"

int main() {
    bool byConfig, callOnce;
    cout << "--RANDOM STUDENT GENERATOR--" << endl << endl;
    cout << "Class data file name or file path: ";
    string fileName;
    getline(cin, fileName);
    Class ctt2(fileName);
    system("clear");
    do {
        cout << "Random by: 1. config.txt\t2. built-in formula\tType 1 or 2 to choose" << endl;
        int opt;
        cin >> opt;
        if (1 == opt) {
            byConfig = true;
            break;
        }
        else if (2 == opt) {
            byConfig = false;
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    } while (true);
    system("clear");
    do {
        cout << "How many times is a student called in a session? 1. once\t2. no limit\tType 1 or 2 to choose" << endl;
        int opt;
        cin >> opt;
        if (1 == opt) {
            callOnce = true;
            break;
        }
        else if (2 == opt) {
            callOnce = false;
            break;
        }
        else {
            cout << "Invalid input!" << endl;
        }
    } while (true);
    system("clear");
    Random rand(byConfig, callOnce);
    do {
        cout << "--RANDOM STUDENT GENERATOR--" << endl << endl << "Press Enter to generate random student's id. Esc to exit." << endl << endl;
        Student choosen = rand.next(ctt2);
        cout << "Student's id: " << choosen.getID() << endl;
        if (10 != getchar()) break;
        system("clear");
    } while (ctt2._notOnBoard.size() > 0);
    cout << "Session ended." << endl;
    ctt2.exportToFile(fileName);
    return 0;
}