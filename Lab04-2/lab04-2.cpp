/*
 * lab04-2.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: vitorma
 *
 *  Write a program to calculate the total price for a sale at a greengrocer. Some
 * items are on special offer, you get 2 for the price of 1. Your program should be
 * able to check if an item is on special offer and calculate the correct price. Take
 * into account that the special offer only applies to multiples of 2, if the number
 * of items is odd, the extra item is calculated at full price.
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(void) {

	float total = 0;

	float applePrice = 1;
	float orangePrice = 2;
	bool inPromotion = true;

	int numberOfApples = 0;
	int numberOfOranges = 0;

	int userInput = 0;

	printf("Welcome to my store\n");
	printf("\n");
	printf("I have apples for %f pounds", applePrice);
	printf("\n");
	printf("I have oranges for %f pounds", orangePrice);
	printf("\n");
	printf("\n");
	printf("how many apples do you want?");
	printf("\n");
	scanf("%d", &userInput);
	numberOfApples = userInput;
	printf("how many oranges do you want?");
	printf("\n");
	scanf("%d", &userInput);
	numberOfOranges = userInput;

	if (inPromotion) {
		if (numberOfApples % 2 == 0) {
			printf("you got %d apples for the half of price\n", numberOfApples);
			applePrice = applePrice / 2;
			total += applePrice * numberOfApples;

		} else {
			if (numberOfApples > 1) {
				printf("you got %d apples for the half of price\n",
						numberOfApples - 1);
				printf("you got %d apples for the full price\n", 1);
			} else if (numberOfApples == 1) {
				printf("you got %d apples for the full price\n",
						numberOfApples);
			}
			total += applePrice;
			total += (numberOfApples - 1) * (applePrice / 2.0);
		}
	} else {

		total += applePrice * numberOfApples;
		printf("you got %d apples for the full price\n", numberOfApples);
	}

	if (numberOfOranges % 2 == 0) {
		printf("you got %d oranges for the half of price\n", numberOfOranges);
		total += (orangePrice / 2) * numberOfOranges;

	} else {
		if (numberOfOranges > 1) {
			printf("you got %d oranges for the half of price\n",
					numberOfOranges - 1);
			printf("you got %d oranges for the full price\n", 1);
		} else if (numberOfOranges == 1) {
			printf("you got %d oranges for the full price\n", 1);
		}
		total += orangePrice;
		total += (numberOfOranges - 1) * (orangePrice / 2);
	}
	printf("your total is: %f ", total);

	return 0;
}

