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


void humanMove() {
    int row, col;
    while (1) {
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--; 
	col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = HUMAN;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    initBoard();
    printBoard();
    char winner = 'N';

    while (winner == 'N') {
        humanMove();
        printBoard();
    }

    if (winner == HUMAN)
        printf("You win!\n");
    
    return 0;
}

