/*
Name: populater.h by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions for populater.c, enabling forward declaractions
*/

#ifndef POPULATER_H
#define POPULATER_H

void populateBoard(char** boardArray, int* snakeLen, char** snakeArray);
void updateAndPopulate(char** boardArray, int* boardRows, int* boardColumns, int* snakeLen, char** snakeArray, int* xFood, int*yFood);
void breakArray(char** snakeArray, int* snakeLength, int* xArray, int* yArray, char* charArray);
void recombineSnake(char** snakeArray, int* snakeLen, int* xArray, int* yArray, char* charArray);

#endif