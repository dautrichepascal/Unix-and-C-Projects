/*
Name: main.c by Pascal d'Autriche (20190826)
Purpose: Runs the entire snake game
NOTE: ASCII Characters were used throughout the program as the project was described as being 'ASCII based'
*/

#include <stdio.h>
#include <stdlib.h>

#include "startgame.h"

int main (int argc, char** argv)
{
    
    int numArgs, rowMap, colMap, snakeLength;

    /*Malloc the row, column and length as they will be referred to throughout the entire program*/

    int *rowPtr = (int*)(malloc(sizeof(int)));
    int *colPtr = (int*)(malloc(sizeof(int)));
    int *lenPtr = (int*)(malloc(sizeof(int)));

    numArgs = argc;

    /*assigning each of the command line arguments (height)(width)(Snake Length)*/
    if(numArgs != 4)
    {
        printf("\n\t\tInvalid number of entries!! \n\n\t<row length> <column length> <snake length>\n\n");
    }

    else
    {

        
        rowMap = atoi(argv[1]);
        colMap = atoi(argv[2]);
        snakeLength = atoi(argv[3]);

        *rowPtr = rowMap;
        *colPtr = colMap;
        *lenPtr = snakeLength;

        /*Conditions to be met before the program can start*/

        if( (numArgs == 4) && (rowMap >= 5) && (rowMap <= 99) && (colMap >= 5) && (colMap <= 99) && (snakeLength >= 3) && (snakeLength <= colMap))
        {
            letsPlay(rowPtr, colPtr, lenPtr);
        }

        /*Did repeated if statements so the user knows after one go all of the 
        changes that need to be made instead of using if - elseif - else statements 
        because only one error will always print*/
        else
        {
        

            if(rowMap < 5 || rowMap > 99)
            {
                printf("\nThe Height of the map must be between 5 and 99 inclusive!!\n\n");
            }

            if(colMap < 5 || colMap > 99)
            {
                printf("\nThe Width of the map must be between 5 and 99 inclusive!!\n\n");
            }

            if(snakeLength < 3)
            {
                printf("\nThe Snake Length must be at least 3!!\n\n");
            }

            if(snakeLength > colMap)
            {
                printf("\nThe Snake Length must be no more than the Width of the Map!!\n\n");
            }
        }
    }
    
    /*Freeing the pointers at the end of the program (when it is necessary)*/
    free(rowPtr);
    rowPtr = NULL;

    free(colPtr);
    colPtr = NULL;

    free(lenPtr);
    lenPtr = NULL;

    return 0;
}