/*
 * wildfire_update.c
 *
 *  Created on: Feb 24, 2017
 *      Author: halburt
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

	//calculate the probability that the tree's will catch fire
	// to handle the first row, don't have to check above it
	// to handle the last row, don't have to check below it
	// to handle the first column, don't have to check to the left
	// to handle the last column, don't have to check to the right
	function_STILL_BURNING = 0;
	changesPerCycle = 0;
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{

			int neighbors = 0;

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
					if (col != size)
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

				if (col != size)
				{
					if (forest[row][col + 1] == BURNING_TREE)
					{
						neighbors++;
					}
				}

				if (col > 0)
				{
					if (row != size)
					{
						if (forest[row + 1][col - 1] == BURNING_TREE)
						{
							neighbors++;
						}
					}
				}

				if (row != size)
				{
					if (forest[row + 1][col] == BURNING_TREE)
					{
						neighbors++;
					}
				}

				if (row != size)
				{
					if (col != size)
					{
						if (forest[row + 1][col + 1] == BURNING_TREE)
						{
							neighbors++;
						}
					}
				}
				//printf("neighbors = %i, proportion = %i\n", neighbors,
				//		proportion);
				/*
				 * calculate the proportion of neighbors needed to set this off, since row 0 col 0 have less neighbors possible
				 */

				if (row == 0 || row == size)
				{
					if (col == 0 || col == size)
					{
						pNeighbors = (3 * ((double) pNeighbors / 100));
					} else
					{
						pNeighbors = (5 * ((double) pNeighbors / 100));
					}
				} else
				{
					if (col == 0 || col == size)
					{
						pNeighbors = (5 * ((double) pNeighbors / 100));
					} else
					{
						pNeighbors = (8 * ((double) pNeighbors / 100));
					}
				}




				//pNeighbors = (8 * ((double) pNeighbors / 100));

				if (neighbors >= pNeighbors)
				{
					randomProbability = (double) random()
							/ ((double) RAND_MAX + 1);
					if (randomProbability >= ((double) pCatch / 100))
					{
						forest[row][col] = HOLD_TREE;
						changesPerCycle++;
						cummulativeChanges++;
						//printf("changesPerCycle = %i, cummulatvieChanges = %i\n", changesPerCycle, cummulativeChanges);
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
				function_STILL_BURNING = 1;
			}
		}
	}

	return (function_STILL_BURNING);
}

