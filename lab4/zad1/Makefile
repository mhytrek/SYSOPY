CC=gcc
CFLAGS=-Wall

.PHONY: clean

all: process

process: processes.c
	$(CC) $(CFLAGS) -o process processes.c

clean:
	rm process