#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Book.h"

using namespace std;

class BookStore {
private:
	// Attributes
	string name;
	vector<Book> data;

public:
	// Constructor
	BookStore() {}
	BookStore(string name) {
		this->name = name;
	}

	// Getter
	string getName();
	vector<Book> getData();

	// Operation
	void loadData();
	void display(vector<Book>, int k);
	void addBook();
	vector<Book> cart();
	void writeBill(vector<Book>&); 
	void lowStock(int);

	// Ultilities
	void sortByPrice();
	void sortByInputDate();
	int checkExisted(string);
	void displayCart(vector<Book>);
	void writeToFile(string, vector<Book>);
};