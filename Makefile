CFLAGS = -O2
CFLAGS2 = $(CFLAGS) -L/usr/X11R6/lib -lX11
CC = gcc

all: rmbox

clean:
	$(MAKE) -C images clean
	rm *.o images.h rmbox forms.h

rmbox: images_obj rmbox.o flou.o sprites.o collision.o
	$(CC) -o rmbox $(CFLAGS2) images/*.o rmbox.o flou.o sprites.o \
	                          collision.o

rmbox.o: rmbox.c forms.h rmbox.h images.h
	$(CC) -c -o rmbox.o $(CFLAGS) rmbox.c

forms.h: forms.dat forms.sh
	./forms.sh

images_obj:
	$(MAKE) -C images

images.h: $(shell ls images/*.c)
	./images.h.sh
