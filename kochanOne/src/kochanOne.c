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

struct time																		//put here so available to all
{
	int hour;
	int minute;
	int second;
};

struct week
{
	char name[3];
};

#include "sideFunctions.h"														//to bring in functions


int main(void) {
	//puts("!!!Hello World!!!"); 													//generic puts

/*
 *
 * 9.2
 *


	//struct date firstDay = { 8, 8, 2004 };			//for fixed entry
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
*
*
*
 */


/*
 *
 *  9.3
 *


	struct time time1 = { 3, 45, 15 };			//for fixed entry
	struct time time2 = { 9, 44, 03 };
	struct time timeDiff;

	timeDiff = elapsed_time (time1, time2);

	printf("The amount of time between %i:%i:%i and %i:%i:%i is %i:%i:%i\n",
			time1.hour, time1.minute, time1.second,
			time2.hour, time2.minute, time2.second,
			timeDiff.hour, timeDiff.minute, timeDiff.second);


 *
 */


	struct date day1 = { 8, 8, 2004 };			//for fixed entry
	int day1Number;
	int dayOfWeekNum;

	const struct week days[7] =
		{ 		{{'S', 'u', 'n'}},
				{{'M', 'o', 'n'}},
				{{'T', 'u', 'e'}},
				{{'W', 'e', 'd'}},
				{{'T', 'h', 'u'}},
				{{'F', 'r', 'i'}},
				{{'S', 'a', 't'}}
		};

	day1Number = calculateDateNumber (day1);
	dayOfWeekNum = (day1Number - 621049) % 7;	//formula to get day of week (-621049 %7)

	printf ("%i/%i/%i was a %c%c%c \n", day1.month, day1.day, day1.year, days[dayOfWeekNum].name[0], days[dayOfWeekNum].name[1], days[dayOfWeekNum].name[2]);



	return EXIT_SUCCESS;
}


