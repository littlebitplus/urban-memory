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

struct date
{
	int month;
	int day;
	int year;
};


/*
 *
 * N=1461xf(year,month)/4+153xg(month)/5 +day
 *
 * where
 *
 * f(year, month) = year - 1     if month <= 2 otherwise
 * 					year
 *
 * g(month) = month + 13 		if month <= 2 otherwise
 * 			month + 1
 *
 *
 *
 */



int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */


	int number, right_digit;

	printf ("Enter two dates (format mm:dd:yy)\n");
	scanf ("%i", &number);

















	return EXIT_SUCCESS;
}
