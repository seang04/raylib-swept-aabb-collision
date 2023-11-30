CC = gcc
CFLAGS =-L../raylib/lib -L../bin -lrect-collision -lraylib -lglfw -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -Werror -pedantic
OUTDIR = ../build
OBJECTDIR = ../object

all: $(OUTDIR) $(OBJECTDIR) $(OBJECTDIR)/rect-collision.o 
	ar rcs $(OUTDIR)/librect-collision.a $(OBJECTDIR)/rect-collision.o
	$(CC) -shared -o $(OUTDIR)/librect-collision.so $(OBJECTDIR)/rect-collision.o
	
$(OUTDIR): 
	mkdir ../build
	
$(OBJECTDIR):
	mkdir ../object

$(OBJECTDIR)/rect-collision.o: rect-collision.c rect-collision.h
	$(CC) rect-collision.c -c $(CFLAGS)
	mv *.o $(OBJECTDIR)
