/*
 * wildfire_update.c
 *
 *  Created on: Feb 24, 2017
 *      Author: halburt
 */

#include <stdio.h>
#include <stdlib.h>
#include "wildfire.h"

//void updateForest(char forest[][10],                   int  size)

void updateForest(void *forestx, int size)
{
	int row, col;
	double randomProbability;
	char (*forest)[size] = forestx;
	/*
	 *
	 *   char forest2[size][size];
	 *   char forest3[size][size];
	 *
	 *   for (int i = 0; i < size; i++)
	 *   {
	 *       for (int i2 = 0; i2 < size; i2++)
	 *       {
	 *           forest2[i][i2] = forest[i][i2];
	 *           forest3[i][i2] = forest[i][i2];
	 *       }
	 *   }
	 *
	 *   printf("forest in wildfire_update\n");
	 *   for (int i = 0; i < size; i++)
	 *   {
	 *       for (int i2 = 0; i2 < size; i2++)
	 *       {
	 *           printf("%c", forest[i][i2]);
	 *       }
	 *
	 *       puts(" ");
	 *   }
	 *   printf("forest2 in wildfire_update\n");
	 *   for (int i = 0; i < size; i++)
	 *   {
	 *       for (int i2 = 0; i2 < size; i2++)
	 *       {
	 *           printf("%c", forest2[i][i2]);
	 *       }
	 *
	 *       puts(" ");
	 *   }
	 */

	//calculate the probability that the tree's will catch fire
	//first time through this was between 0, 1, all other times it was, so ran once just to get out of the way
	randomProbability = (double) rand() / (double) RAND_MAX;

	// to handle the first row, don't have to check above it
	// to handle the last row, don't have to check below it
	// to handle the first column, don't have to check to the left
	// to handle the last column, don't have to check to the right
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

//                if (neighbors >= proportion)

				if (neighbors >= proportion)
				{
					randomProbability = (double) rand() / (double) RAND_MAX;
					if (randomProbability >= ((double) probability / 100))

						forest[row][col] = HOLD_TREE;
				}
			}
		}
	}

	/*
	 *       for (int i = 0; i < size; i++)
	 *       {
	 *           for (int i2 = 0; i2 < size; i2++)
	 *           {
	 *               forest[i][i2] = forest2[i][i2];
	 *           }
	 *       }
	 *
	 *   }
	 *
	 *   printf("forest2\n");
	 *   for (int i = 0; i < size; i++)
	 *   {
	 *       for (int i2 = 0; i2 < size; i2++)
	 *       {
	 *           printf("%c", forest2[i][i2]);
	 *       }
	 *
	 *       puts(" ");
	 *   }
	 */

	// to update burning tree's to burned tree's
	for (int cnt = 0; cnt < size; ++cnt)
	{
		for (row = 0; row < size; row++)
		{
			for (col = 0; col < size; col++)
			{
				if (*&forest[row][col] == BURNING_TREE)
				{
					forest[row][col] = BURNED_TREE;
				}
			}
		}
	}

	// to update hold burning tree's to actual burned tree's
	for (int cnt = 0; cnt < size; ++cnt)
	{
		for (row = 0; row < size; row++)
		{
			for (col = 0; col < size; col++)
			{
				if (*&forest[row][col] == HOLD_TREE)
				{
					forest[row][col] = BURNING_TREE;
				}
			}
		}
	}

	/*
	 *   printf("forest3\n");
	 *   for (int i = 0; i < size; i++)
	 *   {
	 *       for (int i2 = 0; i2 < size; i2++)
	 *       {
	 *           printf("%c", forest3[i][i2]);
	 *       }
	 *
	 *       puts(" ");
	 *   }
	 */
	return;
}

//~ Formatted by Jindent --- http://www.jindent.com
