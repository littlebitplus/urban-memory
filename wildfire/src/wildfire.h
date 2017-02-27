/*
 * wildfire.h
 *
 *  Created on: Feb 24, 2017
 *      Author:
 */

#ifndef WILDFIRE_H_
#define WILDFIRE_H_

/*
 * function to print usage of command line
 */
void print_usage();

/*
 * function to retrieve command line arguments
 */
void commandArguments(int argc, char * argv[]);

/*
 * function to load the initial forest
 */
void loadForest(void *forestx, int size);

/*
 * function to update the forest values
 */
_Bool updateForest(void *forestx, void *foresty, int size);

/*
 * GLOBAL DEFINITIONS
 */
const char EMPTY;
const char LIVE_TREE;
const char BURNING_TREE;
const char BURNED_TREE;
const char HOLD_TREE;
int DEFAULT_BURN;
int DEFAULT_PROB_CATCH;
int DEFAULT_DENSITY;
int DEFAULT_PROP_NEIGHBOR;
_Bool DEFAULT_PRINT_COUNT;
int DEFAULT_CYCLES;    // wasn't specified but used for my testing
int DEFAULT_SIZE;
int burn;
int pCatch;
int density;
int pNeighbors;
int size;
int assignment;
int cycles;
int option;
int changesPerCycle;
int cummulativeChanges;

#endif /* WILDFIRE_H_ */
