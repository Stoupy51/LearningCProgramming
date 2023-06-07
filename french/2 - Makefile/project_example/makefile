
# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -Werror -O3
SRC_FOLDER = src
OBJ_FOLDER = obj
BIN_FOLDER = bin


# Règles
all: folders main1 main2
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/main1.exe $(OBJ_FOLDER)/main1.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/main2.exe $(OBJ_FOLDER)/main2.o

folders:
	mkdir -p $(BIN_FOLDER)
	mkdir -p $(OBJ_FOLDER)

main1: $(SRC_FOLDER)/main1.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/main1.o -c $^

main2: $(SRC_FOLDER)/main2.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/main2.o -c $^


# Nettoyage et restart
clean:
	rm -f $(BIN_FOLDER)/*.exe
	rm -f $(OBJ_FOLDER)/*.o

restart: clean all

