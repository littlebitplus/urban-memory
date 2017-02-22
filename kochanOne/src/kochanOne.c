/*
 ============================================================================
 Name        : kochanOne.c
 Author      : tim
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct date																		//put here so available to all
{
	int month;
	int day;
	int year;
};

#include "sideFunctions.h"														//to bring in functions


int main(void) {
	//puts("!!!Hello World!!!"); 													//generic puts

	//struct date firstDay = { 8, 8, 2004 };
	//struct date secondDay = { 2, 22, 2005 };

	struct date firstDay;
	struct date secondDay;
	int firstDayNumber, secondDayNumber;
	int firstRequest = 1;
	int secondRequest = 2;

	firstDay = enterDateData (firstRequest);
	secondDay = enterDateData (secondRequest);

	firstDayNumber = calculateDateNumber (firstDay);
	secondDayNumber = calculateDateNumber(secondDay);

	printf ("%i, %i \n", firstDayNumber, secondDayNumber);						//for debug
	printf ("The number of day's between %i/%i/%i and %i/%i/%i is %i\n",
			firstDay.month, firstDay.day, firstDay.year,
			secondDay.month, secondDay.day, secondDay.year,
			(secondDayNumber - firstDayNumber));



	return EXIT_SUCCESS;
}


