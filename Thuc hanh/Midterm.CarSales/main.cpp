#include <iostream>
#include <vector>
#include <string>
#include "CarSalesProvider.h"
#include "CarToTableConverter.h"
#include "Car.h"
#include "SortBySellingPrice.h"

using namespace std;

int main() {
    cout << "Phan tich du lieu ban xe hoi 2024" << endl << endl << "Top 10 xe ban chay nhat" << endl << endl;

    vector<Car> carSales = CarSalesProvider::read("CarSales2024.min.csv");
    SortBySellingPrice::sort(carSales);
    vector<string> header = {"STT", "Dong xe", "Gia"};
    vector<int> columnSize = {3, 45, 11};
    CarToTableConverter converter(header, columnSize, 10);
    cout << converter.convert(carSales);

    system("pause");
    return 0;
}