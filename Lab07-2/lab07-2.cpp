/*
 * lab07-2.cpp
 *
 *  Created on: Mar 04, 2014
 *      Author: vitorma
 *
 * "Write a recursive function to calculate the Fibonacci number for a given value
 * n. This is defined as:
 * Fibonacci (1) =1
 * Fibonacci (2) = 1
 * Fibonacci (n) = Fibonacci(n-1) + Fibonacci(n-2), for all n > 2"
 */

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstddef>
#include <string>

int fibonnaci(int n) {
	if (n == 1) {
		return 1;
	}

	if (n == 2) {
		return 1;
	}
	return fibonnaci(n - 1) + fibonnaci(n - 2);
}

int main(void) {
	int userInput;
	std::cout << "type the fibonnaci number: ";
	std::cin >> userInput;
	std::cout << fibonnaci(userInput);
	return 0;
}

