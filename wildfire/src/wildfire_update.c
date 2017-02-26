/*
 * wildfire_update.c
 *
 *  Created on: Feb 24, 2017
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include "wildfire.h"

_Bool updateForest(void *forestx, int size)
{
	int row, col;
	double randomProbability;
	char (*forest)[size] = forestx;
	_Bool function_STILL_BURNING;

	function_STILL_BURNING = 0;
	changesPerCycle = 0;

	/*
	 * calculate the probability that the tree's will catch fire
	 * to handle the first row, don't have to check above it
	 * to handle the last row, don't have to check below it
	 * to handle the first column, don't have to check to the left
	 * to handle the last column, don't have to check to the right
	 *
	 */

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			int neighbors = 0;
			int minBurningNeighbors = 0;

			if (*&forest[row][col] == LIVE_TREE)
			{
				if (row > 0)
				{
					if (col > 0)
					{
						if (forest[row - 1][col - 1] == BURNING_TREE)
						{
							neighbors++;
						}
					}
				}

				if (row > 0)
				{
					if (forest[row - 1][col] == BURNING_TREE)
					{
						neighbors++;
					}
				}

				if (row > 0)
				{
					if (col != size - 1)
					{
						if (forest[row - 1][col + 1] == BURNING_TREE)
						{
							neighbors++;
						}
					}
				}

				if (col > 0)
				{
					if (forest[row][col - 1] == BURNING_TREE)
					{
						neighbors++;
					}
				}

				if (col != size - 1)
				{
					if (forest[row][col + 1] == BURNING_TREE)
					{
						neighbors++;
					}
				}

				if (col > 0)
				{
					if (row != size - 1)
					{
						if (forest[row + 1][col - 1] == BURNING_TREE)
						{
							neighbors++;
						}
					}
				}

				if (row != size - 1)
				{
					if (forest[row + 1][col] == BURNING_TREE)
					{
						neighbors++;
					}
				}

				if (row != size - 1)
				{
					if (col != size - 1)
					{
						if (forest[row + 1][col + 1] == BURNING_TREE)
						{
							neighbors++;
						}
					}
				}

				/*
				 * calculate the proportion of neighbors needed to set this off, since row 0 col 0 have less neighbors possible
				 */

				if (row == 0 || row == size - 1)
				{
					if (col == 0 || col == size - 1)
					{
						minBurningNeighbors = (3 * ((double) pNeighbors / 100));
					}
					else
					{
						minBurningNeighbors = (5 * ((double) pNeighbors / 100));
					}
				}
				else
				{
					if (col == 0 || col == size - 1)
					{
						minBurningNeighbors = (5 * ((double) pNeighbors / 100));
					}
					else
					{
						minBurningNeighbors = (8 * ((double) pNeighbors / 100));
					}
				}
				if (minBurningNeighbors == 0) //to make it so if the percentage is less than 1
					minBurningNeighbors = 100; //(which will = 0) it won't match

				if (neighbors >= minBurningNeighbors)
				{
					randomProbability = (double) random()
							/ ((double) RAND_MAX + 1);
					if (randomProbability <= ((double) pCatch / 100))
					{
						forest[row][col] = HOLD_TREE;		//set to temp value first
						changesPerCycle++;
						cummulativeChanges++;
					}
				}
			}
		}
	}

	/*
	 *  to update burning tree's to burned tree's
	 */

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (*&forest[row][col] == BURNING_TREE)
			{
				forest[row][col] = BURNED_TREE;
				changesPerCycle++;
				cummulativeChanges++;
			}
		}
	}

	/*
	 * to update hold burning tree's to actual burning tree's
	 */

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			if (*&forest[row][col] == HOLD_TREE)
			{
				forest[row][col] = BURNING_TREE;
				function_STILL_BURNING = 1;				//if any are still burning, continue run
			}
		}
	}

	return (function_STILL_BURNING);
}

