#include <iostream>
using namespace std;

#include "Product.h"

int main() {
    cout << "Enter product:" << endl;
    Product product;
    product.input();
    system("cls");
    cout << "Product information: " << endl;
    product.output();

    system("pause");
    return 0;
}