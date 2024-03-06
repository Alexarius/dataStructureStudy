CC = gcc
CFLAGS = -c -g
LDFLAGS =  
OBJECTS = 0908pb1.o

run: all
	program

all: program

program : $(OBJECTS)
	$(CC)  $(LDFLAGS) -o program $(OBJECTS)

0908pb1.o : 0908pb1.c
	$(CC) $(CFLAGS) 0908pb1.c 