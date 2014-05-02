/*
 * lab05-1.cpp
 *
 *  Created on: Feb 18, 2014
 *      Author: vitorma
 *
 *  "Write a program to find the average of an array of integers. Use a loop to do this. In
 * case you can’t remember, you calculate the average by dividing the sum of all the
 * values by the number of values."
 *
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>

int main(int argc, char **argv) {

	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	float sum = 0;
	for (int i = 0; i < 10; ++i) {
		sum += array[i];
		//sum = sum + array[i];
	}
	float avarage = sum / 10;
	printf("%f", avarage);
}

