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
#include <stdlib.h>			//exit values
#include <stdbool.h>		//boolen values
#include <ctype.h>   		//toupper

#include "testSwitch.h"		//for exercise 4.x



int main(void) {

/*
 * 4.3
 * integer math
 *
 * notice how this doesn't work out quite the way you might think because
 * integer math doesn't use the remainder
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

///////////////////////////////////////////////////////////////////////////


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


///////////////////////////////////////////////////////////////////////////

/*
 *
 * 4.8
 *
 * for loop and using an array
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


////////////////////////////////////////////////////////////////////////////


/*
 *
 * 5.  while loop
 *
 */
	int count = 1;
	while ( count <= 5 ) {
		printf ("%i\n", count); ++count;
	}



////////////////////////////////////////////////////////////////////////////


/*
 *
 * 5.9 do while
 *
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


////////////////////////////////////////////////////////////////////////////


/*
 *
 * 5.7 scanf with 2 inputs  commented out scan so program will run without interrupt
 *
 */

	int u, v, temp;
	printf ("Please type in two nonnegative integers.\n");
//	scanf ("%i %i", &u, &v);
	u =34, v=56;
	while ( v != 0 ) {
		temp = u % v;
		u = v;
		v = temp;
	}
	printf ("Their greatest common divisor is %i\n", u);


////////////////////////////////////////////////////////////////////////////


/*
 *
 * 5.3 for loop, counting by jumps of 5
 */

	printf ("EVERY FIFTH TRIANGULAR NUMBER FROM 5 TO 50\n\n");
	printf (" n       triangular number\n");
	printf ("---      -----------------\n");

	for ( int n = 5; n <= 50; n += 5 )
		printf ("%2i        %4i\n", n, n * (n + 1) / 2);

////////////////////////////////////////////////////////////////////////////


/*
 *
 * Calculating the factorial of an integer  =  5! = 5x4x3x2x1 = 120
 *
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

////////////////////////////////////////////////////////////////////////////

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


	printf ("%i = sum\n", sumnum);
	printf ("\n");


////////////////////////////////////////////////////////////////////////////


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


////////////////////////////////////////////////////////////////////////////


/*
 *
 * test of switch statement, but, also test of using function's
 * put this into testSwitch.c
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


////////////////////////////////////////////////////////////////////////////


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


////////////////////////////////////////////////////////////////////////////


/*
 *
 * using the conditional operator - twice in one line - read from right to left
 *
 */

	int number2 = -4;

	printf ("Sign = %i\n", ( number2 < 0 ) ? -1 : ( number2 == 0 ) ? 0 : 1);


////////////////////////////////////////////////////////////////////////////


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


////////////////////////////////////////////////////////////////////////////



/*
 * 6.3
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
	//scanf("%i %i", &term3, &term4);
	term3 = 22455, term4 = 11;

	if (term4 != 0){
		term5 = (double) term3 /  term4;
		printf("%d divided by %d = %-3.3f\n", term3, term4, term5);
	}
	else {
		printf("can't divide by 0");
	}




////////////////////////////////////////////////////////////////////////////

/*
 *
 * 6.4
 * Write a program that acts as a simple “printing” calculator.
 * The program should allow the user to type in expressions of the form
 * number operator
 * The following operators should be recognized by the program:
 *
 * + - * / S E
 *
 *
 *
 */


	int calc1;
	char oper1;
	int accum = 0;
	_Bool runLoop = true;

	printf("Begin Calculations\nkey in number and operator separated by a space - (i.e 10 S) --> ");
	printf("\n");
	while (runLoop) {
		//scanf("%i %c", &calc1, &oper1);
		calc1 = 10;
		oper1 = 'e';
		oper1 = toupper(oper1);
		switch (oper1) {
			case '+':
				accum += calc1;
				printf ("add %i to get new total of:%i\n", calc1, accum);
				break;
			case '-':
				accum -= calc1;
				printf ("subtract %i to get new total of:%i\n", calc1, accum);
				break;
			case '*':
				accum *= calc1;
				printf ("multiple by %i to get new total of:%i\n", calc1, accum);
				break;
			case '/':
				if ( value2 == 0 )
					printf ("Division by zero.\n");
				else {
					accum /= calc1;
					printf ("divide by %i to get new total of:%i\n", calc1, accum);
				}
				break;
			case 'S':
				accum = calc1;
				printf ("new total = %i\n",accum);
				break;
			case 'E':
				runLoop = false;
				printf ("End program\n"); break;
				break;
			default:
				runLoop = false;
				printf ("Unknown operator.\n");
				break;
		}
	}



////////////////////////////////////////////////////////////////////////////



/*
 *
 * 6.6
 * Write a program that takes an integer keyed in from the terminal and
 * extracts and displays each digit of the integer in English. So, if the user types
 * in 932, the pro- gram should display
 *     nine three two
 *
 *
 *
 *
 * Did this two way's
 *    the first I used array's of pointers, the second using the idea of finding the number of
 *    digits and selecting them one at a time
 *
 *
 *
 */

    // Declaring/Initializing ten characters pointers
    char *ptr1 = "zero";
    char *ptr2 = "one";
    char *ptr3 = "two";
    char *ptr4 = "three";
    char *ptr5 = "four";
    char *ptr6 = "five";
    char *ptr7 = "six";
    char *ptr8 = "seven";
    char *ptr9 = "eight";
    char *ptr10 = "nine";

    char *pointr = " ";

    //Declaring two arrays of 10 char pointers
    char* arr[10];
    char* outArr[10];

    // Initializing the input array with values
    arr[0] = ptr1;
    arr[1] = ptr2;
    arr[2] = ptr3;
    arr[3] = ptr4;
    arr[4] = ptr5;
    arr[5] = ptr6;
    arr[6] = ptr7;
    arr[7] = ptr8;
    arr[8] = ptr9;
    arr[9] = ptr10;

    // Initializing the output array
    for(int i23 = 0 ; i23 < 10 ; ++i23)
    	outArr[i23] = pointr;


	int keyedValue;
	int digit;
	int cntr = 9;
	_Bool isTrue = true;

	printf("key in number --> ");
	//scanf("%i", &keyedValue);
	keyedValue = 345;
	printf("\n");
	while (isTrue) {
		if (keyedValue < 10) {
			isTrue = false;
			outArr [cntr] = arr[keyedValue];
			//printf("%s ", arr[keyedValue]);
		}
			else {
				digit = keyedValue % 10;
				keyedValue /= 10;
				outArr[cntr] = arr[digit];
				//printf("%s ", arr[digit]);
			}
		--cntr;
		}
	printf("%s %s %s %s %s %s %s %s %s %s\n", outArr[0], outArr[1], outArr[2], outArr[3], outArr[4], outArr[5], outArr[6], outArr[7], outArr[8], outArr[9] );



	/*
	 * this is the second way, which does a while loop to count the number of
	 * thousands (factor) and then divide by that many to pop the digits off
	 */

	  int num,temp3,factor=1;

	  printf("Enter a number: ");
	  //scanf("%d",&num);
	  num = 67567;
	  temp3=num;
	  while(temp3){
	      temp3=temp3/10;
	      factor = factor*10;
	  }

	  printf("Each digits of given number are: ");
	  while(factor>1){
	      factor = factor/10;
			switch (num/factor) {
				case 0:
					printf ("zero ");
					break;
				case 1:
					printf ("one ");
					break;
				case 2:
					printf ("two ");
					break;
				case 3:
					printf ("three ");
					break;
				case 4:
					printf ("four ");
					break;
				case 5:
					printf ("five ");
					break;
				case 6:
					printf ("six ");
					break;
				case 7:
					printf ("seven ");
					break;
				case 8:
					printf ("eight ");
					break;
				case 9:
					printf ("nine ");
					break;
				default:
					printf ("Unknown\n");
					break;
			}
	      //printf("%d ",num/factor);
	      num = num % factor;
	  }

	  printf("\n");

/*

	unsigned int count2(unsigned int i2) {
	 unsigned int ret2=1;
	 while (i2/=10) ret2++;
	 return ret2;
	}



	unsigned int num=123; //for example
	unsigned int dig3=count2(num);
	char arr3[dig3];
	while (dig3--) {
	 arr3[dig3]=num%10;
	 num/=10;
	}

*/



/*!
 *
 * 7.4
 * Write a program that calculates the average of an array of 10 floating-point values.
 *
 *
 *
 */

	  float array2[10];
	  float sum3 = 0;
	  int cnt1;

	  for ( cnt1=1; cnt1<10 ; ++cnt1 ) {
		  printf("Enter number: \n");
	  	  //scanf("%f",&array2[cnt1]);
		  array2[cnt1] = 4.567+cnt1;
	  }

	  for ( cnt1=1; cnt1<10 ; ++cnt1 ) {
	      sum3 += array2[cnt1];
	  }

	  printf("Avg of these 10 numbers is: %f\n",sum3/cnt1);



		float values[10] = {
			0.1, 1.2, 2.3, 3.4, 4.5,
			5.6, 6.7, 7.8, 8.9, 9.0
		};
		int count22 = sizeof(values) / sizeof(float);   	//way to count number of attributes in an array

		float sum = 0;

		for ( int i = 0; i < count22; i++ )
			sum += values[i];

		printf ("Average: %.2f\n", sum / count);

		return EXIT_SUCCESS;
}
