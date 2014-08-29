cc = gcc -Wall -std=c99

all: clean draw

draw: main.o common.o
	$(cc) main.o common.o -o draw

main.o: main.c
	$(cc)  -c main.c -o main.o

common.o: common.c
	$(cc)  -c common.c -o common.o

clean:
	rm -f *.o draw
