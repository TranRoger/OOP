#include "main.h"

int main() {
    CurrencyDisplay();

    system("pause");
    return 0;
}

void CurrencyDisplay() {
    string vnd, dollar, exc;
    do {
        cout << "Currency: ";
        getline(cin, vnd);
        if (vnd.size() == 0) {
            cout << "Cannot leave blank." << endl;
            continue;
        }
        cout << "Exchange for 1$: ";
        getline(cin, exc);
        if (vnd.size() == 0) {
            cout << "Cannot leave blank." << endl;
            continue;
        }
        else break;
    } while (true);

    dollar = to_string((double)stoi(vnd) / (double)stoi(exc));

    seperate(vnd);
    seperate(dollar);

    cout << "Vietnam market: " << vnd << " d." << endl;
    cout << "US market: $ " << dollar << endl;
}

void seperate(string &money) {
    int sep = money.find('.');
    if (sep == -1) sep = money.size();
    else {
        money[sep] = ',';
        money.erase(sep + 3);
    }
    for (int i = sep - 3; i > 0; i = i - 3) {
        money.insert(i, ".");
    }
    
}