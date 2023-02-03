/*
Name: startgame.h by Pascal d'Autriche (20190826)
Purpose: Contains all of the functions for startgame.c, enabling forward declaractions
*/

#ifndef STARTGAME_H
#define STARTGAME_H

void letsPlay(int* rowPtr, int* colPtr, int* snakeLen);

/*This will always be the length of the snake description (x-cord, y-cord, character) and the null character, assuming the max board dimensions will be 99 x 99*/
#define SNAKEDESCRIPTION 8

#endif