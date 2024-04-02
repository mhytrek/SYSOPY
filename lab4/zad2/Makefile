CC=gcc
CFLAGS=-Wall

.PHONY: clean

all: start

start: parent_process.c
	$(CC) $(CFLAGS) -o p parent_process.c
	
clean:
	rm p
