#include <iostream>
using namespace std;

#include "Student.h"

int main() {
    cout << "Enter student." << endl;
    Student student;
    student.input();
    system("cls");
    cout << "Student information:" << endl;
    student.output();

    system("pause");
    return 0;
}