/*
 * lab03-2.cpp
 *
 *  Created on: Feb 4, 2014
 *      Author: vitorma
 *
 * "Write a program to output the following list of items as a numbered list ‘apple’,
 * ‘pear’, ‘orange’, ‘banana’. The order of the items does not matter.
 * e.g.
 * apple
 * pear
 * orange
 * banana
 * should become
 * 1 apple
 * 2 pear
 * 3 orange
 * 4 banana
 * The clue is to use the increment operator to get the numbering."
 *
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main() {
	string apple = "apple";
	string pear = "pear";
	string orange = "orange";
	string banana = "banana";
	int position = 1;

	printf("%d. %s\n", position, apple.c_str());
	printf("%d. %s\n", ++position, pear.c_str());
	printf("%d. %s\n", ++position, orange.c_str());
	printf("%d. %s\n", ++position, banana.c_str());
	return 0;
}
