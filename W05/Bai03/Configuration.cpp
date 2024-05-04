#include "Configuration.h"

// constructor
Configuration::Configuration() {
    _rate.resize(0);
    loadConfig();
}

// accessor
vector<pair<int, int>> Configuration::getRate() {
    return _rate;
}

vector<pair<int, int>> Configuration::getConfig() {
    return _configRate;
}

// operation
void Configuration::loadConfig() { // get config data
    ifstream fin;
    fin.open("config.txt", ios::in);
    if (!fin.good()) { // if file cannot be opened, throw error
        throw runtime_error("File not found.");
        return;
    }
    while (!fin.eof()) {
        string a, b;
        getline(fin, a, '=');
        getline(fin, b);
        pair<int, int> r(stoi(a), stoi(b));
        _configRate.push_back(r);
    }
    fin.close();
}

bool Configuration::find(const int &value) { // check if count is already in vector
    for (auto r : _rate) {
        if (value == r.first) return true;
    }
    return false;
}

void Configuration::sort(const int &low, const int &high) { // use quick sort to sort counts in ascending order
    if (low < high) {
        // Partition the array by setting the position of the pivot element
        int pivot = _rate[high].first;
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (_rate[j].first < pivot) {
                i++;
                swap(_rate[i], _rate[j]);
            }
        }
        swap(_rate[i + 1], _rate[high]);

        // Position partitioned correctly
        int pi = i + 1;

        // Sort the elements before and after partition
        sort(low, pi - 1);
        sort(pi + 1, high);
    }
}

void Configuration::calculate(Class &students) { // calculate the rate for each count
    _rate.erase(_rate.begin(), _rate.end());
    for (auto iterator = students._notOnBoard.begin(); iterator != students._notOnBoard.end(); iterator++) {
        // delete students whose count > maxCount from the calling list
        if (iterator->getCount() > _maxCount) {
            students._notOnBoard.erase(iterator);
        }
        else { // add student's count to the rate list to calculate
            if (!find(iterator->getCount())) { // if student's count is not already in list, add in
                pair<int, int> p(iterator->getCount(), 100); // now every count has 100% rate
                _rate.push_back(p);
            }
        }
    }
    // sort the count list in ascending order
    sort(0, _rate.size() - 1);
    // calculate rate for each count
    int sub = 100 / (_rate.size() + 1);
    int i = 1;
    for (auto &r : _rate) {
        r.second -= sub * i; // the rate will decrease as count increase
        i++;
    }
}