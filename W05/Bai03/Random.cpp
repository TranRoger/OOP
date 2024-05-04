#include "Random.h"

// constructor
Random::Random(bool byConfig, bool callOnce) : _byConfig(byConfig), _callOnce(callOnce) {

}

// operation
Student Random::next(Class &students) {
    _config.calculate(students); // calculate rate
    _config.loadConfig();
    // initiate random source
    random_device rd;
    mt19937 gen(rd());

    vector<pair<int, int>> rates;
    if (_byConfig) {
        rates = _config.getConfig();
    }
    else {
        rates = _config.getRate();
    }

    // create a vector store ratio for event
    vector<int> weight;
    for (auto r : rates) {
        weight.push_back(r.second);
    }

    // create a discrete distribution base on weight
    discrete_distribution dist(weight.begin(), weight.end());
    vector<Student> group;
    do {
        int choosenCount = rates[dist(gen)].first; // random a count number to choose student group
        group = getGroup(students._notOnBoard, choosenCount);
    } while (0 == group.size());
    srand(time(NULL));
    int index = rand(); index %= group.size(); // use rand() to random a student in choosen group
    Student choosen = group[index]; 
    if (_callOnce)
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