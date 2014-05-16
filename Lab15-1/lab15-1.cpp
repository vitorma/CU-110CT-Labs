/*
 * lab15-1.cpp
 *
 *  Created on: 16 May 2014
 *      Author: vitorma
 *
 * Your task this week is to implement the bubble sort algorithm demonstrated
 * in the lecture, you may use the code on Moodle, but it’s better for your skills if you
 * try to implement it yourself. Then write a program which creates a very large array (>
 * 100,000 elements) of random numbers (look up the rand() function in the stdlib.h
 * library on Google), use the clock() function in the ctime.h library to compare the
 * running time for the algorithm on an array 100 elements long, 1000 elements long and
 * 100,000 elements long. This task requires you to look up the usage of the rand and
 * clock functions on the internet or in a book. You may use the pre-processor #define
 * to set the array size, though remember its bad practice to do this usually.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int size) {

	bool swapped;
	for (int i = 0; i < size - 1; ++i) {
		swapped = false;
		for (int j = 0; j < size - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

void randomArray(int array[], int size) {
	srand((unsigned) time(0));

	for (int i = 0; i < size; i++) {
		int number = rand() % size;
		array[i] = number;
	}
}

void printArray(int array[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n ");
}

void sortTest(int size, bool print) {
	int array[size];
	printf("generating a random array... \n");
	randomArray(array, size);
	if (print)
		printArray(array, size);
	printf("sorting... \n");
	clock_t start = clock();
	bubbleSort(array, size);
	double timeTaken = ((double) (clock() - start) / CLOCKS_PER_SEC);
	printf("Time taken: %fs\n", timeTaken );
	if (print)
		printArray(array, size);
	printf("------------------------- \n");
}

int main(int argc, char **argv) {
	printf("n = 10  \n");
	sortTest(10, true);
	printf("n = 100  \n");
	sortTest(100, true);
	printf("n = 1000  \n");
	sortTest(1000, false);
	printf("n = 100000  \n");
	sortTest(100000, false);

}

