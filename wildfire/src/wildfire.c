/*
 * ==============================================================================
 * Name        : wildfire.c
 * Author      : x
 * Version     : 1.0
 * Created         : 2017/02/23
 *
 * Description :
 *                        :
 *
 * Steps           :
 *                        :
 *                        :
 *
 *
 * Notes           : Compile
 *                        : gcc -Wall -Wextra -std=c99 -pedantic wildfire.c -o wildfire
 *                        : Compile with debug
 *                        : gcc -Wall -Wextra -std=c99 -pedantic -g wildfire.c -o wildfire
 *                        : Added to git
 * ==============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include "wildfire.h"
#include <time.h>

// GLOBAL VARIABLES DEFINED IN HEADER, ASSIGNED VALUES IN WILDFIRE
const char EMPTY = ' ';
const char LIVE_TREE = 'Y';
const char BURNING_TREE = '*';
const char BURNED_TREE = '.';
const char HOLD_TREE = '$';
int DEFAULT_BURN = 10;
int DEFAULT_PROB_CATCH = 30;
int DEFAULT_DENSITY = 50;
int DEFAULT_PROP_NEIGHBOR = 25;
_Bool DEFAULT_PRINT_COUNT = 1; //need to change this to 0 when adding visualization
int DEFAULT_CYCLES = 10;    // wasn't specified but i needed for testing
int DEFAULT_SIZE = 10;
int burn = -1;
int pCatch = -1;
int density = -1;
int pNeighbors = -1;
int size = -1;
int cycles = -1;
int option = 0;
int changesPerCycle = 0;
int cummulativeChanges = 0;
double randomDensity;
double randomBurning;

int main(int argc, char * argv[])
{

	/*
	 * bring in command line arguments, and set parameters
	 */

	commandArguments(argc, argv);

	/*
	 * create the forest of the correct size
	 */

	char forest[size][size];

	/*
	 * load up forest
	 */

	//srandom(time(0));
	//srandom(41);	//for consistent testing
	srandom(33);	//for consistent testing
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

	/*
	 * print out info about trees for debug
	 */
	int countLiveTree = 0;
	int countBurningTree = 0;

	for (int i = 0; i < size; i++)
	{
		for (int i2 = 0; i2 < size; i2++)
		{
			//printf("%c", forest[i][i2]);
			if (forest[i][i2] == LIVE_TREE)
				countLiveTree++;
			if (forest[i][i2] == BURNING_TREE)
				countBurningTree++;
		}
		//puts(" ");
	}
	printf("count live trees = %i, count burning trees = %i\n", countLiveTree,
			countBurningTree);
	puts(" ");

	/*
	 *
	 * Loop through the cycles - main work done here
	 *
	 */
	_Bool main_STILL_BURNING = 0;

	for (int cnt = 0; cnt < cycles; cnt++)
	{

		/*
		 * print out forest
		 */
		for (int i = 0; i < size; i++)
		{
			for (int i2 = 0; i2 < size; i2++)
			{
				printf("%c", forest[i][i2]);
			}
			puts(" ");
		}

		/*
		 * Print header lines
		 */
		printf(
				"size %i, pCatch %.2f, density %.2f, pBurning %.2f, pNeighbor %.2f\n",
				size, (double) pCatch / 100, (double) density / 100,
				(double) burn / 100, (double) pNeighbors / 100);
		printf("cycle %i, changes %i, cumulative changes %i\n", cnt,
				changesPerCycle, cummulativeChanges);


		main_STILL_BURNING = updateForest(forest, size);//main working function


		/*
		 * poor mans way to end for now
		 */
		if (main_STILL_BURNING == 0)
		{
			cnt = 99999999;
		}
	}

	/*
	 * Print footer lines
	 */

	printf("Fires are out\n");

	return EXIT_SUCCESS;
}

//~ Formatted by Jindent --- http://www.jindent.com
