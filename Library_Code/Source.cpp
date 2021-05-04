//Source.cpp

#pragma warning(disable: 4996)
#include "Librarys_Information.h"
using namespace std;
void add_library();
void menu();
void print_library_list();
Books_List add_books_list();
Book_information add_books();
void input(Librarys_Information library);
void print_booksinf(Librarys_Information library);
void library_menu(Librarys_Information library);
int main() {
	FILE* file_obj;
	file_obj = fopen("Input2.txt", "w");
	fclose(file_obj);
	menu();

}
void menu() {
	system("cls");
	int num = 0;
	cout << "		1.add library" << endl;
	cout << "		2.open a library" << endl;
	cout << "		0.exit" << endl;
	cin >> num;
	switch (num)
	{
	case 0:exit(0);
	case 1:add_library();
	case 2:print_library_list();
	default: {cout << "ERROR" << endl; menu(); }
	}
}
void print_library_list() {
	system("cls");
	int counter = 0;
	Librarys_Information library;
	ifstream file_obj;
	file_obj.open("Input2.txt", ios::in | ios::binary);
	file_obj.read((char*)&library, sizeof(library));
	cout << "which library do you want to open?" << endl;;
	for (counter = 1; (!file_obj.eof()); counter++) {
		cout << counter << ". ";
		library.print_library_name();
		file_obj.read((char*)&library, sizeof(library));
	}
	file_obj.close();
	file_obj.open("Input2.txt", ios::in | ios::binary);
	file_obj.read((char*)&library, sizeof(library));
	int num = 0;
	cin >> num;
	for (int i = 1; i <= counter; i++) {
		if (i == num) {
			file_obj.close();
			library_menu(library);
		}
		file_obj.read((char*)&library, sizeof(library));
	}
}
void library_menu(Librarys_Information library) {
	system("cls");
	int num = 0;
	cout << "1.add book to the library\n2.Checking book inventory\n3.Borrow a book\n4.Return a book\n5.print list of all books in this library"
		"	\n6.print list of  a writer's books\n7.library situation ( open or close)\n8.back to menu\n0.exit" << endl;
	cin >> num;
	switch (num)
	{
	case 1: {
		system("cls");
		library.add_book_to_list(add_books());
		Sleep(2000);
		library_menu(library);
	}
	case 2: {
		system("cls");
		char bookname[100];
		cout << "what is the book name?" << endl;
		cin >> bookname;
		if ((library.search_book_from_list(bookname)) == 0)
			cout << "this book does not exist" << endl;
		else
			cout << "this book exist" << endl;
		Sleep(2000);
		library_menu(library);
	}
	case 3: {
		system("cls");
		char bookname[100];
		cout << "what is the book name?" << endl;
		cin >> bookname;
		if ((library.search_book_from_list(bookname)) == 0)
			cout << "this book does not exist" << endl;
		else {
			library.checkandgive_to_borrow(bookname);
		}
		Sleep(2000);
		library_menu(library);
	}
	case 4: {
		system("cls");
		char bookname[100];
		cout << "what is the book name?" << endl;
		cin >> bookname;
		if ((library.search_book_from_list(bookname)) == 0)
			cout << "this book does not belong this library" << endl;
		else {
			library.checkandget_book(bookname);
		}
		Sleep(2000);
		library_menu(library);
	}
	case 5: {print_booksinf(library); }
	case 6: {
		system("cls");
		char writername[100];
		cout << "what is the writer's name?" << endl;
		cin >> writername;
		library.find_writer(writername);
		int num = 0;
		cout << "1.back to menu\n0.exit" << endl;
		cin >> num;
		switch (num)
		{
		case 1:library_menu(library);
		case 2:exit(0);
		default:exit(0);
		}
	}
	case 7: {
		system("cls");
		float time = 0, start = 0, end = 0;;
		cout << "what time do you want to go to library?" << endl;
		cin >> time;
		start = library.get_starttime();
		end = library.get_endtime();
		if (time <= end && start <= time)
			cout << "the library is open in this time" << endl;
		else
			cout << "the library is close in this time" << endl;
		Sleep(2000);
		library_menu(library);
	}
	case 8:menu();
	case 0: {system("cls"); exit(0); }
	default: {system("cls"); exit(0); }
	}
}
void add_library() {
	system("cls");
	Librarys_Information library;
	char libraryname[100];
	char address[100];
	int establishedyear = 0;
	int numofemployers = 0;
	float starttime = 0;
	float endtime = 0;
	cout << "what is the library's name?" << endl;
	cin >> libraryname;
	cout << "what is library address?" << endl;
	cin >> address;
	cout << "when is the library's established year?" << endl;
	cin >> establishedyear;
	cout << "how many employers work in this library?" << endl;
	cin >> numofemployers;
	cout << "what time the library open?" << endl;
	cin >> starttime;
	cout << "what time the library close?" << endl;
	cin >> endtime;
	cout << "add books to this library!" << endl;
	library.set(libraryname, address, establishedyear, numofemployers, starttime, endtime, add_books_list());

	input(library);
}
void input(Librarys_Information library) {
	ofstream file_obj;
	file_obj.open("Input2.txt", ofstream::out | ios::app | ios::binary);
	file_obj.write((char*)&library, sizeof(library));
	file_obj.close();
	Sleep(3000);
	menu();
}
void print_booksinf(Librarys_Information library) {
	system("cls");
	library.print_books_information();
	int num = 0;
	cout << "1.back to menu\n0.exit" << endl;
	cin >> num;
	switch (num)
	{
	case 1:library_menu(library);
	case 2:exit(0);
	default:exit(0);
	}
}
Books_List add_books_list() {
	int temp = 1;
	Books_List bookslist;
	Book_information book;
	while (temp == 1) {
		book = add_books();
		bookslist.addbook(book);
		cout << "Do you want to add more books? ( write 1 for say YES and 0 for NO)" << endl;
		cin >> temp;
	}
	return bookslist;
}
Book_information add_books() {
	Book_information book;
	char bookname[100];
	writer_information writer;
	char writername[100];
	char e_mail[100];
	string gender1;
	char gender;
	int printyear = 0;
	cout << "what is the name of book?" << endl;
	cin >> bookname;
	cout << "what is the writer's name?" << endl;
	cin >> writername;
	cout << "what is the writer's e_mail?" << endl;
	cin >> e_mail;
	cout << "what is the writer's gender?(male or female)" << endl;
	cin >> gender1;
	if (gender1 == "male")
		gender = 'm';
	else
		gender = 'f';
	writer.set_writer_information(writername, e_mail, gender);
	cout << "when was this book published?" << endl;
	cin >> printyear;
	book.set_information(bookname, writer, printyear);
	return book;
}
