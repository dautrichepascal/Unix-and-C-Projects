/*
Name: initialisation.c by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions used to initialise the snakeBoard
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "initialisation.h"
#include "macros.h"
#include "random.h"

/*
Name: initSnakeBoard
Purpose: Populates the gameboard with its borders and spaces (Must be called every time to reset the gameboard, to not allow overwriting)
Imports: char** boardArray, int* boardRows, int* boardColumns
Exports: void
*/

void initSnakeBoard(char** boardArray, int* boardRows, int* boardColumns)
{
    int i, j;

    for(i = 0; (i < *boardRows); i++)
    {
        for(j = 0; (j < *boardColumns); j++)
        {
            /*If border is met, set it to '*'*/
            if((i == 0) || (j == 0) || (j == (*boardColumns - 1)) || (i == (*boardRows - 1)))
            {
                boardArray[i][j] = 42; /* * = 42 */
            }

            else
            {
                boardArray[i][j] =  32; /* ' ' = 32 */
            }
        }
    }
}

/*
Name: printBoard
Purpose: prints out the gameboard
Imports: char** boardArray, int* rows, int* columns
Exports: void
*/

void printBoard(char** boardArray, int* rows, int* columns)
{
    int i, j;

    for(i = 0; i < *rows; i++)
    {
        for(j = 0; j < *columns; j++)
        {
            printf("%c", boardArray[i][j]);
        }
        printf("\n");
    }
}

/*
Name: foodLocation
Purpose: randomises and determines the location of the fruit
Imports: char** boardArray, int* rows, int* columns, int* xFood, int* yFood
Exports: void
*/

void foodLocation(char** boardArray, int* rows, int* columns, int* xFood, int* yFood)
{
    

    int foodPlaced;
    char isEqual;


    foodPlaced = FALSE;
    

    initRandom();

    do
    {
        /*Used randomNum as random() was not being recognised*/
        *xFood = randomNum(1, (*columns - 2));

        
        /*-2 as we are only concerned within the gameboard, 0 = boarder and (row/col) - 1 = other boarder*/
        *yFood = randomNum(1, (*rows - 2));

        isEqual = boardArray[*yFood][*xFood];
        
        if( isEqual == 32) /* ' ' = 32 */
        {
            foodPlaced = TRUE; 
        }

        

    /*Will keep itterating until the fruit doesnt overlap within the gameboard*/
    }while (!foodPlaced);
    
}

/*
Name: initSnake
Purpose: Initialises the snake and stores it within the array 
(only needs to be called once, as it is used to place the snake in its starting position)

Imports: int* snakeLen, char** snakeArray
Exports: void
*/

void initSnake(int* snakeLen, char** snakeArray)
{

    int i, count;

    count = 0;
    /*Snake tail is given to start at [1][1] on the game board, then we just build it from there*/

    for(i = 1; i <= *snakeLen; i++)
    {
        if(i == 1)
        {
            sprintf(snakeArray[count], "%d,%d,%c", 1, i, 35); /* # = 35 */
            count++;
        }

        else if((i > 1) && (i < *snakeLen))
        {
            sprintf(snakeArray[count], "%d,%d,%c", 1, i, 45); /* - = 45 */
            count++;
        }

        else
        {
            sprintf(snakeArray[count], "%d,%d,%c", 1, i, 62); /* > = 62 */
            count++;
        }
    }

}