#ifndef LIBRARY_H_
#define LIBRARY_H_
#include "Book.h"

class Library {
	Book *books;
	int size;
	int capacity;
	void realloc();
	void swap(int, int);
public:
	static string default_file;
	Library();
	Library(Book);
	int getSize() const;
	int getCapacity() const;

	void addBook();
	void addBook(Book);
	void addBook(int);
	void addBook(Book, int);

	void deleteBook(int);
	void deleteAllEmpty();

	Book operator[](int) const;
	Book& operator[](int);

	void print() const;
	void toFile(string) const;
	void fromFile(string);

	void searchByAuthor(string) const;
	void searchByTitle(string) const;
	void searchByPlace(string) const;
	void searchByPublisher(string) const;
	void searchByYear(int) const;


	void sortByAuthor();
	void sortByTitle();
	void sortByPlace();
	void sortByPublisher();
	void sortByYear();

	virtual ~Library();
};

#endif /* LIBRARY_H_ */
