#include "Book.h"
#include <string>
#include <iostream>
using namespace std;

Book::Book() {
	this->author = "";
	this->title = "";
	this->place = "";
	this->publisher = "";
	this->year = 0;
}

Book::Book(string title) :
		Book() {
	this->title = title;
}

Book::Book(string author, string title) :
		Book(title) {
	this->author = author;
}

Book::Book(string title, int year) :
		Book(title) {
	this->year = year;
}

Book::Book(string author, string title, int year) :
		Book(author, title) {
	this->year = year;
}

Book::Book(string author, string title, string place, int year) :
		Book(author, title, year) {
	this->place = place;
}

Book::Book(string author, string title, string place, string publisher,
		int year) :
		Book(author, title, place, year) {
	this->publisher = publisher;
}

Book::Book(const Book &r) {
	this->author = r.author;
	this->title = r.title;
	this->place = r.place;
	this->publisher = r.publisher;
	this->year = r.year;
}

string Book::getAuthor() const {
	return this->author;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::getTitle() const {
	return this->title;
}

void Book::setTitle(string title) {
	this->title = title;
}

string Book::getPlace() const {
	return this->place;
}

void Book::setPlace(string place) {
	this->place = place;
}

string Book::getPublisher() const {
	return this->publisher;
}

void Book::setPublisher(string publisher) {
	this->publisher = publisher;
}

int Book::getYear() const {
	return this->year;
}

void Book::setYear(int year) {
	this->year = year;
}

void Book::show() const {
	if (this->author != "") {
		cout << this->author;
		if (this->author.back() != '.')
			cout << ".";
		cout << " ";
	}
	if (this->title != "") {
		cout << this->title;
		if (this->title.back() != '.')
			cout << ".";
	} else {
		cout << "[No title].";
	}
	cout << " ";
	if (this->place != "") {
		cout << this->place;
		if (this->publisher != "") {
			cout << ": " << this->publisher;
		}
		cout << ", ";
	} else {
		if (this->publisher != "") {
			cout << this->publisher << ", ";
		}
	}
	if (this->year != 0) {
		cout << this->year << ".";
	} else {
		cout << "[s.D].";
	}
	cout << endl;
}

void Book::edit() {
	int c { };
	do {
		show();

		cout << "What would you like to change about this book?" << endl;
		cout << "1. Book author" << endl;
		cout << "2. Book title" << endl;
		cout << "3. Place of publishing" << endl;
		cout << "4. Publisher" << endl;
		cout << "5. Year" << endl;
		cout << "0. Stop editing the book" << endl;
		cin >> c;
		switch (c) {
		case 0:
			break;
		case 1:
			cout << "Enter new author: ";
			cin.ignore();
			getline(cin, this->author);
			break;
		case 2:
			cout << "Enter new title: ";
			cin.ignore();
			getline(cin, this->title);
			break;
		case 3:
			cout << "Enter new place: ";
			cin.ignore();
			getline(cin, this->place);
			break;
		case 4:
			cout << "Enter new publisher: ";
			cin.ignore();
			getline(cin, this->publisher);
			break;
		case 5:
			cout << "Enter new year of publishing: ";
			cin >> year;
			break;
		default:
			cout << "Wrong command!";
		}
	} while (c);
}

string Book::toString() const {
	return "{" + this->getAuthor() + "}{" + this->getTitle() + "}{"
			+ this->getPlace() + "}{" + this->getPublisher() + "}{"
			+ to_string(this->getYear()) + "}\n";
}

bool Book::isEmpty() {
	if (this->author != "")
		return false;
	if (this->title != "")
		return false;
	if (this->place != "")
		return false;
	if (this->publisher != "")
		return false;
	if (this->year != 0)
		return false;
	return true;
}

Book::~Book() {
// TODO Auto-generated destructor stub
}

