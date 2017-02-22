/*
 * sideFunctions.c
 *
 *  Created on: Feb 19, 2017
 *      Author: halburt
 */

#include <stdio.h>

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
*/


struct date enterDateData (int requestNum) {

	struct date enterDate;

	printf ("Enter %i date (format mm:dd:yy)\n",requestNum);
	scanf (" %d:%d:%d", &enterDate.month, &enterDate.day, &enterDate.year);

	return (enterDate);

}


int calculateDateNumber (struct date d) {
	int numb, f, g;
	if (d.month <= 2) {
		f = d.year - 1;
		g = d.month  + 13;
	} else {
		f = d.year;
		g = d.month  + 1;
	}
	numb = 1461 * f / 4 + 153 * g / 5 + d.day;

	return (numb);
}


