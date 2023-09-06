CC = gcc
CFLAGS =-L../raylib/lib -L../src -l:librect-collision.a -I../src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -Werror -pedantic -ggdb

all: ray-collision-example moving-rectangle-collision rectangle-bounce


ray-collision-example: ray-collision-example.c ../src/librect-collision.a
	$(CC) -o ray-collision-example ray-collision-example.c $(CFLAGS)

moving-rectangle-collision: moving-rectangle-collision.c ../src/librect-collision.a
	$(CC) -o moving-rectangle-collision moving-rectangle-collision.c $(CFLAGS)

rectangle-bounce: rectangle-bounce.c ../src/librect-collision.a
	$(CC) -o rectangle-bounce rectangle-bounce.c $(CFLAGS)
