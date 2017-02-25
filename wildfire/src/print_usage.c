/*
 * print_usage.c
 *
 *  Created on: Feb 25, 2017
 *      Author: halburt
 */


#include <stdio.h>


void print_usage()
{
	fprintf(stderr, "usage: wildfire [options]\n");
	fprintf(stderr,
			"By default, the simulation runs in overlay display mode.\n");
	fprintf(stderr,
			"The -pN option makes the simulation run in print mode for up to N cycles.\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "Simulation Configuration Options:\n");
	fprintf(stderr, " -H  # View simulation options and quit.\n");
	fprintf(stderr,
			" -bN # proportion that a tree is already burning. 0 < N < 101.\n");
	fprintf(stderr,
			" -cN # probability that a tree will catch fire. 0 < N < 101.\n");
	fprintf(stderr,
			" -dN # density/proportion of trees in the grid. 0 < N < 101.\n");
	fprintf(stderr,
			" -nN # proportion of neighbors that influence a tree catching fire. -1 < N < 101.\n");
	fprintf(stderr,
			" -pN # number of cycles to print before quitting. -1 < N < ...\n");
	fprintf(stderr, " -sN # simulation grid size. 4 < N < 41.\n");
}

