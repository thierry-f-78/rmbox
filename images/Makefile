SRC = $(shell ls *.c)
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(OBJ)

%.o: %.c
	CC=$(CC) ./conv.sh $@ $^

clean:
	rm *.o
