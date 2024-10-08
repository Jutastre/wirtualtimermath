define .RECIPEPREFIX
 
endef
CC=gcc-14
CFLAGS= -std=c23 -c -I ./include/ -Wall -Wno-unused-result

all: bruteforce

bruteforce: bruteforce.o
    $(CC) -o ./bin/bruteforce bruteforce.o

bruteforce.c: bruteforce.c
    $(CC) $(CFLAGS) bruteforce.c -o bruteforce.o

clean:
    -rm -rf *.o
    -rm -f ./bin/*
