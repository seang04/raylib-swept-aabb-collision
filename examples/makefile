CC = gcc
CFLAGS =-L../raylib/lib -L../bin -lrect-collision -lraylib -lglfw -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -Werror -pedantic

all: ray-collision-example moving-rectangle-collision


ray-collision-example: ray-collision-example.c ../bin/librect-collision.a
	$(CC) -o ray-collision-example ray-collision-example.c $(CFLAGS)

moving-rectangle-collision: moving-rectangle-collision.c ../bin/librect-collision.a
	$(CC) -o moving-rectangle-collision moving-rectangle-collision.c $(CFLAGS)
