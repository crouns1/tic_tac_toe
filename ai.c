#include "board.h"

int minimax(int depth, int isMaximizing) {
    char result = checkWinner();
    if (result == AI) return 10 - depth;
    if (result == HUMAN) return depth - 10;
    if (result == 'D') return 0;

    if (isMaximizing) {
        int bestScore = INT_MIN;
        int i = 0;
        while (i < 3) {
            int j = 0;
            while (j < 3) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = AI;
                    int score = minimax(depth + 1, 0);
                    board[i][j] = EMPTY;
                    if (score > bestScore) bestScore = score;
                }
                j++;
            }
            i++;
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        int i = 0;
        while (i < 3) {
            int j = 0;
            while (j < 3) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = HUMAN;
                    int score = minimax(depth + 1, 1);
                    board[i][j] = EMPTY;
                    if (score < bestScore) bestScore = score;
                }
                j++;
            }
            i++;
        }
        return bestScore;
    }
}

void bestMove() {
    int bestScore = INT_MIN;
    int moveRow = -1;
    int moveCol = -1;

    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                int score = minimax(0, 0);
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
            j++;
        }
        i++;
    }

    if (moveRow != -1 && moveCol != -1)
        board[moveRow][moveCol] = AI;
}

