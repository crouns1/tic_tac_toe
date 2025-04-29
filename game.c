#include "board.h"

void humanMove() {
    int row, col;
    while (1) {
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--; col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == EMPTY) {
            board[row][col] = HUMAN;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void runGame() {
    initBoard();
    printBoard();
    char winner = 'N';

    while (winner == 'N') {
        humanMove();
        printBoard();
        winner = checkWinner();
        if (winner != 'N') break;

        printf("AI is thinking...\n");
        bestMove();
        printBoard();
        winner = checkWinner();
    }

    if (winner == HUMAN)
        printf("You win!\n");
    else if (winner == AI)
        printf("AI wins!\n");
    else
        printf("It's a draw!\n");
}

