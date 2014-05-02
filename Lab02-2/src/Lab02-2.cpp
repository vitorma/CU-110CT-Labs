/*
 * Lab02-2.cpp
 *
 *  Created on: Jan 25, 2014
 *      Author: vitorma
 *
 *
 *     "Your second task this lab is to write a program to print out the lines of the children’s
 * song ‘1 man went to mow, went to mow a meadow’. Use variables to store the count
 * and increment it as well as the string parts which vary, or where they can be reused."
 *
 */
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(void) {
	string singular =
			"%d man went to mow, went to mow a meadow,\n%d man and his dog - Woof! - went to mow a meadow.\n\n";
	string plural =
			"%d men went to mow, went to mow a meadow,\n%d men and their dog - Woof! - went to mow a meadow.\n\n";
	int verses;

	printf("how many verses do you want: ");
	scanf("%d", &verses);
	printf("=========================");
	printf("\n");
	for (int verse = 1; verse <= verses; verse++) {
		if (verse <= 1)
			printf(singular.c_str(), verse);
		else
			printf(plural.c_str(), verse);
	}
	return 0;
}
