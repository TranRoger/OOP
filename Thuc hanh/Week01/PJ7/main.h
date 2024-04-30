#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum Color {
    Black = 0,
    LightBlue = 3,
    White = 15
};

enum Keys : int {
    Arrow = 224,
    Up = 72,
    Down = 80,
    Left = 75,
    Right = 77,
    Enter = 13,
    Del = 83
};

void Menu();