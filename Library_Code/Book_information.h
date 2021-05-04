//Book_information.h

#pragma once
#include "writer_information.h"
using namespace std;
class Book_information {
	char bookname[100];
	writer_information writer;
	int printyear;
	int numberofbook;
public:
	Book_information();
	Book_information(const Book_information& obj2);
	int get_numberofbook();
	void set_information(char _bookname[], writer_information _writer, int _printyear);
	void add_numberofbook();
	void subtract_numberofbook();
	const char* print_book_information();
	const char* get_bookname();
	const char* get_writername();
	~Book_information();
};
