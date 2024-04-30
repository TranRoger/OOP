#pragma once

#include <iostream>
using namespace std;

#include <vector>

enum Color {
    Black = 0,
    LightBlue = 3,
    White = 15
};

class Menu {
private:
    vector<string> _menu;
public:
    Menu();
    void display(int);
};