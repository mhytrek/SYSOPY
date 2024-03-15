CC=gcc
CFLAGS := -std=c11 -Wall

				 
static: collatz.c
	$(CC) $(CFLAGS) -o static_collatz -c collatz.c
	ar rcs lib_static_collatz.a static_collatz


shared: collatz.c
	$(CC) $(CFLAGS) -fPIC -o shared_collatz.o -c collatz.c
	$(CC) -shared -o lib_shared_collatz.so shared_collatz.o

.PHONY: clean

clean:
	rm -rf *.o *.a *.so static_collatz