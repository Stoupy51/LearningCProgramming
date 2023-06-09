
# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -Werror -O3
SRC_FOLDER = src
OBJ_FOLDER = obj
BIN_FOLDER = bin
PROG_FOLDER = programs


# Règles
all: folders objects programs

folders:
	mkdir -p $(BIN_FOLDER)
	mkdir -p $(OBJ_FOLDER)

objects: functions functions_solution
programs: basic_header basic_header_solution



# Objets
functions:
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/$@.o -c $(SRC_FOLDER)/$@.c
functions_solution:
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/$@.o -c $(SRC_FOLDER)/$@.c



# Programmes
basic_header: functions
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/$@.exe $(PROG_FOLDER)/$@.c $(OBJ_FOLDER)/functions.o
basic_header_solution: functions_solution
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/$@.exe $(PROG_FOLDER)/basic_header.c $(OBJ_FOLDER)/functions_solution.o



# Nettoyage et restart
clean:
	rm -f $(BIN_FOLDER)/*.exe
	rm -f $(OBJ_FOLDER)/*.o

restart: clean all

