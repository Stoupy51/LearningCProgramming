
# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -Werror -O3
SRC_FOLDER = src
OBJ_FOLDER = obj
BIN_FOLDER = bin


# Règles
all: args scanf errors
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/args.exe $(OBJ_FOLDER)/args.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/scanf.exe $(OBJ_FOLDER)/scanf.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/errors.exe $(OBJ_FOLDER)/errors.o

args: $(SRC_FOLDER)/args.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/args.o -c $^

scanf: $(SRC_FOLDER)/scanf.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/scanf.o -c $^

errors: $(SRC_FOLDER)/errors.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/errors.o -c $^


# Nettoyage et restart
clean:
	rm -f $(BIN_FOLDER)/*.exe
	rm -f $(OBJ_FOLDER)/*.o

restart: clean all

