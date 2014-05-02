/*
 * lab07-1.cpp
 *
 *  Created on: Mar 04, 2014
 *      Author: vitorma
 *
 * "Write a recursive function Power() which raises its first argument (of type
 * "float") to the power of its second (non-negative integer) argument. For example,
 * Power(2.0, 3) = 2 x 2 x 2, and Power(4.0, 5) = 4 x 4 x 4 x 4 x 4."
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstddef>
#include <string>

float powerIterative(float base, int exponent) {
	if (exponent < 0) {
		throw 0;
	}

	if (exponent == 0) {
		return 1;
	}

	float result = base;
	for (int i = 1; i < exponent; ++i) {
		result *= base;
	}

	return result;
}

float powerRecursive(float base, int exponent) {
//	if(exponent < 0) {
//		throw 0;
//	}

	if (exponent == 0) {
		return 1;
	}

	return base * powerRecursive(base, exponent - 1);

}

int main(int argc, char **argv) {
	float base;
	std::cout << "type the base : ";
	std::cin >> base;
	std::cout << "type the exponent : ";
	int exponent;
	std::cin >> exponent;
	try {
		std::cout << base << "^" << exponent << ": "
				<< powerRecursive(base, exponent);
	} catch (int e) {
		switch (e) {
		case 0:
			std::cout << "the exponent must be positive";
			break;
		default:
			std::cout << "something is wrong";
			break;
		}
	}

}
