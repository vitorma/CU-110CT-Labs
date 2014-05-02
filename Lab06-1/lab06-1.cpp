/*
 * lab06-1.cpp
 *
 *  Created on: Feb 25, 2014
 *      Author: vitorma
 *
 *  "Write a function to calculate and return the area of a circle. The radius of the
 * circle should be given as an argument to the function. You should also write a
 * short program to print the result to the screen. The equations to calculate the
 * area is PI*r^2"
 *
 */

#include <cmath>
#include <stdio.h>
using namespace std;

float calculateAreaOfCircle(float radius) {
	return M_PI * (radius * radius);
}

int main() {
	printf("Type the radius: ");
	float userInput;
	scanf("%f", &userInput);
	printf("\n");
	printf("Area: %f", calculateAreaOfCircle(userInput));
}

