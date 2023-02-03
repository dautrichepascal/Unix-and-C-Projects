/*
Name: movement.h by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions for movement.c, enabling forward declaractions
*/

#ifndef MOVEMENT_H
#define MOVEMENT_H

void slitherSnake(char** snakeArray, int* snakeLen);
void moveRight(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar);
void moveLeft(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar);
void moveUp(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar);
void moveDown(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood, char* nextChar);

/*Creating a type def for ease of use when creating the function pointer (whichMovement())*/
typedef void (*MovementPointer)(char**, int*, int*, int*, char**, int*, int*, char*);

MovementPointer whichMovement(char *userInput);

#endif