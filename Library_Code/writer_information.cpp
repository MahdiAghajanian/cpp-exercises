//writer_information.cpp

#include "writer_information.h"
writer_information::writer_information() {
	gender = '\0';
	e_mail[0] = '\0';
	name[0] = '\0';
}
writer_information::writer_information(writer_information& obj2) {
	strcpy(name, obj2.name);
	strcpy(e_mail, obj2.e_mail);
	gender = obj2.gender;
}
void writer_information::set_writer_information(char _name[], char _e_mail[], char _gender) {
	strcpy(name, _name);
	strcpy(e_mail, _e_mail);
	gender = _gender;
}
const char* writer_information::print_writer_information() {
	char writerinf[100];
	sprintf(writerinf, "%s ( %c ) %s", name, gender, e_mail);
	return writerinf;;
}
const char* writer_information::get_writer_name() { return name; }
writer_information::~writer_information() {

}
