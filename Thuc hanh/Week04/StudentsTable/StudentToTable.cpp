#include <iostream>
#include "StudentToTable.h"
using namespace std;

// StudentToTableConverter
StudentsToTableConverter::StudentsToTableConverter() {

}

StudentsToTableConverter::StudentsToTableConverter(vector<string> headers, vector<int> columnSizes) : _headers(headers), _columnSizes(columnSizes) {

}

string StudentsToTableConverter::convert(vector<Student> students) {
    stringstream builder;
    for (int i = 0; i < _headers.size(); i++) {
        builder << "|" << setw(_columnSizes[i]) << right << _headers[i];
    }
    builder << "|";
    int width = builder.str().size();
    builder << endl << setw(width) << setfill('-') << "-" << endl << setfill(' ');
    for (int i = 0; i < students.size(); i++) {
        builder << "|" << setw(_columnSizes[0]) << right << i + 1;
        StudentToRowConverter row(_columnSizes);
        builder << row.convert(students[i]) << endl;
    }
    string result = builder.str();
    return result;
}


// StudentToRowConverter
StudentsToTableConverter::StudentToRowConverter::StudentToRowConverter() {

}

StudentsToTableConverter::StudentToRowConverter::StudentToRowConverter(vector<int> columnSizes) : _columnSizes(columnSizes) {

}

string StudentsToTableConverter::StudentToRowConverter::convert(Student student) {
    stringstream builder;
    builder << "|" << setw(_columnSizes[1]) << right << student._id
            << "|" << setw(_columnSizes[2]) << right << student._fullname
            << "|" << setw(_columnSizes[3]) << right << student._email << "|";
    string result = builder.str();
    return result;
}