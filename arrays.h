/*
Name: arrays.h by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions for arrays.c, enabling forward declaractions
*/


#ifndef ARRAYS_H
#define ARRAYS_H

char** make2dCharArray(char** charArray, int *numRows,int  *numColumns);
int** make2dIntArray(int** intArray, int *numRows,int  *numColumns);
void freeIntArray(int** intArray, int *numRows,int  *numColumns);
void freeCharArray(char** charArray, int *numRows,int  *numColumns);

#endif