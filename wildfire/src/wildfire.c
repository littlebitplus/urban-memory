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


// GLOBAL VARIABLES DEFINED IN HEADER, ASSIGNED VALUES IN WILDFIRE
const char EMPTY        = ' ';
const char LIVE_TREE    = 'Y';
const char BURNING_TREE = '*';
const char BURNED_TREE  = '.';
const char HOLD_TREE    = '$';


void print_usage()
{
    fprintf(stderr, "usage: wildfire [options]\n");
    fprintf(stderr, "By default, the simulation runs in overlay display mode.\n");
    fprintf(stderr, "The -pN option makes the simulation run in print mode for up to N cycles.\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "Simulation Configuration Options:\n");
    fprintf(stderr, " -H  # View simulation options and quit.\n");
    fprintf(stderr, " -bN # proportion that a tree is already burning. 0 < N < 101.\n");
    fprintf(stderr, " -cN # probability that a tree will catch fire. 0 < N < 101.\n");
    fprintf(stderr, " -dN # density/proportion of trees in the grid. 0 < N < 101.\n");
    fprintf(stderr, " -nN # proportion of neighbors that influence a tree catching fire. -1 < N < 101.\n");
    fprintf(stderr, " -pN # number of cycles to print before quitting. -1 < N < ...\n");
    fprintf(stderr, " -sN # simulation grid size. 4 < N < 41.\n");
}

int main(int    argc,
         char * argv[])
{
    int   DEFAULT_BURN          = 10;
    int   DEFAULT_PROB_CATCH    = 30;
    int   DEFAULT_DENSITY       = 50;
    int   DEFAULT_PROP_NEIGHBOR = 25;
    _Bool DEFAULT_PRINT_COUNT   = 1;
    int   DEFAULT_CYCLES        = 10;    // wasn't specificied
    int   DEFAULT_SIZE          = 20;
    int   burn                  = -1;
    int   probability           = -1;
    int   density               = -1;
    int   proportion            = -1;
    int   size                  = -1;
    int   cycles                = -1;
    int   option                = 0;

    // printf ("Number of arguments = %i\n", argc);
    // Specifying the expected options
    // The two options h and H do not expect any numbers after them
    // the options b, c, d, n, p and s, if used, need a number ... i.e. -b11 -p2
    while ((option = getopt(argc, argv, "Hhb:c:d:n:p:s")) != -1)
    {
        switch (option)
        {
            case 'H' :
                print_usage();
                exit(EXIT_SUCCESS);
            case 'h' :
                print_usage();
                exit(EXIT_SUCCESS);
            case 'b' :
                burn = atoi(optarg);

                break;

            case 'c' :
                probability = atoi(optarg);

                break;

            case 'd' :
                density = atoi(optarg);

                break;

            case 'n' :
                proportion = atoi(optarg);

                break;

            case 'p' :
                cycles = atoi(optarg);

                break;

            case 's' :
                size = atoi(optarg);

                break;

            default :
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
        fprintf(stderr, "(-bN) proportion already burning. must be an integer in [1...100].\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    if (probability == -1)
    {
        probability = DEFAULT_PROB_CATCH;
    }
    else if ((probability < 1) || (probability > 100))
    {
        fprintf(stderr, "(-cN) probability a tree will catch fire. must be an integer in [1...100].\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    if (density == -1)
    {
        density = DEFAULT_DENSITY;
    }
    else if ((density < 1) || (density > 100))
    {
        fprintf(stderr, "(-dN) density of trees in the grid must be an integer in [1...100].\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    if (proportion == -1)
    {
        proportion = DEFAULT_PROP_NEIGHBOR;
    }
    else if ((proportion < 0) || (proportion > 100))
    {
        fprintf(stderr, "(-nN) %%neighbors influence catching fire must be an integer in [0...100].\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    if (cycles == -1)
    {
        cycles = DEFAULT_CYCLES;
    }
    else if ((cycles < 0) || (cycles > 10000))
    {
        fprintf(stderr, "(-pN) number of cycles to print. must be an integer in [0...10000].\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    if (size == -1)
    {
        size = DEFAULT_SIZE;
    }
    else if ((size < 5) || (size > 40))
    {
        fprintf(stderr, "(-sN) simulation grid size must be an integer in [5...40].\n");
        print_usage();
        exit(EXIT_FAILURE);
    }

    char forest[size][size];

    // printf("here\n");
    // load up forest with live tree's
    for (int i = 0; i < size; i++)
    {
        for (int i2 = 0; i2 < size; i2++)
        {
            forest[i][i2] = LIVE_TREE;
        }
    }

    // put in 1 burning tree
    forest[size / 2][size / 2] = BURNING_TREE;

    // printf("%c\n",forest [5][4]);
    // printf("%c\n",forest [size/2][size/2]);
    // print out forest
    printf("forest in wildfire\n");

    for (int i = 0; i < size; i++)
    {
        for (int i2 = 0; i2 < size; i2++)
        {
            printf("%c", forest[i][i2]);
        }

        puts(" ");
    }

    puts("---------");
    printf("size = %i\n", size);

    // loop through cycles
    for (int cnt = 1; cnt < cycles + 1; cnt++)
    {
        updateForest(forest, size);
        printf("cycle #%i\n", cnt);

        // print out forest
        for (int i = 0; i < size; i++)
        {
            for (int i2 = 0; i2 < size; i2++)
            {
                printf("%c", forest[i][i2]);
            }

            puts(" ");
        }
    }

    printf("The program cleared the screen here\n");
    printf("header 22222\n");
    printf("size %i, pCatch %.2f, density %.2f, pBurning %.2f, pNeighbor %.2f\n",
           size,
           (double) probability / 100,
           (double) density / 100,
           (double) proportion / 100,
           (double) burn / 100);
    printf("cycle %i, changes %i, cumulative changes %i\n", cycles, cycles, cycles);
    printf("Fires are out\n");

    return EXIT_SUCCESS;
}


//~ Formatted by Jindent --- http://www.jindent.com
