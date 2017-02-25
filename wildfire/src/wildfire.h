/*
 * wildfire.h
 *
 *  Created on: Feb 24, 2017
 *      Author: halburt
 */

#ifndef WILDFIRE_H_
#define WILDFIRE_H_
//void updateForest(char forest[][10],
//                  int  size);


void print_usage();
_Bool updateForest(void *forestx, int size);



// GLOBAL DEFINTIONS
const char EMPTY;
;
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
int proportion;
int size;
int cycles;
int option;

#endif /* WILDFIRE_H_ */

//~ Formatted by Jindent --- http://www.jindent.com
