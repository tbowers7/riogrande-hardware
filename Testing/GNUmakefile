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
all : testport bob clear_ports turnlight test_dip driver_test


.PHONY: all clean rmtl

clean:
	rm -rf $(EXE)

rmtl:
	rm -rf *~


# Make Targets

testport: testport.c
	$(CC) $(CFLAGS) -o testport testport.c -lm

bob: bob.c
	$(CC) $(CFLAGS) -o bob bob.c -lm

clear_ports: clear_ports.c
	$(CC) $(CFLAGS) -o clear_ports clear_ports.c -lm

turnlight: turnlight.c
	$(CC) $(CFLAGS) -o turnlight turnlight.c -lm

test_dip: test_dip.c
	$(CC) $(CFLAGS) -o test_dip test_dip.c -lm

driver_test: driver_test.c
	$(CC) $(CFLAGS) -o driver_test driver_test.c -lm
