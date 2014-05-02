/*
 * Lab02-1.cpp
 *
 *  Created on: Jan 25, 2014
 *      Author: vitorma
 *
 *
 *      "You are required to write a program which will calculate the area of a trapezoid, the
 *	formula is:
 *
 *  area =   b1 + b2
 *         (---------) * h
 *              2
 *
 * Where b1 and b2 are the two bases and h is the height. Be sure to get the
 * operator precedence right."
 *
 */
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(void) {
	float height;
	float base1;
	float base2;

	printf("Type the height: ");
	scanf("%f", &height);
	printf("Type the base1: ");
	scanf("%f", &base1);
	printf("Type the base2: ");
	scanf("%f", &base2);

	printf("\n");
	printf("=============");
	printf("\n");
	printf("height: %f", height);
	printf("\n");
	printf("base1: %f", base1);
	printf("\n");
	printf("base2: %f", base2);
	printf("\n");
	printf("calculated area: %f", ((base1 + base2) / 2) * height);
	return 0;

}

