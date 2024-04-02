CC=gcc
CFLAGS=-Wall

.PHONY: clean

all: reverse

reverse: reverse.c
	$(CC) $(CFLAGS) -o reverse reverse.c

test_1:
	make reverse
	./reverse test tmp1 1 ; ./reverse tmp1 tmp2 1 ; diff -s tmp2 test

test_2:
	make reverse
	./reverse test tmp1 1024 ; ./reverse tmp1 tmp2 1024 ; diff -s tmp2 test

clean:
	rm tmp1 tmp2 reverse 
