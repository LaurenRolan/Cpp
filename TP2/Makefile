CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=

complex: complex.o main.o
	$(CC) -o complex complex.o main.o $(LDFLAGS) 

complex.o: Complex.cpp Complex.h
	$(CC) $(CFLAGS) -o complex.o -c Complex.cpp

main.o: main.cpp Complex.h
	$(CC) $(CFLAGS) -o main.o -c main.cpp

clean:
	rm -rf *.o complex