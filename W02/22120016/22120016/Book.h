#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "DateTime.h"

using namespace std;

class Book {
private:
	string isbn;
	string title;
	string author;
	string language;
	int publishedYear;
	double price;
	int stockLevel;
	DateTime inputDate;

public:
	// Constructor
	Book() {}

	Book(string isbn) {
		this->isbn = isbn;
		do {
			cout << "Book title: ";
			getline(cin, this->title);
			if (this->title.size() == 0) cout << "Cannot leave blank!" << endl;
		} while (this->title.size() == 0);
		do {
			cout << "Book author: ";
			getline(cin, this->author);
			if (this->author.size() == 0) cout << "Cannot leave blank!" << endl;
		} while (this->author.size() == 0);
		do {
			cout << "Book language: ";
			getline(cin, this->language);
			if (this->language.size() == 0) cout << "Cannot leave blank!" << endl;
		} while (this->language.size() == 0);
		string buffer;
		do {
			cout << "Book published year: ";
			getline(cin, buffer);
			if (buffer.size() == 0) cout << "Cannot leave blank!" << endl;
		} while (buffer.size() == 0);
		this->publishedYear = stoi(buffer);
		buffer.clear();
		do {
			cout << "Book price: ";
			getline(cin, buffer);
			if (buffer.size() == 0) cout << "Cannot leave blank!" << endl;
		} while (buffer.size() == 0);
		this->price = stod(buffer);
		buffer.clear();
		do {
			cout << "Stock level: ";
			getline(cin, buffer);
			if (buffer.size() == 0) cout << "Cannot leave blank!" << endl;
		} while (buffer.size() == 0);
		this->stockLevel = stoi(buffer);
		DateTime inputDate;
		this->inputDate = inputDate;
	}

	Book(string isbn, string title, int stockLevel) {
		this->isbn = isbn;
		this->title = title;
		this->stockLevel = stockLevel;
	}

	Book(string isbn, string name, string author, string language, int publishedYear, double price, int stockLevel, DateTime inputDate) {
		this->isbn = isbn;
		this->title = name;
		this->author = author;
		this->language = language;
		this->publishedYear = publishedYear;
		this->price = price;
		this->stockLevel = stockLevel;
		this->inputDate = inputDate;
	}

	// Getter
	string getISBN();
	string getTitle();
	string getAuthor();
	string getLanguage();
	int getPublishedYear();
	double getPrice();
	int getStockLevel();
	DateTime getInputDate();

	// Setter
	void setStockLevel(int);
	void setInputDate(DateTime);

	// Operation
	void display();
};