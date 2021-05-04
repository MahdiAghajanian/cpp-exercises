//Book_information.cpp

#include "Book_information.h"
Book_information::Book_information() {
	printyear = 0;
	numberofbook = 0;
	bookname[0] = '\0';
}
Book_information::Book_information(const Book_information& obj2) {
	numberofbook = obj2.numberofbook;
	strcpy(bookname, obj2.bookname);
	printyear = obj2.printyear;
	writer = obj2.writer;
}
int Book_information::get_numberofbook() { return numberofbook; }
void Book_information::set_information(char _bookname[], writer_information _writer, int _printyear) {
	strcpy(bookname, _bookname);
	writer = _writer;
	printyear = _printyear;
	numberofbook++;
}
void Book_information::add_numberofbook() {
	numberofbook++;
}
void Book_information::subtract_numberofbook() {
	numberofbook--;
}
const char* Book_information::print_book_information() {

	char bookinf[100];
	char writerinf[100];
	strcpy(writerinf, writer.print_writer_information());
	sprintf(bookinf, "%s %d %s", bookname, printyear, writerinf);
	return bookinf;
}
const char* Book_information::get_bookname() { return bookname; }
const char* Book_information::get_writername() { return writer.get_writer_name(); }
Book_information::~Book_information() {

}
