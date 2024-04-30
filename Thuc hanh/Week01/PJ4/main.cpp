#include "main.h"

int main() {
    RandomIntegers();

    return 0;
}

bool isPrime(int number) {
    if (number < 2) return false;
    else if (number == 2) return true;
    for (int i = 2; i < sqrt(number); i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void RandomIntegers() {
    srand(time(NULL));
    int number;
    do {
        number = rand();
    } while (number < 10 || number > 20);
    cout << "Random number: " << number << endl;

    cout << "Array size: ";
    int n, even = 0;
    cin >> n;
    cout << "Random array: ";
    vector<int> array(n, -1); 
    for (int i = 0; i < n; i++) {
        while (array[i] < 1 || array[i] > 100) {
            array[i] = rand();
        }
        if (array[i] % 2 == 0) even++;
        cout << array[i] << " , ";
    }
    cout << endl;
    cout << "There are/is " << even << " even number(s) and " << n - even << " odd number(s) in the array." << endl;
    
    cout << "Prime number in array: ";
    for (int i = 0; i < n; i++) {
        if (isPrime(array[i])) {
            cout << array[i] << " , ";
        }
    }

    cout << endl;
}