/*
 * lab09-2.cpp
 *
 *  Created on: Mar 18, 2014
 *      Author: vitorma
 *
 * Create a class which stores an array of student records, can add a new student
 * record and access a specific record, and print out a list of all the records. Make sure
 * that the list cannot be accidently changed. The class should keep track of the total
 * number of records currently stored. You can assume a maximum of 10 records can be
 * stored.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

class student {
private:
	string name;
	string surname;
	int number;

public:

	student(string name, string surname, int number) {
		this->name = name;
		this->surname = surname;
		this->number = number;
	}

	student() {}

	string getName() {
		return name;
	}

	string getSurname() {
			return surname;
		}

	int getNumber() {
			return number;
		}

	void setName(string name) {
		this->name = name;
	}

	void setsurname(string surname) {
		this->surname = surname;
	}

	void setNumber(int number) {
		this->number = number;
	}
};

class studentStorage {
private:
	int count;
	student students[10];

public:
	studentStorage() {
		this->count = 0;
	}

	bool add(student s) {
		if (!count >= 10) {
			return false;
		}
		students[count] = s;
		count++;
		return true;
	}

	bool edit(int studentNumber, string name, string surname) {
		if (getStudentByNumber(studentNumber).getName() == "null")
			return false;
		student &s = getStudentByNumber(studentNumber);
		s.setName(name);
		s.setsurname(surname);
		return true;
	}

	student& getStudentByNumber(int studentNumber) {
		for (int i = 0; i < count; i++) {
			if (students[i].getNumber() == studentNumber) {
				return students[i];
			}
		}
		return * new student("null", "null", 0);
	}

	student& getStudentByPosition(int position) {
		if (position > count) {
			return * new student("null", "null", 0);
		}
		return students[position];
	}

	int getNumberOfStudents() {
		return count;
	}
};

//utility method to convert strings to int
bool String2Int(const string& str, int& result) {
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

void addStudents(studentStorage &students) {
	string name;
	string surname;
	int number;
	cout << "Enter name: ";
	cin.ignore();
	std::getline(std::cin, name);
	cout << "Enter surname: ";
	std::getline(std::cin, surname);
	cout << "Enter the student number: ";
	string temp;
	cin >> temp;
	if(!String2Int(temp, number)) {
		cout << "student number invalid!" << endl;
		cout << "student not added!" << endl;
		return;
	}
	student  s(name, surname, number);
	if (students.add(s)) {
		cout << "student added successfully" << endl;
	} else {
		cout << "I can't add more students";
	}

}

void listStudents(studentStorage &students) {
	if (students.getNumberOfStudents() == 0) {
		cout << "no students to list!" << endl;
		return;
	}
	for (int i = 0; i < students.getNumberOfStudents(); ++i) {
		cout << "Student Name: " << students.getStudentByPosition(i).getName()
				<< endl;
		cout << "Student Surname: " << students.getStudentByPosition(i).getSurname()
				<< endl;
		cout << "Student number: " << students.getStudentByPosition(i).getNumber()
				<< endl;
	}

}

void editStudent(studentStorage &students) {
	int numberToFind;
	string name;
	string surname;
	cout << "Type the student's number that you want to edit: ";
	cin >> numberToFind;
	if (students.getStudentByNumber(numberToFind).getName() == "null") {
		cout << "student not found ";

	} else {
		student& s = students.getStudentByNumber(numberToFind);
		cout << "Type the new student's name: ";
		cin >> name;
		cout << "Type the new student's surname: ";
		cin >> surname;
		students.edit(s.getNumber(), name, surname);

	}

}

int main() {
	studentStorage students;
	char userInput;
	while (userInput != 'q') {
		cout << "------------------------------" << endl;
		cout << "Select an option below" << endl;
		cout << "a. add a student" << endl;
		cout << "l. list student" << endl;
		cout << "e. edit student by number" << endl;
		cout << "q. quit" << endl;
		cout << "Type the option: " << endl;
		cin >> userInput;
		cout << "------------------------------" << endl;
		switch (userInput) {
		case 'a':
			addStudents(students);
			break;
		case 'l':
			listStudents(students);
			break;
		case 'e':
			editStudent(students);
			break;
		case 'q':
			cout << "Bye!" << endl;
			break;
		default:
			cout << "Invalid option!" << endl;
			break;

		}

	}

	return 0;
}
