/*
 * lab04-1.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: vitorma
 *
 *   "Write a simple menu that takes user input and displays to the user which item
 * they selected. Examples might be ‘open file’, ‘close file’ and ‘exit’ etc. Try to
 * have a few more choices available. You should handle the case where the user
 * inputs an invalid value."
 *
 *
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(void) {

	const int openFile = 1;
	const int closeFile = 2;
	const int exit = 3;
	int userInput = 0;

	printf("Choose one of the following options\n");
	printf("%d. %s\n", openFile, "open file");
	printf("%d. %s\n", closeFile, "close file");
	printf("%d. %s\n", exit, "exit");
	printf("please type the number corresponding to an option:");
	scanf("%d", &userInput);
	switch (userInput) {
	case openFile:
		printf("you have choose to open file!");
		break;
	case closeFile:
		printf("you have choose to close file!");
		break;
	case exit:
		printf("you have choose to exit! Good bye then");
		break;
	default:
		printf("you have choose an invalid option! The program will close...");
		break;
	}
	return 0;
}
