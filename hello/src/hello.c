/*
 ============================================================================
 Name        : hello.c
 Author      : x
 Version     : 1.0

 Description : Sample code of various things

 Steps		 :

 Notes		 :

 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "testSwitch.h"



int main(void) {

/*
 * 4.3
 * integer math
 *
 *  Program 4.3 Output
 *	6 + a / 5 * b = 16
 *	a / b * b = 24
 *	c / d * d = 25.000000
 *	-a = -25
 *
 */
	int a = 25;
	int b=2;
	float c = 25.0;
	float d = 2.0;

	printf ("6 + a / 5 * b = %i\n", 6 + a / 5 * b);
	printf ("a / b * b = %i\n", a / b * b);
	printf ("c / d * d = %f\n", c / d * d);
	printf ("-a = %i\n", -a);

/*
 *
 * 4.4
 * Write a program that converts 27° from degrees Fahrenheit (F)
 * to degrees Celsius (C).  Use formating to limit decimal
 *
 *
 */

	double far = 27;
	double cel = 0;

	printf("the answer is %-5.1f \n\n", (cel = (far -32) /1.8));

/*
 *
 * 4.8  for loop
 * using an array
 *
 */

	double nextMultiple = 0;
	int ii[3] = {365,12258,996};		// int array
	int jj[3] = {7,23,4};				// int array

	for ( int n = 0; n <= 2; ++n )
	{
		printf("ii = %i, jj = %i, next multiple = %-5.f\n",ii[n],jj[n], nextMultiple=(ii[n]+jj[n]-ii[n]%jj[n]));
	}
	printf("\n");

/*
 *
 * 5.  while loop
 *
 */
	int count = 1;
	while ( count <= 5 ) {
		printf ("%i\n", count); ++count;
	}

/*
 *
 * 5.9 do while
 *
 * scanf for input  commented out scan so program will run without interrupt
 *
 */
	int number, right_digit;

	printf ("Enter your number - pgm will reverse the digits.\n");
//	scanf ("%i", &number);
	number = 3456;
	do {
		right_digit = number % 10;
		 	 printf ("%i", right_digit); number = number / 10;
	}
	while ( number != 0 );

	printf ("\n");



/*
 *
 * 5.7 scanf with 2 inputs  commented out scan so program will run without interrupt
 *
 */

	int u, v, temp;
	printf ("Please type in two nonnegative integers.\n");
//	scanf ("%i%i", &u, &v);
	u =34, v=56;
	while ( v != 0 ) {
		temp = u % v;
		u = v;
		v = temp;
	}
	printf ("Their greatest common divisor is %i\n", u);


/*
 *
 * 5.3 for loop, counting by jumps of 5
 */

	printf ("EVERY FIFTH TRIANGULAR NUMBER FROM 5 TO 50\n\n");
	printf (" n       triangular number\n");
	printf ("---      -----------------\n");

	for ( int n = 5; n <= 50; n += 5 )
		printf ("%2i        %4i\n", n, n * (n + 1) / 2);


/*
 *
 * The factorial of an integer n, written n!, is the product of the consecutive integers 1 through n. For example, 5 factorial is calculated as
5! = 5x4x3x2x1 = 120
Write a program to generate and print a table of the first 10 factorials.
 *
 */

	int x, factorial = 1;
	for ( int n = 0; n <= 9; ++n ) {
		x = n+1;
		while (x > 1) {
			factorial = factorial * x;
			--x;
		}
		printf ("count is %i   factorial is %i\n", n+1, factorial);
		factorial = 1;

	}



/*
 *
 * Write a program that calculates the sum of the digits of an integer.
 * For example, the sum of the digits of the number 2155 is 2 + 1 + 5 + 5 or 13.
 * The program should accept any arbitrary integer typed in by the user.
 *
 *
 */

	int sumnum=0, num2;

	printf ("Enter your number - pgm will calc the sum of it's digits.\n");
//	scanf ("%i", &num2);
	num2 = 456;
	do {
		sumnum = sumnum + (num2 % 10);
	 	num2 = num2 / 10;
	}
	while ( num2 != 0 );


	printf ("%i = sum", sumnum);

	printf ("\n");

/*
 *
 * if, and if/else
 *
 */

	int number_to_test, remainder;

	printf ("Enter your number to be tested: 34 ");
//	scanf ("%i", &number_to_test);
	number_to_test = 34;
	remainder = number_to_test % 2;

	if ( remainder == 0 ) {
		printf ("The number is even.\n");
	}
		else {
			printf ("The number is odd.\n");
		}


/*
 *
 * test of switch statement, but, also test of using function's
 * put this into hello.h
 *
 */



	float value1, value2;
	char operator;

	printf ("Type in your expression.\n");
	//scanf ("%f %c %f", &value1, &operator, &value2);
	value1 = 4;
	value2 = 5;
	operator = '+';


//  changed to function call versus just doing in main

	testSwitch (value1, operator, value2);

/*
	switch (operator) {
		case '+':
			printf ("%.2f\n", value1 + value2);
			break;
		case '-':
			printf ("%.2f\n", value1 - value2);
			break;
		case '*':
			printf ("%.2f\n", value1 * value2);
			break;
		case '/':
			if ( value2 == 0 )
				printf ("Division by zero.\n");
			else
				printf ("%.2f\n", value1 / value2);
			break;
		default:
			printf ("Unknown operator.\n"); break;
	}

*/




/*
 *
 * Test if leap year
 *
 *
 *
 */



	int rem_4, rem_100, rem_400, yearToTest;

	printf ("Enter your number to be tested:  ");
//	scanf ("%i", &yearToTest);
	yearToTest = 2000;

	rem_4 = yearToTest % 4;
	rem_100 = yearToTest % 100;
	rem_400 = yearToTest % 400;

	if ((rem_4 == 0 && rem_100 != 0) || (rem_4 == 0 && rem_100 == 0 && rem_400 == 0))
		printf ("%i is a leap year\n", yearToTest);




/*
 *
 * using the conditional operator - twice in one line - read from right to left
 *
 */

	int number2 = -4;

	printf ("Sign = %i\n", ( number2 < 0 ) ? -1 : ( number2 == 0 ) ? 0 : 1);




/*
 *
 * 6.2  Write a program that asks the user to type in two integer values at the terminal.
 * Test these two numbers to determine if the first is evenly divisible by the second,
 * and then display an appropriate message at the terminal.
 *
 *
 */

	int term1, term2;
	printf("key in two values separated by a space - ");
	//scanf("%i %i", &term1, &term2);
	term1 = 22, term2=11;


	if ((term1 % term2) == 0) {
		printf("%i is divisible by %i\n",term1, term2);
	}
	else
	{
		printf("%i is NOT divisible by %i\n",term1, term2);
	}



/*
 *
 * Write a program that accepts two integer values typed in by the user.
 * Display the result of dividing the first integer by the second,
 * to three-decimal-place accuracy. Remember to have the program check
 * for division by zero.
 *
 *
 *
 */

	int term3, term4;
	double term5;
	printf("key in two values separated by a space - ");
	scanf("%i %i", &term3, &term4);
	//term3 = 22, ter42=11;

	if (term4 != 0){
		term5 = (double) term3 /  term4;
		printf("%d divided by %d = %-3.3f\n", term3, term4, term5);
	}
	else {
		printf("can't divide by 0");
	}









		return EXIT_SUCCESS;
}
