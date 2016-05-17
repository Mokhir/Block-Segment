# Author: Waleed Qawasmi
# Originally compiled on Debian Jessie using g++
CC=g++
CFLAGS=-c -Wall
LIBS=-L/usr/local/lib -lcryptopp -lpthread

all: main

main: main.o hasher.o segment.o
	$(CC) main.o hasher.o segment.o $(LIBS) -o test

segment.o:
	$(CC) $(CFLAGS) segment.cpp
	
hasher.o:
	$(CC) $(CFLAGS) $(LIBS) hasher.cpp

main.o:
	$(CC) $(CFLAGS) $(LIBS) main.cpp

clean:
	rm *o
