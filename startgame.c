/*
Name: startgame.c by Pascal d'Autriche (20190826)
Purpose: This is where the behind the scenes of game functionality occurs
*/

#include <stdio.h>
#include <stdlib.h>

#include "initialisation.h"
#include "populater.h"
#include "movement.h"
#include "arrays.h"
#include "startgame.h"
#include "macros.h"
#include "terminal.h"

/*
Name: make2dCharArray
Purpose: is where everything is combined to play the game
Imports: int* rowPtr, int* colPtr, int* snakeLen
Exports: void
*/
void letsPlay(int* rowPtr, int* colPtr, int* snakeLen)
{

    /*Initialise all necessary variables and pointers*/
    int xFood, yFood, snakeDescriber, exitProgram, validInput;

    char nextCharacter, userInput;

    int *ptrXFood = (int*)(malloc(sizeof(int)));
    int *ptrYFood = (int*)(malloc(sizeof(int)));
    int *ptrSnakeDesc = (int*)(malloc(sizeof(int)));

    char *ptrNextChar = (char*)(malloc(sizeof(char)));
    char *ptrUserInput = (char*)(malloc(sizeof(char)));
    
    char** gameBoard = NULL;
    char** snakeLocation = NULL;

    /*Initialise pointer function*/
    MovementPointer desiredLocation; 

    /*+2 for each as the users input for the game board diemnsions were for what was playable*/
    *rowPtr += 2;
    *colPtr += 2;

    /*Constant used for snake description was an appropriate number assuming a gamboard size less than 
    100 x 100 was used*/
    snakeDescriber = SNAKEDESCRIPTION;

    *ptrSnakeDesc = snakeDescriber;

    /*Initialise gameboard and snake location 2d Arrays*/
    gameBoard = make2dCharArray(gameBoard, rowPtr, colPtr);
    snakeLocation = make2dCharArray(snakeLocation, snakeLen, ptrSnakeDesc);


    /*Initialise all of the variables*/
    xFood = 0;
    yFood = 0;
    nextCharacter = 'z';
    userInput = 'z';
    exitProgram = FALSE;
    validInput = TRUE;

    *ptrXFood = xFood;
    *ptrYFood = yFood;
    *ptrNextChar = nextCharacter;
    *ptrUserInput = userInput;

    /*Snake board is initialised and snake is also initialised, the game board is then populated with the snake
    and only then can the food location be determined*/
    
    system("clear");
    initSnakeBoard(gameBoard, rowPtr, colPtr);
    initSnake(snakeLen, snakeLocation);
    populateBoard(gameBoard, snakeLen, snakeLocation);
    foodLocation(gameBoard, rowPtr, colPtr, ptrXFood, ptrYFood);
    updateAndPopulate(gameBoard, rowPtr, colPtr, snakeLen, snakeLocation, ptrXFood, ptrYFood);

    /*Outer do while loop is to keep the snake game going, inner one it to validate userInput*/
    do
    {
        do 
        {
            validInput = TRUE;

            disableBuffer();
            scanf(" %c", ptrUserInput);
            enableBuffer();

            /*If neither w/a/s/d is entered then the loop will enter here and set validInput to FALSE*/
            if( (*ptrUserInput != 'w') && (*ptrUserInput != 'a') && (*ptrUserInput != 's') && (*ptrUserInput != 'd'))
            {

                /*Game boarg was always updated and populated throughout the program to make the print statements fall below the game board*/
                system("clear");
                updateAndPopulate(gameBoard, rowPtr, colPtr, snakeLen, snakeLocation, ptrXFood, ptrYFood);
                printf("Invalid input\n");
                validInput = FALSE;
            }

        }while(!validInput);

        system("clear");

        /*Takes validated user input into here and then returns a pointer to the desired function*/
        desiredLocation = whichMovement(ptrUserInput);
        (*desiredLocation)(gameBoard, rowPtr, colPtr, snakeLen, snakeLocation, ptrXFood, ptrYFood, ptrNextChar);

        /*The only two ways that the game will stop*/
        if( *ptrNextChar == 64 ) /* @ = 64 */
        {
            printf("Congratulations You Win!!!\n");
            exitProgram = TRUE;
        }

        #ifndef UNBEATABLE
        else if( (*ptrNextChar == 45) || (*ptrNextChar == 124)) /* - = 45, | = 124*/
        {
            printf("You hit your own body, you lose!!\n");
            exitProgram = TRUE;
        }
        #endif
        

    } while (!exitProgram);
    

    /*Free all the pointers within the 2D arrays*/
    freeCharArray(gameBoard, rowPtr, colPtr);
    freeCharArray(snakeLocation, snakeLen, ptrSnakeDesc);


    free(ptrXFood);
    ptrXFood = NULL;

    free(ptrYFood);
    ptrYFood = NULL;

    free(ptrSnakeDesc);
    ptrSnakeDesc = NULL;

    free(ptrNextChar);
    ptrNextChar = NULL;

    free(ptrUserInput);
    ptrUserInput = NULL;

}