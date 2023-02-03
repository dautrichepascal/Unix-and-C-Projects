/*
Name: arrays.c by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions for creating and freeing dynamic arrays
*/

#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

/*
Name: make2dCharArray
Purpose: creates a 2d dynamic array of characters
Imports: char** charArray, int* numRows, int* numColumns
Exports: the char Array
*/

char** make2dCharArray(char** charArray, int *numRows,int  *numColumns)
{
    int i;

    charArray = (char**)(malloc((*numRows) * sizeof(char*)));

    for(i = 0; (i < *numRows); i++)
    {
        charArray[i] = (char*)(malloc((*numColumns) * sizeof(char)));
    }

    return charArray;

}

/*
Name: make2dIntArray
Purpose: creates a 2d dynamic array of integers
Imports: int** intArray, int* numRows, int* numColumns
Exports: the int Array
*/

int** make2dIntArray(int** intArray, int *numRows,int  *numColumns)
{
    int i;

    intArray = (int**)(malloc((*numRows) * sizeof(int*)));

    for(i = 0; (i < *numRows); i++)
    {
        intArray[i] = (int*)(malloc((*numColumns) * sizeof(int)));
    }

    return intArray;
}

/*
Name: freeIntArray
Purpose: frees a 2d Int array
Imports: int** intArray, int *numRows,int  *numColumns
Exports: void
*/

void freeIntArray(int** intArray, int *numRows,int  *numColumns)
{
    int i;

    for(i = 0; i < *numRows; i++)
    {
        free(intArray[i]);
        intArray[i] = NULL;
    }

    free(intArray);
    intArray = NULL;

}

/*
Name: freeCharArray
Purpose: frees a 2d Char array
Imports: char** charArray, int *numRows,int  *numColumns
Exports: void
*/

void freeCharArray(char** charArray, int *numRows,int  *numColumns)
{
    int i;

    for(i = 0; i < *numRows; i++)
    {
        free(charArray[i]);
        charArray[i] = NULL;
    }

    free(charArray);
    charArray = NULL;

}