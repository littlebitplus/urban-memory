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
#include <stdbool.h>
#include "wildfire.h"

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
int assignment = -1;
int lightning = -1;
int cycles = -1;
int option = 0;
int changesPerCycle = 0;
int cummulativeChanges = 0;

//LOCAL VARIABLES
_Bool main_STILL_BURNING = 0;

int main(int argc, char * argv[])
{

	/*
	 * bring in command line arguments and set parameters
	 */

	commandArguments(argc, argv);

	/*
	 * create the forest of the correct size
	 */

	char forest[size][size];
	char forestTwo[size][size];		//for assignment 6 - two time cycles

	/*
	 * load the forest with live and burning trees, and empty spaces
	 */
	loadForest(forest, size);

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
	 * copy forest for assignment 6
	 */
	for (int i = 0; i < size; i++)
	{
		for (int i2 = 0; i2 < size; i2++)
		{
			forestTwo[i][i2] = EMPTY;
		}
	}

	/*
	 * Loop through the cycles - main work done here  -  only focused on print case, not display assignment
	 */
	int loopCnt = 0;
	for (int cnt = 0; cnt < cycles; cnt++)
	{

		/*
		 * Print lines within loop
		 */
		printf(
				"size %i, pCatch %.2f, density %.2f, pBurning %.2f, pNeighbor %.2f\n",
				size, (double) pCatch / 100, (double) density / 100,
				(double) burn / 100, (double) pNeighbors / 100);
		printf("cycle %i, changes %i, cumulative changes %i\n", loopCnt,
				changesPerCycle, cummulativeChanges);

		/*
		 * Update the forest with changes
		 */
		main_STILL_BURNING = updateForest(forest, forestTwo, size); //main working function

		/*
		 * print out forest within loop
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
		 * increment loop counter since breaking loop by making cnt 9999999
		 */
		loopCnt++;

		/*
		 * poor mans way to end for now
		 */
		if (main_STILL_BURNING == 0)
		{
			cnt = 99999999;
		}
	}

	/*
	 * Print closing lines
	 */
	printf(
			"size %i, pCatch %.2f, density %.2f, pBurning %.2f, pNeighbor %.2f\n",
			size, (double) pCatch / 100, (double) density / 100,
			(double) burn / 100, (double) pNeighbors / 100);
	printf("cycle %i, changes %i, cumulative changes %i\n", loopCnt,
			changesPerCycle, cummulativeChanges);
	printf("Fires are out\n");

	return EXIT_SUCCESS;
}
