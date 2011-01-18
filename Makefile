CFLAGS = -Wall -g 
#-O2
CFLAGS2 = $(CFLAGS) -L/usr/X11R6/lib -lX11 -lpng
CC = gcc

all: rmbox

OBJS = rmbox.o flou.o collision.o check_level.o \
       background.o SDL_LoadPNG.o

clean:
	rm *.o rmbox forms.h

rmbox: $(OBJS)
	$(CC) -o rmbox $(CFLAGS2) $(OBJS) -lSDL

rmbox.o: rmbox.c forms.h rmbox.h images.h
	$(CC) -c -o rmbox.o $(CFLAGS) rmbox.c

forms.h: forms.dat forms.sh
	./forms.sh

