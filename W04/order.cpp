#include <iostream>
using namespace std;

class base {
private: 
    int a;
public:
    base(int a) {
        this->a = a;
        cout << "Parameterized constructor cua base class." << endl;
    }
};

class derived : public base {
public:
    derived(int a) : base(a) {
        cout << "Parameterized constructor cua derived class." << endl;
    }
};

int main() {
    derived b(1);

    system("pause");
    return 0;
}