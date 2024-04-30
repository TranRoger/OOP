#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
    int yearModel;
    string make;
    int speed;

    public:
    void input();
    int getYearModel();
    void setYearModel(int s);
    string getMake();
    void setMake(string s);
    int getSpeed();
    void accelerate();
    void brake();
    void output();
};

void Car::input() {
    cout << "Year model: ";
    cin >> this->yearModel;
    cout << "Make: ";
    cin.ignore();
    getline(cin, this->make);
    this->speed = 0;
}

int Car::getYearModel() {
    return this->yearModel;
}

void Car::setYearModel(int s) {
    this->yearModel = s;
}

string Car::getMake() {
    return this->make;
}

void Car::setMake(string s) {
    this->make = s;
}

int Car::getSpeed() {
    return this->speed;
}

void Car::accelerate() {
    this->speed += 5;
}

void Car::brake() {
    this->speed -= 5;
}

void Car::output() {
    cout << "Year model: " << this->yearModel << endl;
    cout << "Make: " << this->make << endl;
    cout << "Speed: " << this->speed << endl;
}

int main() {
    Car car;
    car.input();
    for (int i = 0; i < 5; i++) {
        car.accelerate();
        cout << "Car speed after acceleration: " << car.getSpeed() << endl;
    }

    for (int i = 0; i < 5; i++) {
        car.brake();
        cout << "Car speed after brake: " << car.getSpeed() << endl;
    }

    return 0;
}