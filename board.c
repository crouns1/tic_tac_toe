#include "board.h"

char board[3][3];

void initBoard() {
    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            board[i][j] = EMPTY;
            j++;
        }
        i++;
    }
}

void printBoard() {
    printf("\n");
    int i = 0;
    while (i < 3) {
        int j = 0;
        printf(" ");
        while (j < 3) {
            printf("%c", board[i][j]);
            if (j < 2) printf(" | ");
            j++;
        }
        if (i < 2) printf("\n-----------\n");
        i++;
    }
    printf("\n\n");
}

char checkWinner() {
    int i = 0;
    while (i < 3) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
        i++;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];

    i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            if (board[i][j] == EMPTY)
                return 'N';
            j++;
        }
        i++;
    }
    return 'D';
}

