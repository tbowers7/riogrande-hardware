# Makefile for the test routines in the riogrande-hardware repository.
#
# Library inclusions are named -- each make target needs to call the proper
#    library inclusion variable

CC = gcc

## General CFLAGS
CFLAGS += -Wall

## Library Inclusions
X11 = -L/usr/X11/lib
TPEB = -ltpeb

## Variable for executables (for clean)
SOURCES = $(wildcard *.c)
EXE = $(SOURCES:.c=)

# make all / clean
all : testport bob


.PHONY: all clean

clean:
	rm -rf $(EXE)



# Make Targets

testport: testport.c
	$(CC) $(CFLAGS) -o testport testport.c -lm

bob: bob.c
	$(CC) $(CFLAGS) -o bob bob.c -lm
