//writer_information.h

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
#pragma warning(disable: 4996)
class writer_information {
	char name[100];
	char e_mail[100];
	char gender;
public:
	writer_information();
	writer_information(writer_information& obj2);
	void set_writer_information(char _name[], char _e_mail[], char _gender);
	const char* print_writer_information();
	const char* get_writer_name();
	~writer_information();
};
