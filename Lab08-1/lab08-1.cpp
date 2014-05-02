/*
 * lab08-1.cpp
 *
 *  Created on: Mar 11, 2014
 *      Author: vitorma
 *
 * Write a small program which will create a variable of type ‘char’, create two
 * pointers of type ‘char’ and set both of them to point at the original char variable. Then
 * write two functions which will take the pointer to char as an argument and then
 * change the value of the original variable.
 */

#include <iostream>

void replaceCharByAnother(char* pointerToChar, char newValue) {
	*pointerToChar = newValue;
}

int main() {
	char aChar = 'x';
	char* firstPointer = &aChar;
	char* secondPointer = &aChar;
	std::cout << "the original value of the variable is: " << aChar
			<< std::endl;
	replaceCharByAnother(firstPointer, 'A');
	std::cout << "now the value of the variable is: " << aChar << std::endl;
	replaceCharByAnother(secondPointer, 'B');
	std::cout << "and now the value of the variable is: " << aChar << std::endl;
	return 0;
}
