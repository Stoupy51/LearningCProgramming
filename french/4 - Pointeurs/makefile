
# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -Werror -O3
SRC_FOLDER = src
OBJ_FOLDER = obj
BIN_FOLDER = bin


# Règles
all: folders swap swap_solution create_int create_int_solution
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/swap.exe $(OBJ_FOLDER)/swap.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/swap_solution.exe $(OBJ_FOLDER)/swap_solution.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/create_int.exe $(OBJ_FOLDER)/create_int.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/create_int_solution.exe $(OBJ_FOLDER)/create_int_solution.o

folders:
	mkdir -p $(BIN_FOLDER)
	mkdir -p $(OBJ_FOLDER)

swap: $(SRC_FOLDER)/swap.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/swap.o -c $^

swap_solution: $(SRC_FOLDER)/swap_solution.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/swap_solution.o -c $^

create_int: $(SRC_FOLDER)/create_int.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/create_int.o -c $^

create_int_solution: $(SRC_FOLDER)/create_int_solution.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/create_int_solution.o -c $^


# Nettoyage et restart
clean:
	rm -f $(BIN_FOLDER)/*.exe
	rm -f $(OBJ_FOLDER)/*.o

restart: clean all

