CC = gcc
CFLAGS =-L../raylib/lib -L../src -l:librect-collision.a -I../src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -Werror -pedantic -ggdb
OUTDIR = build

all: $(OUTDIR) ray-collision-example moving-rectangle-collision rectangle-bounce 

#------------------------------------------------------------------------------
# Create build directory if it does not exist
#------------------------------------------------------------------------------
$(OUTDIR): 
	mkdir $(OUTDIR)

#------------------------------------------------------------------------------
# Compile examples
#------------------------------------------------------------------------------
ray-collision-example: ray-collision-example.c ../src/librect-collision.a
	$(CC) -o ./build/ray-collision-example ray-collision-example.c $(CFLAGS)

moving-rectangle-collision: moving-rectangle-collision.c ../src/librect-collision.a
	$(CC) -o ./build/moving-rectangle-collision moving-rectangle-collision.c $(CFLAGS)

rectangle-bounce: rectangle-bounce.c ../src/librect-collision.a
	$(CC) -o ./build/rectangle-bounce rectangle-bounce.c $(CFLAGS)
