
CC=gcc
CFLAGS := -std=c11 -Wall 


.PHONY: clean

klient_static: klient.c
	make -C libcollatz static
	$(CC) $(CFLAGS) -o klient_static klient.c libcollatz/lib_static_collatz.a 


klient_shared: klient.c
	make -C libcollatz shared
	$(CC) $(CFLAGS) -L ./libcollatz klient.c -l_shared_collatz -Wl,-rpath=./collatzlib -o klient_shared

klient_shared_dynamic: klient.c
	make shared_collatz -C libcollatz
	$(CC) $(CFLAGS) -o klient_dynamic klient.c -ldl -D DYNAMIC

clean:
	make -C libcollatz .PHONY
	rm -rf klient_shared klient_static klient_dynamic