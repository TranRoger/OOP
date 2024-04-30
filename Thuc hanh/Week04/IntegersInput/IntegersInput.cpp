#include <iostream>
using namespace std;

#include "..\Utilities\RandomInteger.h"
#include "..\Utilities\DynamicArray.h"
#include "..\Utilities\Result.h"
#include "IntegerKeyboardProvider.h"
#include "IntegersInput.h"

int main() {
    RandomInteger random;
    IntegerKeyboardProvider scanner;
    int n = random.next(10, 20);
    DynamicArray<int> array;
    cout << "Please enter " << n << " integers in the range of [20; 100]" << endl;
    int pN = 0;
    DynamicArray<int> primeNumber;
    for (int i = 0; i < n; i++) {
        cout << "Integer " << i + 1 << ": ";
        Result result = scanner.next(20, 100);
        if (false == result.success) {
            cout << "Error code: " << result.errorCode << ". " << result.message << endl;
            i--;
        }
        else {
            array.push(result.data);
            if (isPrime(result.data)) {
                pN++;
                primeNumber.push(result.data);
            }
        }
    }

    cout << endl;
    cout << "Found " << pN << " prime number(s): ";
    for (int i = 0; i < primeNumber.size(); i++) {
        cout << primeNumber[i];
        if (i < primeNumber.size() - 1)
            cout << " , ";
    }

    return 0;
}
