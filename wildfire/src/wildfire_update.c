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
    int  row, col;
    char forest2[size][size];
    char forest3[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int i2 = 0; i2 < size; i2++)
        {
            forest2[i][i2] = forest[i][i2];
            forest3[i][i2] = forest[i][i2];
        }
    }

    printf("forest in wildfire_update\n");
    for (int i = 0; i < size; i++)
    {
        for (int i2 = 0; i2 < size; i2++)
        {
            printf("%c", forest[i][i2]);
        }

        puts(" ");
    }
    printf("forest2 in wildfire_update\n");
    for (int i = 0; i < size; i++)
    {
        for (int i2 = 0; i2 < size; i2++)
        {
            printf("%c", forest2[i][i2]);
        }

        puts(" ");
    }


    for (row = 1; row < size; row++)
    {
        for (col = 1; col < size; col++)
        {
            int neighbors = 0;

            if (*&forest[row][col] == 'Y')
            {
                if (forest[row - 1][col - 1] == '*')
                {
                    neighbors++;
                }

                if (forest[row - 1][col] == '*')
                {
                    neighbors++;
                }

                if (forest[row - 1][col + 1] == '*')
                {
                    neighbors++;
                }

                if (forest[row][col - 1] == '*')
                {
                    neighbors++;
                }

                if (forest[row][col + 1] == '*')
                {
                    neighbors++;
                }

                if (forest[row + 1][col - 1] == '*')
                {
                    neighbors++;
                }

                if (forest[row + 1][col] == '*')
                {
                    neighbors++;
                }

                if (forest[row + 1][col + 1] == '*')
                {
                    neighbors++;
                }

                if (neighbors > 0)
                {
                    forest2[row][col] = '*';
                }
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int i2 = 0; i2 < size; i2++)
            {
                forest[i][i2] = forest2[i][i2];
            }
        }
    }

    printf("forest2\n");
    for (int i = 0; i < size; i++)
    {
        for (int i2 = 0; i2 < size; i2++)
        {
            printf("%c", forest2[i][i2]);
        }

        puts(" ");
    }


    // to update burning tree's to burned tree's
    for (int cnt = 0; cnt < size; ++cnt)
    {
        for (row = 1; row < size; row++)
        {
            for (col = 1; col < size; col++)
            {
                if (*&forest3[row][col] == '*')
                {
                    forest[row][col] = '.';
                }
            }
        }
    }

    printf("forest3\n");
    for (int i = 0; i < size; i++)
    {
        for (int i2 = 0; i2 < size; i2++)
        {
            printf("%c", forest3[i][i2]);
        }

        puts(" ");
    }

    return;
}


//~ Formatted by Jindent --- http://www.jindent.com
