# Author: Waleed Qawasmi
# Originally compiled on Debian Jessie using g++
CC=g++
CFLAGS=-c -Wall -g
LIBS=-L/usr/local/lib -lcryptopp -lpthread

# Run .PHONY first to clean any old *o files if possible.
all: .PHONY main

main: main.o hasher.o segment.o
	$(CC) main.o hasher.o segment.o $(LIBS) -o test

segment.o:
	$(CC) $(CFLAGS) segment.cpp

hasher.o:
	$(CC) $(CFLAGS) $(LIBS) hasher.cpp

main.o:
	$(CC) $(CFLAGS) $(LIBS) main.cpp

# To avoid the error incase there is another file in directory named
# "clean", which is the only case in which the "make clean" will fail
.PHONY: clean
clean:
	rm -f *o || true
# Last line is for the case where "make" is run and there are no current
# *o files to remove, the "-f" flag hides the error message given
# The OR-statement in incase there is an error that there exist no *o files
# in (statement #1), then it will simply run TRUE which is (statement #2)