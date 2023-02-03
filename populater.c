/*
Name: populater.c by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions revolving around populating the game board
*/

#include <stdio.h>

#include "populater.h"
#include "initialisation.h"

/*
Name: populateBoard
Purpose: Adds the snake into the game board
Imports: char** boardArray, int* snakeLen, char** snakeArray
Exports: void
*/

void populateBoard(char** boardArray, int* snakeLen, char** snakeArray)
{

    int i, currentX, currentY;
    char currentChar;

    currentX = 0;
    currentY = 0;
    currentChar = 'z';

    
    for(i = 0; i < *snakeLen; i++)
    {
        /*Strips the snake board into currentX, currentY and currentChar*/
        sscanf(snakeArray[i], "%d,%d,%c", &currentX, &currentY, &currentChar);
        boardArray[currentX][currentY] = currentChar;
    }

}

/*
Name: updateAndPopulate
Purpose: Is only used so that 4 functions do not repeatedly have to be used, it clears the board, adds the food then snake into the board and prints the result
Imports: char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood
Exports: void
*/

void updateAndPopulate(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood)
{
    initSnakeBoard(boardArray, boardRows, boardColumns);
    boardArray[*yFood][*xFood] = 64; /* @ = 64 */
    populateBoard(boardArray, snakeLen, snakeArray);
    printBoard(boardArray, boardRows, boardColumns);

}

/*
Name: breakArray
Purpose: breaks down snake array and stores its components in its appropriate arrays
Imports: char** snakeArray, int* snakeLength, int* xArray, int* yArray, char* charArray
Exports: void
*/

void breakArray(char** snakeArray, int* snakeLength, int* xArray, int* yArray, char* charArray)
{

    int i, tempX, tempY;
    char tempChar;

    tempChar = 'z';
    tempX = 0;
    tempY = 0;

    for(i = 0; i < *snakeLength; i++)
    {
        /*Stores tempX, tempY and tempChar into each array element*/
        sscanf(snakeArray[i], "%d,%d,%c",&tempX ,&tempY ,&tempChar);
        xArray[i] = tempX;
        yArray[i] = tempY;
        charArray[i] = tempChar;
    }

}

/*
Name: recombineSnake
Purpose: Takes the 3 arrays that build up the data within the snake and recombines them to make the snakeArray
Imports: char** snakeArray, int* snakeLen, int* xArray, int* yArray, char* charArray
Exports: void
*/

void recombineSnake(char** snakeArray, int* snakeLen, int* xArray, int* yArray, char* charArray)
{

    int i;

    for(i = 0; i < *snakeLen; i++)
    {
        sprintf(snakeArray[i], "%d,%d,%c", xArray[i], yArray[i], charArray[i]);
    }

}