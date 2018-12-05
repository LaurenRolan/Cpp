EXE = main1 main2 main3 main4 main5 main6

CC = g++
SRC_DIR = src
OBJ_DIR = obj

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CFLAGS=-W -Wall -ansi -pedantic -std=c++11 -g -fPIC
LDFLAGS += -Llib
LDLIBS +=

.PHONY: all clean

all: $(EXE)

$(EXE): %: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ $<
clean:
	$(RM) $(OBJ) $(EXE)
