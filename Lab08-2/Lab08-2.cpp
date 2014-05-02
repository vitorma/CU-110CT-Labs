/*
 * lab08-2.cpp
 *
 *  Created on: Mar 11, 2014
 *      Author: vitorma
 *
 * Write a small program to create an array of 10 ‘ints’, then use pointer
 * arithmetic to point to the 5th element of the array.
 */

#include <iostream>

int main() {
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int * pointerToIntArray = array;
	int * pointerTo5thElement = pointerToIntArray + 4;
	int fifthElement = *pointerTo5thElement;
	std::cout << fifthElement;
	return 0;
}

