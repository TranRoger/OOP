#include "main.h"

int main() {
    int number = DeathLoop();
    cout << endl << "Your number: " << number << endl;

    system("pause");
    return 0;
}

int DeathLoop() {
    string input;
    regex numberPattern("\\d+");
    do {
        cout << "Please enter an integer between 0 and 10: ";
        getline(cin, input);
        if (input.size() == 0) {
            cout << "Input cannot be left blank!" << endl;
            continue;
        }
        if (input.size() > 2) {
            cout << "Number should be between 0 and 10. Your number: " << stoi(input) << endl;
            continue;
        }

        bool match = regex_match(input, numberPattern);
        if (match && stoi(input) > 0) break;
        else {
            cout << "Invalid number format! Your input: " << input << endl;
        }
    } while (true);
    return stoi(input);
}