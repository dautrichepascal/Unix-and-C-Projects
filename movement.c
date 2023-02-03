/*
Name: movament.c by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions for allowing the snake to move
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "movement.h"
#include "arrays.h"
#include "populater.h"
#include "startgame.h"

/*
Name: slitherSnake
Purpose: make the tail of the snakeArray follow the index that comes before it
(Allows for it to slither like a snake)

Imports: char** snakeArray, int* snakeLen
Exports: void
*/

void slitherSnake(char** snakeArray, int* snakeLen)
{
    int i;

    for(i = 0; i < *snakeLen-1; i++)
    {
        strcpy(snakeArray[i], snakeArray[i+1]);
    }
}

/*
Name: whichMovement
Purpose: is a pointer function that determines whether to move up/down/left/right depending on user input
Imports: char *userInput
Exports: MovementPointer
*/

MovementPointer whichMovement(char *userInput)
{
    MovementPointer letsMove;
    letsMove = NULL;

    if(*userInput == 'w')
    {
        letsMove = &moveUp;
    }

    else if (*userInput == 'a')
    {
        letsMove = &moveLeft;
    }

    else if(*userInput == 's')
    {
        letsMove = &moveDown;
    }

    else
    {
        letsMove = &moveRight;
    }

    return letsMove;


}

/*
Name: moveRight
Purpose: moves the snake to the right on the gameboard
Imports: char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar
Exports: void
*/

void moveRight(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar)
{
    /*Initialise the Variable and pointers*/
    int nextX, nextY;
    char temp;

    int *currentX = NULL;
    int *currentY = NULL;
    char *currentChar = NULL;

    

    currentX = (int*)(malloc(*snakeLen * sizeof(int)));
    currentY = (int*)(malloc(*snakeLen * sizeof(int)));
    currentChar = (char*)(malloc(*snakeLen * sizeof(char)));

    nextX = 0;
    nextY = 0;

    /*Break snake array down into 3 1d arrays*/
    breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

    nextX = currentX[*snakeLen-1];
    nextY = currentY[*snakeLen-1];


    /*Stops snake from moving backwards*/
    if( (currentChar[*snakeLen-1]) == 60 ) /* < = 60*/
    {
        recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
        updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
        printf("Cannot go backwards\n");
    }

    else
    {
        /*Finds the char that the head will move into and stores it*/
        *nextChar = boardArray[nextX][nextY+1];

        /*Stops snake from hiting the border*/
        if( *nextChar == 42 ) /* * = 42 */
        {
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
            printf("This is a border, you cant move here!!\n");
        }

        else
        {   
            /*If the head is already > then we can slither as normal and only have to worry about changing the neck to a -*/
            if( (currentChar[*snakeLen-1]) == 62 ) /* > = 62 */
            {

                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);
                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = 45; /* - = 45 */

            }

            /*Else the head is either a ^ or V and thus we have to slither as normal and change the second last char
            (neck of snake back to what it originally was and also change the head of the snake to a >)*/
            else
            {
                temp = currentChar[*snakeLen-2];

                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);

                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = temp;

                currentChar[*snakeLen - 1] = 62; /* > = 62 */

            }

            /*Moves the snake head to the right one and sets the tail*/
            currentY[*snakeLen - 1] += 1;
            currentChar[0] = 35; /* # = 35 */
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
        }
    }


    free(currentX);
    currentX = NULL;

    free(currentY);
    currentY = NULL;

    free(currentChar);
    currentChar = NULL;

}
/*
Name: moveLeft
Purpose: moves the snake to the left on the gameboard
Imports: char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar
Exports: void
*/


void moveLeft(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar)
{
    /*Initialise the Variable and pointers*/
    int nextX, nextY;
    char temp;

    int *currentX = NULL;
    int *currentY = NULL;
    char *currentChar = NULL;

    

    currentX = (int*)(malloc(*snakeLen * sizeof(int)));
    currentY = (int*)(malloc(*snakeLen * sizeof(int)));
    currentChar = (char*)(malloc(*snakeLen * sizeof(char)));

    nextX = 0;
    nextY = 0;

    /*Break snake array down into 3 1d arrays*/
    breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

    nextX = currentX[*snakeLen-1];
    nextY = currentY[*snakeLen-1];


    /*Stops snake from moving backwards*/
    if( (currentChar[*snakeLen-1]) == 62 )/* > = 62 */
    {
        recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
        updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
        printf("Cannot go backwards\n");
    }

    else
    {
        /*Finds the char that the head will move into and stores it*/
        *nextChar = boardArray[nextX][nextY-1];

        /*Stops snake from hiting the border*/
        if( *nextChar == 42 ) /* * = 42 */
        {
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
            printf("This is a border, you cant move here!!\n");
        }

        else
        {
            /*If the head is already < then we can slither as normal and only have to worry about changing the neck to a -*/
            if( (currentChar[*snakeLen-1]) == 60 ) /* < = 60 */
            {

                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);
                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = 45; /* - = 45*/

            }

            else
            {
                /*Else the head is either a ^ or V and thus we have to slither as normal and change the second last char
                (neck of snake back to what it originally was and also change the head of the snake to a <)*/

                temp = currentChar[*snakeLen-2];
                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);

                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = temp;
                currentChar[*snakeLen - 1] = 60; /* < = 60 */

            }

            /*Moves the snake head to the left one and sets the tail*/
            currentY[*snakeLen - 1] -= 1;
            currentChar[0] = 35; /* # = 35 */
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);

        }
    }

    free(currentX);
    currentX = NULL;

    free(currentY);
    currentY = NULL;

    free(currentChar);
    currentChar = NULL;

}
/*
Name: moveUp
Purpose: moves the snake up on the gameboard
Imports: char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar
Exports: void
*/


void moveUp(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar)
{
    /*Initialise the Variable and pointers*/
    int nextX, nextY;
    char temp;

    int *currentX = NULL;
    int *currentY = NULL;
    char *currentChar = NULL;

    

    currentX = (int*)(malloc(*snakeLen * sizeof(int)));
    currentY = (int*)(malloc(*snakeLen * sizeof(int)));
    currentChar = (char*)(malloc(*snakeLen * sizeof(char)));

    nextX = 0;
    nextY = 0;

    /*Break snake array down into 3 1d arrays*/
    breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

    nextX = currentX[*snakeLen-1];
    nextY = currentY[*snakeLen-1];

    

    /*Stops snake from moving backwards*/
    if( (currentChar[*snakeLen-1]) == 86 ) /* V = 86 */
    {
        recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
        updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
        printf("Cannot go backwards\n");
    }

    else
    {
        /*Finds the char that the head will move into and stores it*/
        *nextChar = boardArray[nextX-1][nextY];

        /*Stops snake from hiting the border*/
        if( *nextChar == 42 ) /* * = 42 */
        {
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
            printf("This is a border, you cant move here!!\n");
        }

        else
        {
            /*If the head is already ^ then we can slither as normal and only have to worry about changing the neck to a |*/
            if( (currentChar[*snakeLen-1]) == 94 ) /* ^ = 94 */
            {

                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);
                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = 124; /* | = 124 */

            }

            /*Else the head is either a < or > and thus we have to slither as normal and change the second last char
            (neck of snake back to what it originally was and also change the head of the snake to a ^)*/
            else
            {
                temp = currentChar[*snakeLen-2];
                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);

                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = temp;
                currentChar[*snakeLen - 1] = 94; /* ^ = 94 */

            }

            /*Moves the snake head to up one and sets the tail*/
            currentX[*snakeLen - 1] -= 1;
            currentChar[0] = 35; /* # = 35 */
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
        }
    }


    free(currentX);
    currentX = NULL;

    free(currentY);
    currentY = NULL;

    free(currentChar);
    currentChar = NULL;

}
/*
Name: moveDown
Purpose: moves the snake down on the gameboard
Imports: char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar
Exports: void
*/

void moveDown(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar)
{

    /*Initialise the Variable and pointers*/
    int nextX, nextY;
    char temp;

    int *currentX = NULL;
    int *currentY = NULL;
    char *currentChar = NULL;

    currentX = (int*)(malloc(*snakeLen * sizeof(int)));
    currentY = (int*)(malloc(*snakeLen * sizeof(int)));
    currentChar = (char*)(malloc(*snakeLen * sizeof(char)));

    nextX = 0;
    nextY = 0;

    /*Break snake array down into 3 1d arrays*/
    breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

    nextX = currentX[*snakeLen-1];
    nextY = currentY[*snakeLen-1];

    

    /*Stops snake from moving backwards*/
    if( (currentChar[*snakeLen-1]) == 94 ) /* ^ = 94 */
    {
        recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
        updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
        printf("Cannot go backwards\n");
    }

    else
    {
        /*Finds the char that the head will move into and stores it*/
        *nextChar = boardArray[nextX+1][nextY];

        /*Stops snake from hiting the border*/
        if( *nextChar == 42 ) /* * = 42 */
        {
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
            printf("This is a border, you cant move here!!\n");
        }

        else
        {
            /*If the head is already V then we can slither as normal and only have to worry about changing the neck to a |*/
            if( (currentChar[*snakeLen-1]) == 86 ) /* V = 86 */
            {

                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);
                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = 124; /* | = 124 */

            }

            else
            {
                /*Else the head is either a < or > and thus we have to slither as normal and change the second last char
                (neck of snake back to what it originally was and also change the head of the snake to a V)*/

                temp = currentChar[*snakeLen-2];
                recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
                slitherSnake(snakeArray, snakeLen);

                breakArray(snakeArray, snakeLen, currentX, currentY, currentChar);

                currentChar[*snakeLen-2] = temp;
                currentChar[*snakeLen - 1] = 86; /* V = 86 */

            }

            /*Moves the snake head down one and sets the tail*/
            currentX[*snakeLen - 1] += 1;
            currentChar[0] = 35; /* # = 35 */
            recombineSnake(snakeArray, snakeLen, currentX, currentY, currentChar);
            updateAndPopulate(boardArray, boardRows, boardColumns, snakeLen, snakeArray, xFood, yFood);
        }

    }

    free(currentX);
    currentX = NULL;

    free(currentY);
    currentY = NULL;

    free(currentChar);
    currentChar = NULL;

}