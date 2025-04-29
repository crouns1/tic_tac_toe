#include <stdio.h>
#include <limits.h>

#define HUMAN 'X'
#define AI 'O'
#define EMPTY ' '

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

int main() {
    initBoard();
    printBoard();
}

