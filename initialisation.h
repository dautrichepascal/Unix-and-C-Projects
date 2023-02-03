/*
Name: initialisation.h by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions for initialisation.c, enabling forward declaractions
*/

#ifndef SNAKEBOARD_H
#define SNAKEBOARD_H

void initSnakeBoard(char** boardArray, int* boardRows, int* boardColumns);
void printBoard(char** boardArray, int* rows, int* columns);
void foodLocation(char** boardArray, int* rows, int* columns, int* xFood, int* yFood);
void initSnake(int* snakeLen, char** snakeArray);

#endif