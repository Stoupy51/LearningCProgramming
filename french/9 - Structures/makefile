
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

objects: universal_utils int_array int_linked_list
programs: test_array test_linked_list



# Objets
int_array:
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/$@.o -c $(SRC_FOLDER)/$@.c
int_linked_list:
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/$@.o -c $(SRC_FOLDER)/$@.c



# Programmes
test_array:
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/$@.exe $(PROG_FOLDER)/$@.c $(OBJ_FOLDER)/int_array.o $(OBJ_FOLDER)/universal_utils.o
test_linked_list:
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/$@.exe $(PROG_FOLDER)/$@.c $(OBJ_FOLDER)/int_linked_list.o $(OBJ_FOLDER)/universal_utils.o



# Nettoyage et restart
clean:
	rm -f $(BIN_FOLDER)/*.exe
	rm -f $(OBJ_FOLDER)/*.o

restart: clean all

