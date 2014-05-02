/*
 * lab03-1.cpp
 *
 *  Created on: Feb 4, 2014
 *      Author: vitorma
 *
 * "Write a program to output to determine the truth of the following statement in a single
 * statement:
 * The maximum value for a unsigned int is greater than the maximum value for a
 * signed int and the minimum value for a int is less than the minimum value for an
 * short int or an unsigned int.
 * Use the correct variable types to store your data.You can use the table in the lecture
 * notes for your values if you prefer, remember to use brackets to ensure the correct
 * operator precedence."
 *
 */

#include <stdio.h>
#include <limits>

int main() {

	unsigned int uimin = std::numeric_limits<unsigned int>::min();
	unsigned int uimax = std::numeric_limits<unsigned int>::max();

	int imin = std::numeric_limits<int>::min();
	int imax = std::numeric_limits<int>::max();

	printf("Is the max unsigned int greater than max int?");
	printf("\n");
	printf("%u > %d? ", uimax, imax);
	printf("%s", imax >= 0 && uimax > (unsigned int) imax ? "TRUE" : "FALSE");
	printf("\n");

	printf("Is the min int less than min unsigned int?");
	printf("\n");
	printf("%d < %u? ", imin, uimin);
	printf("%s", imin < (int) uimin ? "TRUE" : "FALSE");
	printf("\n");

	int a, b;
	printf("\n");
	printf("==============================");
	printf("\n");
	printf("try to put one number now: ");
	scanf("%d", &a);
	printf("try to put another number now: ");
	scanf("%d", &b);
	printf("%d > %d? ", a, b);
	printf("%s", a > b ? "TRUE" : "FALSE");
	printf("\n");
	printf("%d < %d? ", a, b);
	printf("%s", a < b ? "TRUE" : "FALSE");
	printf("\n");
	printf("%d == %d? ", a, b);
	printf("%s", a == b ? "TRUE" : "FALSE");

}
