CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c board.c ai.c game.c
NAME = tictactoe

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f $(NAME)

