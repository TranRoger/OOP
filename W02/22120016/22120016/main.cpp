#include "BookStore.h"
#include <math.h>

int main() {
	BookStore bookStore("Fahasa");
	bookStore.loadData();
	string option;
	vector<Book> cart;
	// MENU
	do {
		system("cls");
		cout << "MENU" << endl;
		cout << "1. Display books sorted by price." << endl;
		cout << "2. Display top k (default 10) newest books (sorted by input date)." << endl;
		cout << "3. Add book to store." << endl;
		cout << "4. Cart management (add book to cart, remove book from cart)." << endl;
		cout << "5. Purchase." << endl;
		cout << "6. Display low stock books that have stock level under k books(under 50 books by default)." << endl;
		cout << "7. Exit." << endl << endl;
		// Select function
		cout << "Select: ";
		getline(cin, option);
		// Functioning
		system("cls");
		if (stoi(option) == 1) {
			// Sort data by price and then print it to the screen
			bookStore.sortByPrice();
			bookStore.display(bookStore.getData(), bookStore.getData().size());
		}
		else if (stoi(option) == 2) {
			// Sort data by input date and then print it to the screen
			bookStore.sortByInputDate();
			int k = 10;		// Default
			string buffer;
			do {
				cout << "k (press enter to skip) = ";
				getline(cin, buffer);
				// If k > data size, ask to re-enter k
				if (buffer.size() > 0 && (stoi(buffer) > bookStore.getData().size())) {
					cout << "k is larger than number of books in store! Enter again!" << endl;
				}
			} while (buffer.size() > 0 && (stoi(buffer) > bookStore.getData().size()));
			system("cls");
			if (buffer.size() == 0) {
				cout << "TOP " << min(k, (int)bookStore.getData().size()) << " NEWEST BOOK." << endl;
				bookStore.display(bookStore.getData(), min(k, (int)bookStore.getData().size()));
			}
			else {
				cout << "TOP " << buffer << " NEWEST BOOK." << endl;
				bookStore.display(bookStore.getData(), stoi(buffer));
			}
		}
		else if (stoi(option) == 3) {
			bookStore.addBook();
			cout << "Book added successfully!" << endl;
		}
		else if (stoi(option) == 4) {
			cart = bookStore.cart();
		}
		else if (stoi(option) == 5) {
			bookStore.writeBill(cart);
		}
		else if (stoi(option) == 6) {
			int k = 50;
			string buffer;
			cout << "k (press enter to skip) = ";
			getline(cin, buffer);
			system("cls");
			if (buffer.size() == 0) {
				bookStore.lowStock(k);
			}
			else {
				bookStore.lowStock(stoi(buffer));
			}
		}
		else if (stoi(option) == 7) {
			break;
		}
		else {
			cout << "Invalid selection! Enter again!" << endl;
			continue;
		}
		cout << endl << "Press enter to go back to main menu." << endl;
		system("pause");
	} while (stoi(option) != 7);

	return 0;
}