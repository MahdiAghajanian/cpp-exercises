//Librarys_Information.h

#pragma once
#include "Books_List.h"
using namespace std;
class Librarys_Information {
	char libraryname[100];
	char address[100];
	int establishedyear;
	int numofemployers;
	float starttime;
	float endtime;
	Books_List booklists;
public:
	void set(char _libraryname[], char _addressint[], int _establishedyear, int _numofemployers, float _starttime, float _endtime, Books_List _booklists);
	void add_book_to_list(Book_information _book);
	int search_book_from_list(char _book[]);
	void checkandgive_to_borrow(char _book[]);
	void checkandget_book(char _book[]);
	void print_books_information();
	void print_library_name();
	void find_writer(char writername[]);
	float get_starttime();
	float get_endtime();
	Librarys_Information();
	~Librarys_Information();
};
