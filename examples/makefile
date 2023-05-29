CC = gcc
CFLAGS =-L../raylib/lib -L../bin -lrect-collision -lraylib -lglfw -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -Werror -pedantic -ggdb

all: ray-collision-example moving-rectangle-collision rectangle-bounce


ray-collision-example: ray-collision-example.c ../bin/librect-collision.a
	$(CC) -o ray-collision-example ray-collision-example.c $(CFLAGS)

moving-rectangle-collision: moving-rectangle-collision.c ../bin/librect-collision.a
	$(CC) -o moving-rectangle-collision moving-rectangle-collision.c $(CFLAGS)

rectangle-bounce: rectangle-bounce.c ../bin/librect-collision.a
	$(CC) -o rectangle-bounce rectangle-bounce.c $(CFLAGS)
