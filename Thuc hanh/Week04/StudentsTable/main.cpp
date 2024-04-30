#include <iostream>
#include "Student.h"
#include "StudentToTable.h"
using namespace std;

int main() {
    auto students = StudentProvider::getAll();

    std::vector<std::string> headers = { "STT", "MSSV", "Ho va ten", "Email" };
    std::vector<int> columnSizes = {3, 4, 20, 20};
    StudentsToTableConverter table(headers, columnSizes);

    auto info = table.convert(students);
    std::cout << info;

    return 0;
}