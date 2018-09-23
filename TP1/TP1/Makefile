CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
LIST = livres qbonus porte

all: $(LIST)

porte: porte.o
	$(CC) -o porte porte.o $(LDFLAGS) 

porte.o: src/porte.cpp
	$(CC) -o porte.o -c src/porte.cpp $(CFLAGS)	

qbonus: qbonus.o
	$(CC) -o qbonus qbonus.o $(LDFLAGS) 

qbonus.o: src/QuestionBonus.cpp
	$(CC) $(CFLAGS) -o qbonus.o -c src/QuestionBonus.cpp	

livres: livres.o main.o
	$(CC) -o livres livres.o main.o $(LDFLAGS) 

livres.o: src/livres.cpp include/livres.h
	$(CC) $(CFLAGS) -o livres.o -c src/livres.cpp

main.o: src/main.cpp include/livres.h
	$(CC) $(CFLAGS) -o main.o -c src/main.cpp

clean: 
	rm -rf *.o $(LIST)