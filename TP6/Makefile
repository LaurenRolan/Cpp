EXE = main4

CC = g++
SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/$(EXE).cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CFLAGS=-W -Wall -ansi -pedantic -std=c++11 -g -fPIC
LDFLAGS += -Llib
LDLIBS +=

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(EXE)
