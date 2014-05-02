/*
 * Lab06-2.cpp
 *
 *  Created on: Feb 25, 2014
 *      Author: vitorma
 *
 *  "Write a function to return the sum of a range of an array. The array, as well as
 * the start and end point of the range must be given as arguments to the function.
 * You might want to think about checking that the start and end points are valid,
 * that is, that the start point is not bigger than the end point, that the start point is
 * not less than zero, and that the end point is not bigger than the end of the array.
 * You will need to think about how to tell the function how long the array is."
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstddef>
#include <string>

float sumOfArray(int start, int end, int arraySize, float array[]) {
	if (start > end) {
		throw 0;
	}
	if (start < 0) {
		throw 1;
	}
	if (end < 0) {
		throw 2;
	}
	if (end > arraySize) {
		throw 3;
	}

	float sum = 0;
	for (int i = start; i < end; ++i) {
		sum += array[i];
	}

	return sum;
}

int main(int argc, char **argv) {
	int arraySize = 0;
	std::cout << "how many numbers you want to enter? ";
	std::cin >> arraySize; //user input

	float array[arraySize];
	int start = 0;
	int end = 0;
	float userInput;
	int numberOfInputs = 0;
	for (int i = 0; i < arraySize; ++i) {
		std::cout << "Type the " << i + 1 << "th number: ";
		std::cin >> userInput;
		array[numberOfInputs] = userInput;
		numberOfInputs++;

	}

	std::cout << "Type the starting position to sum: ";
	std::cin >> start;
	std::cout << "Type the ending position to sum: ";
	std::cin >> end;

	try {
		printf("sum: %f", sumOfArray((start - 1), end, arraySize, array));
	} catch (int e) {
		switch (e) {
		case 0:
			printf("The start point must be lower than end");
			break;
		case 1:
			printf("The start point must be positive");
			break;
		case 2:
			printf("the end point must be positive");
			break;
		case 3:
			printf("the end point should not be greater than size of array");
			break;
		default:
			printf("something was wrong and I've not predicted");
			break;
		}

	}
}

