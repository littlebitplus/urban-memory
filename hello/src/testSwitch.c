/*
 * testSwitch.c
 *
 *  Created on: Feb 10, 2017
 *      Author: halburt
 */
#include <stdio.h>

int testSwitch(float val1, char oper, float val2) {

	switch (oper) {
		case '+':
			printf ("%.2f\n", val1 + val2);
			break;
		case '-':
			printf ("%.2f\n", val1 - val2);
			break;
		case '*':
			printf ("%.2f\n", val1 * val2);
			break;
		case '/':
			if ( val2 == 0 )
				printf ("Division by zero.\n");
			else
				printf ("%.2f\n", val1 / val2);
			break;
		default:
			printf ("Unknown operator.\n"); break;
	}

	return (0);
}




