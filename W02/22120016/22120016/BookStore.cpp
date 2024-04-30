#include "BookStore.h"

// Getter
string BookStore::getName() {
	return name;
}

vector<Book> BookStore::getData() {
	return data;
}

// Ultilities

void BookStore::sortByPrice() { // Selection sort
	for (int i = 0; i < data.size(); i++) {
		int min = i;
		for (int j = i + 1; j < data.size(); j++) {
			if (data[min].getPrice() > data[j].getPrice()) {
				min = j;
			}
			else if (data[min].getPrice() == data[j].getPrice()) {
				if (data[min].getTitle() > data[j].getTitle()) {
					min = j;
				}
			}
		}
		swap(data[i], data[min]);
	}
}

void BookStore::sortByInputDate() { // Selection sort
	for (int i = 0; i < data.size(); i++) {
		int max = i;
		for (int j = i + 1; j < data.size(); j++) {
			if (data[max].getInputDate().compare(data[j].getInputDate()) == -1) {
				max = j;
			}
		}
		swap(data[i], data[max]);
	}
}

int BookStore::checkExisted(string isbn) {
	// Return book index in data if book is in store
	for (int i = 0; i < data.size(); i++) {
		if (isbn == data[i].getISBN()) return i;
	}
	// Return -1 if book is not in store
	return -1;
}

void BookStore::displayCart(vector<Book> cart) {
	cout << setfill(' ');
	cout << setw(5) << left << "No." << "|"
		<< setw(15) << left << "ISBN" << "|"
		<< setw(25) << left << "Title" << "|"
		<< setw(25) << left << "Author" << "|"
		<< setw(8) << left << "Price" << "|"
		<< setw(15) << left << "Quantity" << "|"
		<< setw(15) << left << "Total price" << endl;
	int i = 1;
	double total = 0;
	for (auto iterator = cart.begin(); iterator != cart.end(); iterator++) {
		cout << setw(5) << left << i << "|"
			<< setw(15) << left << iterator->getISBN() << "|"
			<< setw(25) << left << iterator->getTitle() << "|"
			<< setw(25) << left << iterator->getAuthor() << "|"
			<< setw(8) << left << iterator->getPrice() << "|"
			<< setw(15) << left << iterator->getStockLevel() << "|"
			<< setw(15) << left << iterator->getPrice() * iterator->getStockLevel() << endl;
		double price = iterator->getPrice() * iterator->getStockLevel();
		total += price;
		i++;
	}
	cout << endl << "Total: " << total << endl << endl;
}

void BookStore::writeToFile(string fileName, vector<Book> books) {
	// Write array of books down to file
	ofstream writer;
	writer.open(fileName, ios::out);
	if (!writer.good()) {
		cout << "Cannot find file!" << endl;
		return;
	}
	for (auto iterator = books.begin(); iterator != books.end(); iterator++) {
		writer << iterator->getISBN() << "|";
		writer << iterator->getTitle() << "|";
		writer << iterator->getAuthor() << "|";
		writer << iterator->getLanguage() << "|";
		writer << iterator->getPublishedYear() << "|";
		writer << iterator->getPrice() << "|";
		writer << iterator->getStockLevel() << "|";
		writer << iterator->getInputDate().convertToString() << endl;
	}
	writer.close();
}

// Operation
void BookStore::loadData() {
	ifstream file;
	file.open("books_in_store.txt", ios::in);
	if (!file.is_open()) {
		cout << "Cannot open file!" << endl;
		return;
	}
	while (!file.eof() && file.peek() != ifstream::traits_type::eof()) {
		string isbn, title, author, language, publishedYear, price, stockLevel, day, month, year, hour, minute, second;
		getline(file, isbn, '|');
		getline(file, title, '|');
		getline(file, author, '|');
		getline(file, language, '|');
		getline(file, publishedYear, '|');
		getline(file, price, '|');
		getline(file, stockLevel, '|');
		getline(file, day, '/');
		getline(file, month, '/');
		getline(file, year, ' ');
		getline(file, hour, ':');
		getline(file, minute, ':');
		getline(file, second);
		
		DateTime dt(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute), stoi(second));
		Book book(isbn, title, author, language, stoi(publishedYear), stod(price), stoi(stockLevel), dt);

		data.push_back(book);
	}
	file.close();
}

void BookStore::display(vector<Book> data, int k) {
	cout << setfill(' ');
	cout << setw(15) << left << "ISBN" << "|"
		<< setw(25) << left << "Title" << "|"
		<< setw(25) << left << "Author" << "|"
		<< setw(15) << left << "Language" << "|"
		<< setw(15) << left << "Published year" << "|"
		<< setw(8) << left << "Price" << "|"
		<< setw(15) << left << "Stock level" << "|"
		<< setw(20) << left << "Input date" << endl;

	for (int i = 0; i < k; i++) {
		data[i].display();
	}
}

void BookStore::addBook() {
	string isbn;
	do {
		cout << "Book isbn: ";
		getline(cin, isbn);
		if (isbn.size() == 0) cout << "Cannot leave blank!" << endl;
	} while (isbn.size() == 0);
	int i = checkExisted(isbn);
	// If book is already in store, add quantity to stock level and update input date
	if (i != -1) {
		DateTime inputDate;
		string buffer;
		do {
			cout << "Quantity: ";
			getline(cin, buffer);
			if (buffer.size() == 0) cout << "Cannot leave blank." << endl;
		} while (buffer.size() == 0);
		this->data[i].setStockLevel(data[i].getStockLevel() + stoi(buffer));
		this->data[i].setInputDate(inputDate);
		return;
	}
	// If book is not in store, create new book and add to store
	Book book(isbn);
	this->data.push_back(book);
	// Update file
	writeToFile("books_in_store.txt", data);
}

vector<Book> BookStore::cart() {
	string option;
	vector<Book> cart;
	do {
		system("cls");
		cout << "Cart" << endl;
		displayCart(cart);

		// Menu:
		cout << "1. Add book \t\t 2. Remove book \t\t 3. Purchase \t\t 4. Done" << endl;
		do {
			cout << "Select: ";
			getline(cin, option);
		} while (option.size() == 0 && stoi(option) > 4 && stoi(option) < 1);
		// Perform menu choices
		if (stoi(option) == 1) {
			string isbn;
			int index;
			do {
				cout << "ISBN: ";
				getline(cin, isbn);
				index = checkExisted(isbn);
				if (isbn.size() == 0) {
					cout << "Cannot leave blank!" << endl;
					continue;
				}
				if (index == -1) cout << "Book is not in store! Enter again!" << endl;
			} while (index == -1 || isbn.size() == 0);

			// Display found book information
			cout << setw(15) << left << "ISBN" << "|"
				<< setw(25) << left << "Title" << "|"
				<< setw(25) << left << "Author" << "|"
				<< setw(15) << left << "Language" << "|"
				<< setw(15) << left << "Published year" << "|"
				<< setw(8) << left << "Price" << "|"
				<< setw(15) << left << "Stock level" << "|"
				<< setw(20) << left << "Input date" << endl;
			data[index].display();

			// Ask for quantity
			string quantity;
			do {
				cout << "Quantity: ";
				getline(cin, quantity);
				if (quantity.size() == 0) {
					cout << "Cannot leave blank!" << endl;
					continue;
				}
				// Quantity of buying book cannot be larger than stock level
				if (stoi(quantity) > data[index].getStockLevel()) {
					cout << "Quantity cannot be larger than stock level!" << endl;
				}
			} while (quantity.size() == 0 || stoi(quantity) > data[index].getStockLevel());
			Book book = data[index];
			book.setStockLevel(stoi(quantity));
			cart.push_back(book);
			// Remove the quantity of bought books from stock
			data[index].setStockLevel(data[index].getStockLevel() - stoi(quantity));
		}
		else if (stoi(option) == 2) {
			string No;
			do {
				cout << "Remove book No.: ";
				getline(cin, No);
			} while (stoi(No) < 0 && stoi(No) > cart.size());
			int quantity = cart[stoi(No) - 1].getStockLevel();
			string isbn = cart[stoi(No) - 1].getISBN();
			cart.erase(cart.begin() + stoi(No) - 1);
			// Put the removed books on stock
			int index = checkExisted(isbn);
			data[index].setStockLevel(data[index].getStockLevel() + quantity);
		}
		else if (stoi(option) == 3) { // Call the 5 option in MENU
			system("cls");
			writeBill(cart);
			break;
		}
	} while (stoi(option) != 4);
	// Update file
	writeToFile("books_in_store.txt", data);
	return cart;
}

void BookStore::writeBill(vector<Book> &cart) {
	// If cart has no book, do nothing
	if (cart.size() == 0) {
		cout << "Cart has no book!" << endl;
		return;
	}
	string customerName;
	do {
		cout << "Customer name: ";
		getline(cin, customerName);
		if (customerName.size() == 0) cout << "Cannot leave blank!" << endl;
	} while (customerName.size() == 0);
	// Create purchase date at local time
	DateTime purchaseDate;

	// Print bill information
	cout << endl << endl << setw(50) << setfill('*') << "" << endl;
	cout << "Customer name: " << customerName << endl;
	cout << "Payment date: " << purchaseDate.convertToString() << endl;
	cout << "Books: " << endl;
	displayCart(cart);
	cout << setw(50) << setfill('*') << "" << endl << endl;

	// Get all previous bill into vector and write it back below newest bill
	vector<string> names;
	vector<vector<Book>> books;
	vector<DateTime> dates;
	ifstream scanner;
	scanner.open("bills.txt", ios::in);
	if (!scanner.is_open()) {
		cout << "Cannot open file!" << endl;
		return;
	}
	while (!scanner.eof() && scanner.peek() != ifstream::traits_type::eof()) {
		string cName, size, day, month, year, hour, minute, second;
		getline(scanner, cName,'|');
		names.push_back(cName);
		// Purchased date
		getline(scanner, day, '/');
		getline(scanner, month, '/');
		getline(scanner, year, ' ');
		getline(scanner, hour, ':');
		getline(scanner, minute, ':');
		getline(scanner, second, '|');
		DateTime date(stoi(day), stoi(month), stoi(year), stoi(hour), stoi(minute), stoi(second));
		// Number of books
		getline(scanner, size);
		int i = 0;
		vector<Book> list;
		while (i != stoi(size)) {
			string No, isbn, title, quantity;
			getline(scanner, No, '|');
			getline(scanner, isbn, '|');
			getline(scanner, title, '|');
			getline(scanner, quantity);
			Book book(isbn, title, stoi(quantity));
			list.push_back(book);
			i++;
		}
		dates.push_back(date);
		books.push_back(list);
	}
	scanner.close();

	// Write down to file
	ofstream writer;
	writer.open("bills.txt", ios::out);
	writer << customerName << "|" << purchaseDate.convertToString() << "|" << cart.size() << endl;
	int No = 1;
	for (auto iterator = cart.begin(); iterator != cart.end(); iterator++) {
		writer << No << "|" << iterator->getISBN() << "|" << iterator->getTitle() << "|" << iterator->getStockLevel() << endl;
		No++;
	}

	for (int idx = 0; idx < names.size(); idx++) {
		writer << names[idx] << "|" << dates[idx].convertToString() << "|" << books[idx].size() << endl;
		int No = 1;
		for (auto iterator = books[idx].begin(); iterator != books[idx].end(); iterator++) {
			writer << No << "|" << iterator->getISBN() << "|" << iterator->getTitle() << "|" << iterator->getStockLevel() << endl;
			No++;
		}
	}
	writer.close();
	cart.clear();
	cout << "Payment succeeded!" << endl;
}

void BookStore::lowStock(int k) {
	vector<Book> low;
	for (auto iterator = data.begin(); iterator != data.end(); iterator++) {
		if (iterator->getStockLevel() < k) {
			low.push_back(*iterator);
		}
	}
	display(low, low.size());
	writeToFile("low_stock.txt", low);
}