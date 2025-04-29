CC = gcc
CFLAGS = -Wall -Iinclude
OBJ = obj

SOURCES = main.c board.c ai.c game.c
OUTPUT = tictactoe

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

