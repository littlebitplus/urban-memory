/*
 * loadForest.c
 *
 *  Created on: Feb 26, 2017
 *      Author: halburt
 */

/*
 * createForest.c
 *
 *  Created on: Feb 26, 2017
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "wildfire.h"

double randomDensity;
double randomBurning;

void loadForest(void *forestx, int size)
{

	char (*forest)[size] = forestx;

	/*
	 * load up forest
	 */

	/*
	 * allow for option of fully loaded forest, or, random
	 */

	if (assignment == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int i2 = 0; i2 < size; i2++)
			{
				forest[i][i2] = LIVE_TREE;
			}
		}
		forest[size / 2][size / 2] = BURNING_TREE;
	}
	else
	{
		//srandom(time(0));
		srandom(41);	//for consistent testing

		for (int i = 0; i < size; i++)
		{
			for (int i2 = 0; i2 < size; i2++)
			{
				randomDensity = (double) random() / ((double) RAND_MAX + 1);
				if (randomDensity < ((double) density / 100))
				{
					randomBurning = (double) random() / ((double) RAND_MAX + 1);
					if (randomBurning < ((double) burn / 100))
					{
						forest[i][i2] = BURNING_TREE;
					}
					else
					{
						forest[i][i2] = LIVE_TREE;
					}
				}
				else
				{
					forest[i][i2] = EMPTY;
				}
			}
		}
	}
}

