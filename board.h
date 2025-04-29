#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <limits.h>

#define HUMAN 'X'
#define AI 'O'
#define EMPTY ' '

extern char board[3][3];
void initBoard();
void printBoard();
char checkWinner();
void bestMove();
int minimax(int depth, int isMaximizing);
void humanMove();
void runGame();
#endif

