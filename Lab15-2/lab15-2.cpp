/*
 * lab15-2.cpp
 *
 *  Created on: 16 May 2014
 *      Author: vitorma
 *
 *      Implement the two search algorithms which were demonstrated in the lecture.
 * You can use the code I wrote on Moodle, though, again, try to implement them
 * yourself. It’s good for you. Now, using the rand and clock function as before and
 * compare the running speed of the two algorithms. You may need to try a few times
 * before you find a valid number in it, and additionally they will have to be executed
 * very many times to get a meaningful time value so consider using a loop executing
 * the functions 1,000,000 or more times and using rand to generate the search value.
 * Ensure that you do not execute the sort function in the loop as it will be very slow.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomArray(int array[], int size) {
	srand((unsigned) time(0));

	for (int i = 0; i < size; i++) {
		int number = rand();
		array[i] = number;
	}
}

void printArray(int array[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n ");
}

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

int linearSearch(int array[], int size, int valueToSearch) {
	for (int i = 0; i < size; i++) {
		if (array[i] == valueToSearch) {
			return i;
		}
	}
	return -1;
}

int binary_search(int array[], int first, int last, int search_key) {
	int index;

	if (first > last)
		index = -1;

	else {
		int mid = (first + last) / 2;

		if (search_key == array[mid])
			index = mid;
		else

		if (search_key < array[mid])
			index = binary_search(array, first, mid - 1, search_key);
		else
			index = binary_search(array, mid + 1, last, search_key);

	}
	return index;
}

void searchTest(int size) {
	int array[size];
	randomArray(array, size);
	int randomPosition = rand() % size;
	int randomNumber = array[randomPosition];

	bubbleSort(array, size);

	printf("number: %d \n ", randomNumber);
	printf("-----------------------------------------\n");
	clock_t start = clock();
	printf("Binary search \n position: %d \n",
			binary_search(array, 0, size - 1, randomNumber));
	double timeTaken = ((double) (clock() - start) / CLOCKS_PER_SEC);
	printf("Time taken: %fs\n", timeTaken);
	printf("-----------------------------------------\n");
	start = clock();
	printf("Linear search \n position: %d \n",
			linearSearch(array, size, randomNumber));
	timeTaken = ((double) (clock() - start) / CLOCKS_PER_SEC);
	printf("Time taken: %fs\n", timeTaken);
}

int main(int argc, char **argv) {
	printf("#########################################\n");
	printf("n = 10 \n");
	int size = 10;
	searchTest(size);
	printf("#########################################\n");
	printf("n = 100 \n");
	size = 100;
	searchTest(size);
	printf("#########################################\n");
	printf("n = 10000 \n");
	size = 10000;
	searchTest(size);
	printf("#########################################\n");
	printf("n = 100000 \n");
	size = 100000;
	searchTest(size);
	printf("#########################################\n");

}

