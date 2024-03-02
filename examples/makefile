CC = gcc
RAYLIB = ./raylib
SWEPT_AABB = ../build
CFLAGS =-L.$(RAYLIB)/lib -L$(SWEPT_AABB) -l:librect-collision.a -I$(SWEPT_AABB)/include -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -Werror -pedantic
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
ray-collision-example: ray-collision-example.c $(SWEPT_AABB)/librect-collision.a
	$(CC) -o ./build/ray-collision-example ray-collision-example.c $(CFLAGS)

moving-rectangle-collision: moving-rectangle-collision.c $(SWEPT_AABB)/librect-collision.a
	$(CC) -o ./build/moving-rectangle-collision moving-rectangle-collision.c $(CFLAGS)

rectangle-bounce: rectangle-bounce.c $(SWEPT_AABB)/librect-collision.a
	$(CC) -o ./build/rectangle-bounce rectangle-bounce.c $(CFLAGS)
