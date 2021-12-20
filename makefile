FLAG=-Wall -g
CC=gcc
AR=ar

all: stringProg main.o

stringProg: main.o 
	$(CC) $(FLAG) -o stringProg main.o


main.o: main.c
	$(CC) $(FLAG) -c main.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg 
