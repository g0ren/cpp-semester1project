#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cassert>
#include "Library.h"
#include "Book.h"
using namespace std;

string Library::default_file = "test.txt";

Library::Library() {
	this->books = new Book[1];
	this->capacity = 1;
	this->size = 0;
}

Library::Library(Book b) {
	this->books = new Book[1];
	this->books[0] = b;
	this->capacity = 1;
	this->size = 1;
}

int Library::getSize() const {
	return this->size;
}

int Library::getCapacity() const {
	return this->capacity;
}

void Library::realloc() {
	Book *new_books = new Book[this->capacity * 2];
	for (int i = 0; i < size; i++) {
		new_books[i] = this->books[i];
	}
	delete[] this->books;
	this->books = new_books;
	this->capacity *= 2;
}

void Library::addBook(Book b) {
	if (this->size >= this->capacity - 1)
		this->realloc();
	this->books[size] = b;
	size++;
}

void Library::addBook() {
	Book b;
	b.edit();
	addBook(b);
}

void Library::addBook(int idx) {
	Book b;
	b.edit();
	this->addBook(b, idx);
}

void Library::addBook(Book b, int idx) {
	if (this->size >= this->capacity - 1)
		this->realloc();
	if (idx >= this->size) {
		this->addBook(b);
		return;
	}
	for (int i = this->size; i > idx; i--) {
		this->books[i] = this->books[i - 1];
	}
	this->books[idx] = b;
	this->size++;
}

void Library::deleteBook(int idx) {
	if (idx >= this->size)
		return;

	for (int i = idx; i < this->size; i++)
		this->books[i] = this->books[i + 1];

	this->size--;
}

void Library::deleteAllEmpty() {
	for (int i = 0; i < this->size; i++) {
		if (this->books[i].isEmpty())
			this->deleteBook(i);
	}
}

Book Library::operator[](int n) const {
	assert(n >= 0 && n < this->size && "Out of range!");
	return this->books[n];
}

Book& Library::operator[](int n) {
	assert(n >= 0 && n < this->size && "Out of range!");
	return this->books[n];
}

void Library::print() const {
	size_t w = to_string(this->size - 1).size();
	for (int i = 0; i < this->size; i++) {
		cout << setw(w) << i << " ";
		books[i].show();
	}
}

/*
 * Searching and printing results
 */

void Library::searchByAuthor(string s) const {
	for (int i = 0; i < this->size; i++)
		if (this->books[i].getAuthor().find(s) != string::npos) {
			cout << i << " ";
			this->books[i].show();
		}
}

void Library::searchByTitle(string s) const {
	for (int i = 0; i < this->size; i++)
		if (this->books[i].getTitle().find(s) != string::npos) {
			cout << i << " ";
			this->books[i].show();
		}
}
void Library::searchByPlace(string s) const {
	for (int i = 0; i < this->size; i++)
		if (this->books[i].getPlace().find(s) != string::npos) {
			cout << i << " ";
			this->books[i].show();
		}
}
void Library::searchByPublisher(string s) const {
	for (int i = 0; i < this->size; i++)
		if (this->books[i].getPublisher().find(s) != string::npos) {
			cout << i << " ";
			this->books[i].show();
		}
}

void Library::searchByYear(int y) const {
	for (int i = 0; i < this->size; i++)
		if (this->books[i].getYear() == y) {
			cout << i << " ";
			this->books[i].show();
		}
}

/*
 * Swapping and sorting
 */

void Library::swap(int i, int j) {
	Book t;
	t = this->operator [](i);
	this->operator [](i) = this->operator [](j);
	;
	this->operator [](j) = t;
}

void Library::sortByAuthor() {
	bool sorted { };
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < size; i++) {
			if (this->operator [](i).getAuthor()
					< this->operator [](i - 1).getAuthor()) {
				sorted = false;
				this->swap(i, i - 1);
			}
		}
	}
}

void Library::sortByTitle() {
	bool sorted { };
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < size; i++) {
			if (this->operator [](i).getTitle()
					< this->operator [](i - 1).getTitle()) {
				sorted = false;
				this->swap(i, i - 1);
			}
		}
	}
}

void Library::sortByPlace() {
	bool sorted { };
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < size; i++) {
			if (this->operator [](i).getPlace()
					< this->operator [](i - 1).getPlace()) {
				sorted = false;
				this->swap(i, i - 1);
			}
		}
	}
}

void Library::sortByPublisher() {
	bool sorted { };
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < size; i++) {
			if (this->operator [](i).getPublisher()
					< this->operator [](i - 1).getPublisher()) {
				sorted = false;
				this->swap(i, i - 1);
			}
		}
	}
}

void Library::sortByYear() {
	bool sorted { };
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < size; i++) {
			if (this->operator [](i).getYear()
					< this->operator [](i - 1).getYear()) {
				sorted = false;
				this->swap(i, i - 1);
			}
		}
	}
}

/*
 * Reading from and writing to file
 */

string bracketedPart(string &fullLine) {
	if (fullLine == "")
		return "";
	unsigned first = fullLine.find("{");
	if (first == string::npos)
		return "";
	first++;
	unsigned last = fullLine.find_first_of("}", first);
	if (last == string::npos)
		return "";
	string part = fullLine.substr(first, last - first);
	fullLine = fullLine.substr(last);
	return part;
}

void Library::fromFile(string filename) {
	FILE *input = fopen(filename.c_str(), "r");
	if (input) {
		char *line { };
		size_t len { };
		while (getline(&line, &len, input) != -1) {
			string fullLine = line;
			if (fullLine.find("{") == string::npos)
				continue;
			Book b;
			b.setAuthor(bracketedPart(fullLine));
			b.setTitle(bracketedPart(fullLine));
			b.setPlace(bracketedPart(fullLine));
			b.setPublisher(bracketedPart(fullLine));
			b.setYear(stoi(bracketedPart(fullLine)));
			this->addBook(b);
		}
	} else {
		cout << "Can't open  file " << filename << " for reading!" << endl;
	}
	fclose(input);
}

void Library::toFile(string filename) const {
	FILE *output = fopen(filename.c_str(), "w+");
	if (output) {
		for (int i = 0; i < this->size; i++) {
			string text = this->books[i].toString();
			cout<<text<<endl;
			fwrite(text.c_str(), 1, text.size(), output);
		}
	} else {
		cout << "Can't open  file " << filename << " for writing!" << endl;
	}
	fclose(output);
}

/*
 * Destructor
 */

Library::~Library() {
	if (this->books)
		delete[] this->books;
}

