/*
 * lab09-1.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: vitorma
 *
 * Write a program to store student details in a struct. The information should
 * include a student number and first name and surname. You can use the std::string
 * library, just #include <string>
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

#include <string>

bool String2Int(const std::string& str, int& result) {
	std::string::const_iterator i = str.begin();

	if (i == str.end())
		return false;

	bool negative = false;

	if (*i == '-') {
		negative = true;
		++i;

		if (i == str.end())
			return false;
	}

	result = 0;

	for (; i != str.end(); ++i) {
		if (*i < '0' || *i > '9')
			return false;

		result *= 10;
		result += *i - '0';
	}

	if (negative) {
		result = -result;
	}

	return true;
}

struct student {
	string name;
	string surname;
	int number;
};

int main() {
	student aStudent;
	cout << "Enter name: ";
	getline(cin, aStudent.name);
	cout << "Enter surname: ";
	getline(cin, aStudent.surname);
	cout << "Enter the student number: ";
	string temp;
	getline(cin, temp);
	String2Int(temp, aStudent.number);

	cout << "Name: " << aStudent.name << endl;
	cout << "Surname: " << aStudent.surname << endl;
	cout << "Number: " << aStudent.number << endl;

	return 0;
}
