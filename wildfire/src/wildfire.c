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
_Bool DEFAULT_PRINT_COUNT = 1;
int DEFAULT_CYCLES = 10;    // wasn't specified but i needed for testing
int DEFAULT_SIZE = 20;
int burn = -1;
int pCatch = -1;
int density = -1;
int proportion = -1;
int size = -1;
int cycles = -1;
int option = 0;
double randomDensity;
double randomBurning;



int main(int argc, char * argv[])
{

	// printf ("Number of arguments = %i\n", argc);
	// Specifying the expected options
	// The two options h and H do not expect any numbers after them
	// the options b, c, d, n, p and s, if used, need a number ... i.e. -b11 -p2
	while ((option = getopt(argc, argv, "Hhb:c:d:n:p:s")) != -1)
	{
		switch (option)
		{
		case 'H':
			print_usage();
			exit(EXIT_SUCCESS);
		case 'h':
			print_usage();
			exit(EXIT_SUCCESS);
		case 'b':
			burn = atoi(optarg);
			break;
		case 'c':
			pCatch = atoi(optarg);
			break;
		case 'd':
			density = atoi(optarg);
			break;
		case 'n':
			proportion = atoi(optarg);
			break;
		case 'p':
			cycles = atoi(optarg);
			break;
		case 's':
			size = atoi(optarg);
			break;
		default:
			print_usage();
			exit(EXIT_FAILURE);
		}
	}

	if (burn == -1)
	{
		burn = DEFAULT_BURN;
	}
	else if ((burn < 1) || (burn > 100))
	{
		fprintf(stderr,
				"(-bN) proportion already burning. must be an integer in [1...100].\n");
		print_usage();
		exit(EXIT_FAILURE);
	}

	if (pCatch == -1)
	{
		pCatch = DEFAULT_PROB_CATCH;
	}
	else if ((pCatch < 1) || (pCatch > 100))
	{
		fprintf(stderr,
				"(-cN) probability a tree will catch fire. must be an integer in [1...100].\n");
		print_usage();
		exit(EXIT_FAILURE);
	}

	if (density == -1)
	{
		density = DEFAULT_DENSITY;
	}
	else if ((density < 1) || (density > 100))
	{
		fprintf(stderr,
				"(-dN) density of trees in the grid must be an integer in [1...100].\n");
		print_usage();
		exit(EXIT_FAILURE);
	}

	if (proportion == -1)
	{
		proportion = DEFAULT_PROP_NEIGHBOR;
	}
	else if ((proportion < 0) || (proportion > 100))
	{
		fprintf(stderr,
				"(-nN) %%neighbors influence catching fire must be an integer in [0...100].\n");
		print_usage();
		exit(EXIT_FAILURE);
	}
//need to work on this, since isn't always going to be 8 neighbors, but for now....
	proportion = (8 * ((double) proportion / 100));

	if (cycles == -1)
	{
		cycles = DEFAULT_CYCLES;
	}
	else if ((cycles < 0) || (cycles > 10000))
	{
		fprintf(stderr,
				"(-pN) number of cycles to print. must be an integer in [0...10000].\n");
		print_usage();
		exit(EXIT_FAILURE);
	}

	if (size == -1)
	{
		size = DEFAULT_SIZE;
	}
	else if ((size < 5) || (size > 40))
	{
		fprintf(stderr,
				"(-sN) simulation grid size must be an integer in [5...40].\n");
		print_usage();
		exit(EXIT_FAILURE);
	}

	/*
	 * create the forest of the correct size
	 */
	char forest[size][size];

	/*
	 * load up forest
	 */
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		for (int i2 = 0; i2 < size; i2++)
		{
			randomDensity = (double) rand() / ((double) RAND_MAX + 1);
			if (randomDensity < ((double) density / 100))
			{
				randomBurning = (double) rand() / ((double) RAND_MAX + 1);
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
	 * Print header lines though not sure what exactly they're to be
	 */
	printf("The program cleared the screen here\n");
	printf("header 22222\n");
	puts(" ");

	/*
	 * print out forest
	 */
	int countLiveTree = 0;
	int countBurningTree = 0;

	puts(" ");
	puts(" ");
	printf("@@@@@ cycle #0 @@@@@\n");
	puts(" ");

	for (int i = 0; i < size; i++)
	{
		for (int i2 = 0; i2 < size; i2++)
		{
			printf("%c", forest[i][i2]);
			if (forest[i][i2] == LIVE_TREE)
				countLiveTree++;
			if (forest[i][i2] == BURNING_TREE)
				countBurningTree++;
		}
		puts(" ");
	}

	printf("count live trees = %i, count burning trees = %i\n", countLiveTree,
			countBurningTree);

	/*
	 *
	 * Loop through the cycles - main work done here
	 *
	 */
	_Bool main_STILL_BURNING = 0;

	for (int cnt = 1; cnt < cycles + 1; cnt++)
	{
		main_STILL_BURNING = updateForest(forest, size);	//main working function

		puts(" ");
		puts(" ");
		printf("@@@@@ cycle #%i @@@@@\n", cnt);
		puts(" ");
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
		if (main_STILL_BURNING == 0)
			cnt = 99999999;
	}

	/*
	 * Print footer lines
	 */
	printf(
			"size %i, pCatch %.2f, density %.2f, pBurning %.2f, pNeighbor %.2f\n",
			size, (double) pCatch / 100, (double) density / 100,
			(double) proportion / 100, (double) burn / 100);
	printf("cycle %i, changes %i, cumulative changes %i\n", cycles, cycles,
			cycles);
	printf("Fires are out\n");

	return EXIT_SUCCESS;
}

//~ Formatted by Jindent --- http://www.jindent.com
