//Books_List.cpp

#include "Books_List.h"
void Books_List::addbook(Book_information _book) {
	int num = search((char*)_book.get_bookname());
	if (num == 0) {
		counter++;
		booklist[counter - 1] = _book;
	}
	else
		booklist[num - 1].add_numberofbook();
}
void Books_List::print_books() {
	char bookinf[100][100];
	for (int i = 0; i < counter; i++) {
		strcpy(bookinf[i], (booklist[i]).print_book_information());
	}
	sortfunction(bookinf, counter);
	for (int i = 0; i < counter; i++) {
		cout << bookinf[i] << endl;
	}
}
int Books_List::search(char _bookname[]) {
	bool flag = false;
	int i = 0;
	for (i = 0; i < counter; i++) {
		if (strcmp(_bookname, booklist[i].get_bookname()) == 0) {
			flag = true;
			break;
		}
	}
	if (flag)
		return i + 1;
	else
		return 0;
}
void Books_List::checkandgive_to_borrow_book(int booknum) {
	if (booklist[booknum].get_numberofbook() == 0)
		cout << "Sorry! this book was borrowed before" << endl;
	else {
		cout << "this book is borrowed to you.please return it in a month" << endl;
		booklist[booknum].subtract_numberofbook();
	}
}
void Books_List::return_book(int booknum) {
	booklist[booknum].add_numberofbook();
	cout << "thank you for bring it back" << endl;
}
void Books_List::findandprint_writerbooks(char writername[]) {
	char bookname[100][100];
	bool flag = false;
	int j = 0;
	for (int i = 0; i < counter; i++) {
		if (strcmp(booklist[i].get_writername(), writername) == 0) {
			strcpy(bookname[j], booklist[i].get_bookname());
			j++;
			flag = true;
		}
	}
	if (flag) {
		sortfunction(bookname, j);
		for (int i = 0; i < j; i++) {
			cout << bookname[i] << endl;
		}
	}
	else
		cout << "no books in this library writed by this writer!" << endl;
}
Books_List::~Books_List() {
	for (int i = 0; i < counter; i++)
		(booklist[i]).~Book_information();
}
void Books_List::sortfunction(char str[][100], int count) {
	char temp[100];
	for (int i = 0; i <= count; i++)
		for (int j = i + 1; j <= count; j++) {
			if (strcmp(str[i], str[j]) > 0) {
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
}
