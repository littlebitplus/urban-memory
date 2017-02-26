/*
 * commandArguments.c
 *
 *  Created on: Feb 26, 2017
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include "wildfire.h"
#include <unistd.h>

void commandArguments(int argc, char * argv[])
{

/*
 * The two options "h" and "H" do not expect anything else after them
 * where the options b, c, d, n, p and s, if used, need a number ... i.e. -b11 -p2
 *
 */

	while ((option = getopt(argc, argv, "Hhb:c:d:n:p:s:")) != -1)
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
			pNeighbors = atoi(optarg);
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

	if (pNeighbors == -1)
	{
		pNeighbors = DEFAULT_PROP_NEIGHBOR;
	}
	else if ((pNeighbors < 0) || (pNeighbors > 100))
	{
		fprintf(stderr,
				"(-nN) %%neighbors influence catching fire must be an integer in [0...100].\n");
		print_usage();
		exit(EXIT_FAILURE);
	}

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

}
