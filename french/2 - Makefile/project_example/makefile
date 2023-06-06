
# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -Werror -O3
SRC_FOLDER = src
OBJ_FOLDER = obj
BIN_FOLDER = bin


# Règles
all: main1 main2
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/main1.exe $(OBJ_FOLDER)/main1.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/main2.exe $(OBJ_FOLDER)/main2.o

main1: $(SRC_FOLDER)/main1.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/main1.o -c $^

main2: $(SRC_FOLDER)/main2.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/main2.o -c $^


# Nettoyage et restart
clean:
	rm $(BIN_FOLDER)/*.exe
	rm $(OBJ_FOLDER)/*.o

restart: clean all

