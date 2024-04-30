#include "Book.h"

// Getter
string Book::getISBN() {
	return isbn;
}

string Book::getTitle() {
	return title;
}

string Book::getAuthor() {
	return author;
}

string Book::getLanguage() {
	return language;
}

int Book::getPublishedYear() {
	return publishedYear;
}

double Book::getPrice() {
	return price;
}

int Book::getStockLevel() {
	return stockLevel;
}

DateTime Book::getInputDate() {
	return inputDate;
}

// Setter
void Book::setStockLevel(int stockLevel) {
	this->stockLevel = stockLevel;
}

void Book::setInputDate(DateTime inputDate) {
	this->inputDate = inputDate;
}

// Operation
void Book::display() {
	cout << setw(15) << left << isbn << "|"
		<< setw(25) << left << title << "|"
		<< setw(25) << left << author << "|"
		<< setw(15) << left << language << "|"
		<< setw(15) << left << publishedYear << "|"
		<< setw(8) << left << price << "|"
		<< setw(15) << left << stockLevel << "|"
		<< setw(20) << left << inputDate.convertToString() << endl;
}