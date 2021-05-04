//Librarys_Information.cpp

#include "Librarys_Information.h"
void Librarys_Information::set(char _libraryname[], char _addressint[], int _establishedyear, int _numofemployers, float _starttime, float _endtime, Books_List _booklists) {
	strcpy(libraryname, _libraryname);
	strcpy(address, _addressint);
	establishedyear = _establishedyear;
	numofemployers = _numofemployers;
	starttime = _starttime;
	endtime = _endtime;
	booklists = _booklists;
}
void Librarys_Information::add_book_to_list(Book_information _book) {
	booklists.addbook(_book);
}
int Librarys_Information::search_book_from_list(char _book[]) {
	return booklists.search(_book);
}
void Librarys_Information::checkandgive_to_borrow(char _book[]) {
	booklists.checkandgive_to_borrow_book(booklists.search(_book) - 1);
}
void Librarys_Information::checkandget_book(char _book[]) {
	booklists.return_book(booklists.search(_book) - 1);
}
void Librarys_Information::print_books_information() {
	booklists.print_books();
}
void Librarys_Information::print_library_name() {
	cout << libraryname << endl;
}
void Librarys_Information::find_writer(char writername[]) {
	booklists.findandprint_writerbooks(writername);
}
float Librarys_Information::get_starttime() { return starttime; }
float Librarys_Information::get_endtime() { return endtime; }
Librarys_Information::Librarys_Information() {
	libraryname[0] = '\0';
	address[100] = '\0';
	establishedyear = 0;
	numofemployers = 0;
	starttime = 0;
	endtime = 0;
}
Librarys_Information::~Librarys_Information() {

}
