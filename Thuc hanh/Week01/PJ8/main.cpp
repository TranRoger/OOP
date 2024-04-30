#include "main.h"

int main() {
    FractionToDouble();
    system("pause");
    return 0;
}

void FractionToDouble() {
    string input;
    regex fractionPattern("\\d+/\\d+");
    do {
        getline(cin, input);
        if (input.size() == 0) {
            cout << "Cannot leave blank." << endl;
            continue;
        } 
        bool match = regex_match(input, fractionPattern);
        if (!match) {
            cout << "Wrong input." << endl;
        }
        else break;
    } while (true);

    string num, denum;
    int sep = input.find('/');
    num = input.substr(0, sep);
    denum = input.substr(sep + 1, input.size() - sep);

	if (stoi(denum) != 0)
	{
		float res = 1.0 * stoi(num) / stoi(denum);
		cout << fixed << setprecision(2) << res << endl;
	}
	else
	{
		cout << "Fraction invalid!" << endl;
	}

}