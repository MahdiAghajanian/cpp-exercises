//Books_List.h

#pragma once
#include "Book_information.h"
using namespace std;
class Books_List {
	Book_information booklist[100];
	int counter = 0;
public:
	void addbook(Book_information _book);
	void print_books();
	int search(char _bookname[]);
	void checkandgive_to_borrow_book(int booknum);
	void return_book(int booknum);
	void findandprint_writerbooks(char writername[]);
	~Books_List();
private:
	void sortfunction(char str[][100], int count);
};
