#include "Class.h"

// constructor
Class::Class() {
    _notOnBoard.resize(0);
    _students.resize(0);
}

Class::Class(const string &fileName) {
    _notOnBoard.resize(0);
    _students.resize(0);
    importFromFile(fileName);
    _notOnBoard = _students;
}

// destructor
Class::~Class() {
    _notOnBoard.resize(0);
    _students.resize(0);
}

// accessor
int Class::getSize() {
    return _students.size();
}

Student Class::getStudent(const int &index) {
    return _students[index];
}

void Class::updateStudent(const string &id) {
    for (auto &s : _students) { // add 1 count to student
        if (s.getID() == id) {
            s.addCount();
            break;
        }
    }
    for (auto i = _notOnBoard.begin(); i != _notOnBoard.end(); i++) { // delete student from call list
        if (i->getID() == id) {
            _notOnBoard.erase(i);
            break;
        }
    }
}

// operation
void Class::importFromFile(const string &fileName) { // import student information from csv file to instance
    ifstream fin;
    fin.open(fileName, ios::in);
    if (!fin.good()) { // if file cannot be opened, throw error
        throw runtime_error("File not found.");
        return;
    }
    while (!fin.eof()) {
        string id, count;
        getline(fin, id, ',');
        getline(fin, count);
        if (0 == id.size() || 0 == count.size()) {
            cout << "Invalid data in file " << fileName << endl;
            return; 
        }
        _students.push_back(Student(id, stoi(count)));
    }
    fin.close();
}

void Class::exportToFile(const string &fileName) { // update the csv file when program terminated
    ofstream fout;
    fout.open(fileName, ios::out);
    if (!fout.good()) { // if file cannot be opened, throw error 
        throw runtime_error("File not found.");
        return;
    }
    for (auto iterator = _students.begin(); iterator != _students.end(); iterator++) {
        fout << iterator->getID() << "," << iterator->getCount();
        if (iterator != _students.end() - 1) {
            fout << endl;
        }
    }
    fout.close();
}