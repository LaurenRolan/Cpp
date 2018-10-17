CC=g++
CFLAGS=-W -Wall -ansi -pedantic -std=c++11 -g
LDFLAGS=

matrix: matrix.o main.o
	$(CC) -o matrix matrix.o main.o $(LDFLAGS) 

matrix.o: Matrix.cpp Matrix.h
	$(CC) $(CFLAGS) -o matrix.o -c Matrix.cpp

main.o: main.cpp Matrix.h
	$(CC) $(CFLAGS) -o main.o -c main.cpp

clean:
	rm -rf *.o matrix