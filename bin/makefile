CC = gcc
CFLAGS =-L../raylib/lib -L../bin -lrect-collision -lraylib -lglfw -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -Werror -pedantic

all: rect-collision.o
	ar rcs librect-collision.a rect-collision.o

rect-collision.o: ../src/rect-collision.c ../src/rect-collision.h
	$(CC) ../src/rect-collision.c -c $(CFLAGS)
