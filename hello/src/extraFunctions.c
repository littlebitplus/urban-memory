/*
 * extraFunctions.c
 *
 *  Created on: Feb 14, 2017
 *      Author: halburt
 */

#include <stdio.h>

void sort (int a[], int n, int ascending)
{
	int i, j, temp;

	for ( i = 0; i < n - 1; ++i )
		for ( j = i + 1; j < n; ++j )
			if ( (ascending && a[i] > a[j]) || (!ascending && a[i] < a[j]) ) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
}


	int calculateTriangularNumber (int n)
	{
		int i, triangularNumber = 0;

		for(i=1; i<=n; ++i) triangularNumber += i;
			printf ("Triangular number %i is %i\n", n, triangularNumber);
		return (triangularNumber);
	}
