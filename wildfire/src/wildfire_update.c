/*
 * wildfire_update.c
 *
 *  Created on: Feb 24, 2017
 *      Author: halburt
 */

#include <stdio.h>

void updateForest(char forest[][10],
                  int  size)
{
    int row, col;

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

    // to handle the first row, don't have to check above it
    // to handle the last row, don't have to check below it
    // to handle the first column, don't have to check to the left
    // to handle the last column, don't have to check to the right
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            int neighbors = 0;

            if (*&forest[row][col] == 'Y')
            {
                if (row > 0)
                {
                    if (col > 0)
                    {
                        if (forest[row - 1][col - 1] == '*')
                        {
                            neighbors++;
                        }
                    }
                }

                if (row > 0)
                {
                    if (forest[row - 1][col] == '*')
                    {
                        neighbors++;
                    }
                }

                if (row > 0)
                {
                    if (col != size)
                    {
                        if (forest[row - 1][col + 1] == '*')
                        {
                            neighbors++;
                        }
                    }
                }

                if (col > 0)
                {
                    if (forest[row][col - 1] == '*')
                    {
                        neighbors++;
                    }
                }

                if (col != size)
                {
                    if (forest[row][col + 1] == '*')
                    {
                        neighbors++;
                    }
                }

                if (col > 0)
                {
                    if (row != size)
                    {
                        if (forest[row + 1][col - 1] == '*')
                        {
                            neighbors++;
                        }
                    }
                }

                if (row != size)
                {
                    if (forest[row + 1][col] == '*')
                    {
                        neighbors++;
                    }
                }

                if (row != size)
                {
                    if (col != size)
                    {
                        if (forest[row + 1][col + 1] == '*')
                        {
                            neighbors++;
                        }
                    }
                }

                if (neighbors > 0)
                {
                    forest[row][col] = '$';
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
                if (*&forest[row][col] == '*')
                {
                    forest[row][col] = '.';
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
                if (*&forest[row][col] == '$')
                {
                    forest[row][col] = '*';
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
