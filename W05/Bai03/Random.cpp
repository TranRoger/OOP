#include "Random.h"

// constructor
Random::Random() {

}

// operation
Student Random::next(Class &students) {
    _config.calculate(students); // calculate rate
    // initiate random source
    random_device rd;
    mt19937 gen(rd());

    // create a vector store ratio for event
    vector<int> weight;
    for (auto r : _config.getRate()) {
        weight.push_back(r.second);
    }

    // create a discrete distribution base on weight
    discrete_distribution dist(weight.begin(), weight.end());

    int choosenCount = _config.getRate()[dist(gen)].first; // random a count number to choose student group
    vector<Student> group = getGroup(students._notOnBoard, choosenCount);

    srand(_config.getSeed());
    int index = rand(); index %= group.size(); // use rand() to random a student in choosen group
    Student choosen = group[index]; 
    students.updateStudent(choosen.getID()); // update choosen student status
    
    return choosen;
}

vector<Student> Random::getGroup(const vector<Student> &callList, const int &count) { // create a group of student whose similar counts
    vector<Student> result;
    for (auto s : callList) {
        if (s.getCount() == count) {
            result.push_back(s);
        }
    }
    return result;
}