
# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -Werror -O3
SRC_FOLDER = src
OBJ_FOLDER = obj
BIN_FOLDER = bin


# Règles
all: folders main solution
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/main.exe $(OBJ_FOLDER)/main.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/solution.exe $(OBJ_FOLDER)/solution.o

folders:
	mkdir -p $(BIN_FOLDER)
	mkdir -p $(OBJ_FOLDER)

main: $(SRC_FOLDER)/main.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/main.o -c $^

solution: $(SRC_FOLDER)/solution.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/solution.o -c $^


# Nettoyage et restart
clean:
	rm -f $(BIN_FOLDER)/*.exe
	rm -f $(OBJ_FOLDER)/*.o

restart: clean all

