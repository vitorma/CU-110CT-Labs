/*
 * lab05-2.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: vitorma
 *
 *  "Write a program which will implement a simple multiple choice menu system. The
 * program should repeatedly ask the user for character input representing the chosen
 * menu item, until the character ‘q’ is input, at which point the program must quit.
 * Otherwise the program should output a string showing which menu option the user
 * has chosen. The Menu should have at least 3 choices."
 */
#include <iostream>
#include <cstdlib>
#include <stdio.h>

int main(int argc, char **argv) {
	char userInput;
	const char openFile = 'o';
	const char closeFile = 'c';
	const char exit = 'q';

	printf("Choose one of the following options\n");
	printf("%c. %s\n", openFile, "open file");
	printf("%c. %s\n", closeFile, "close file");
	printf("%c. %s\n", exit, "exit");

	while (userInput != 'q') {
		printf("please type the number corresponding to an option:");
		std::cin >> userInput;
		switch (userInput) {
		case openFile:
			printf("you have choose to open file!\n");
			break;
		case closeFile:
			printf("you have choose to close file!\n");
			break;
		case exit:
			printf("you have choose to exit! Good bye then");
			break;
		default:
			printf("you have choose an invalid option!\n");
			break;

		}

	}

}

