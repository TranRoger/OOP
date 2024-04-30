#include <iostream>
#include "Student.h"

using namespace std;

// Student
Student::Student() {

}

Student::Student(string id, string fullname, string email) : _id(id), _fullname(fullname), _email(email) {
    
}

// StudentProvider
std::vector<Student> StudentProvider::getAll() {
    return {
        Student("001", "Nguyen Van Minh", "nvminh@gmail.com"),
        Student("002", "Cao Ha Thang", "chthang@gmail.com"),
        Student("003", "Tran Duc Tri", "tdtri@gmail.com")
    };
}