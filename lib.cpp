/*
 Начало эрзаца библиотечного каталога.
 Пишет, читает из файлов, ищет по ключу, сортирует. Можно добавлять, удалять и редактировать книги.
 Пример синтаксиса файла каталога в файле test.txt
 */


#include <iostream>
#include <string>
#include <cstring>
#include "Book.h"
#include "Library.h"
using namespace std;
void menu(Library&);
void searchMenu(Library&);
void sortMenu(Library&);

void searchMenu(Library &lib) {
	while (1) {
		cout << "What do you want to search for?" << endl;
		cout << "1. Author" << endl;
		cout << "2. Title" << endl;
		cout << "3. Place" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Year" << endl;
		cout << "0. Return" << endl;
		int c { };
		cin >> c;
		cout << "Enter search key: ";
		cin.ignore();
		string s;
		getline(cin, s);
		switch (c) {
		case 0:
			return;
		case 1:
			lib.searchByAuthor(s);
			return;
		case 2:
			lib.searchByTitle(s);
			return;
		case 3:
			lib.searchByPlace(s);
			return;
		case 4:
			lib.searchByPublisher(s);
			return;
		case 5:
			lib.searchByYear(stoi(s));
			return;
		default:
			cout << "Wrong command!" << endl;
		}
	}
}

void sortMenu(Library &lib) {
	while (1) {
		cout << "What do you want to sort by?" << endl;
		cout << "1. Author" << endl;
		cout << "2. Title" << endl;
		cout << "3. Place" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Year" << endl;
		cout << "0. Return" << endl;

		int c { };
		cin >> c;
		switch (c) {
		case 0:
			return;
		case 1:
			lib.sortByAuthor();
			return;
		case 2:
			lib.sortByTitle();
			return;
		case 3:
			lib.sortByPlace();
			return;
		case 4:
			lib.sortByPublisher();
			return;
		case 5:
			lib.sortByYear();
			return;
		default:
			cout << "Wrong command!" << endl;
		}
	}
}

void menu(Library &lib) {
	string s;
	int i { };
	while (1) {
		lib.print();
		cout << "What do you want to do?" << endl;
		cout << "1. Add book by index" << endl;
		cout << "2. Edit book by index" << endl;
		cout << "3. Delete book by index" << endl;
		cout << "4. Search library" << endl;
		cout << "5. Sort library" << endl;
		cout << "6. Load library from file" << endl;
		cout << "7. Write library to file" << endl;
		cout << "0. Exit" << endl;

		int c { };
		cin >> c;
		switch (c) {
		case 0:
			return;
		case 1:
			cout << "Enter the index where your new book must be" << endl;
			cin >> i;
			lib.addBook(i);
			break;
		case 2:
			cout << "Enter the index of the book you wish to edit" << endl;
			cin >> i;
			lib[i].edit();
			break;
		case 3:
			cout << "Enter the index of the book you wish to delete" << endl;
			cin >> i;
			lib.deleteBook(i);
			break;
		case 4:
			searchMenu(lib);
			break;
		case 5:
			sortMenu(lib);
			break;
		case 6:
			s = "";
			cout << "Enter the filename you want to load. (Default: "
					<< Library::default_file << ")" << endl;
			cin.ignore();
			getline(cin, s);
			if (s == "") {
				lib.fromFile(Library::default_file);
			} else {
				lib.fromFile(s);
				Library::default_file = s;
			}
			break;
		case 7:
			s = "";
			cout << "Enter the filename you want to write to. (Default: "
					<< Library::default_file << ")" << endl;
			cin.ignore();
			getline(cin, s);
			if (s == "") {
				lib.toFile(Library::default_file);
			} else {
				lib.toFile(s);
				Library::default_file = s;
			}
			break;
		default:
			cout << "Wrong command!" << endl;
		}
	}
}

int main() {
	Library lib;
	//addTestBooks(lib);
	//lib.addBook();
	//lib.print();
	//cout << lib[0].toString();

	//lib.fromFile("test.txt");
	//lib.toFile("text.txt");
	menu(lib);
	//lib.print();
	//cout << lib.getSize() << endl;
	//cout << lib.getCapacity() << endl;
	//lib.deleteBook(4);
	//lib.print();
	//cout << lib.getSize() << endl;
	//cout << lib.getCapacity() << endl;
	/*cout << "----" << endl;
	 lib.searchByAuthor("J.");
	 cout << "----" << endl;
	 lib.searchByTitle("The");
	 cout << "----" << endl;
	 lib.searchByPlace("NY");
	 cout << "----" << endl;
	 lib.searchByYear(2001);
	 cout << "----" << endl;
	 lib.sortByAuthor();
	 lib.print();
	 cout << "----" << endl;
	 lib.sortByYear();
	 lib.print();
	 */
//	lib.addBook(3);
//	lib.print();
//	cout << lib.getSize() << endl;
//	cout << lib.getCapacity() << endl;
//	lib.deleteAllEmpty();
//	lib.print();
//	cout << lib.getSize() << endl;
//	cout << lib.getCapacity() << endl;
//	lib.deleteBook(0);
//	lib.print();
//	cout << lib.getSize() << endl;
//	cout << lib.getCapacity() << endl;
//cout << b.getAuthor()<<". "<< b.getTitle() << endl;
//cout<< b.getAuthor().back()<<endl;
	return 0;
}

