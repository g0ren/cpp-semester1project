#ifndef BOOK_H_
#define BOOK_H_
#include <string>
using namespace std;

class Book {
	string author;
	string title;
	string place;
	string publisher;
	int year;
public:
	Book();
	Book(string);
	Book(string,string);
	Book(string,int);
	Book(string, string, int);
	Book(string, string, string, int);
	Book(string, string, string,string, int);
	Book(const Book &r);
	virtual ~Book();
	string getAuthor() const;
	void setAuthor(string);
	string getTitle() const;
	void setTitle(string);
	string getPlace() const;
	void setPlace(string);
	string getPublisher() const;
	void setPublisher(string);
	int getYear() const;
	void setYear(int);

	string toString() const;
	void show() const;
	void edit();
	bool isEmpty();
};

#endif /* BOOK_H_ */
