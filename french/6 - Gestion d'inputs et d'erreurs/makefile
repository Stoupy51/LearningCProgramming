
# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -O3 # Pas de Werror pour ce chapitre
SRC_FOLDER = src
OBJ_FOLDER = obj
BIN_FOLDER = bin


# Règles
all: folders args args_solution scanf scanf_solution errors errors_solution
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/args.exe $(OBJ_FOLDER)/args.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/args_solution.exe $(OBJ_FOLDER)/args_solution.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/scanf.exe $(OBJ_FOLDER)/scanf.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/scanf_solution.exe $(OBJ_FOLDER)/scanf_solution.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/errors.exe $(OBJ_FOLDER)/errors.o
	$(CC) $(COMPILER_FLAGS) -o $(BIN_FOLDER)/errors_solution.exe $(OBJ_FOLDER)/errors_solution.o

folders:
	mkdir -p $(BIN_FOLDER)
	mkdir -p $(OBJ_FOLDER)

args: $(SRC_FOLDER)/args.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/args.o -c $^

args_solution: $(SRC_FOLDER)/args_solution.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/args_solution.o -c $^

scanf: $(SRC_FOLDER)/scanf.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/scanf.o -c $^

scanf_solution: $(SRC_FOLDER)/scanf_solution.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/scanf_solution.o -c $^

errors: $(SRC_FOLDER)/errors.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/errors.o -c $^

errors_solution: $(SRC_FOLDER)/errors_solution.c
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_FOLDER)/errors_solution.o -c $^


# Nettoyage et restart
clean:
	rm -f $(BIN_FOLDER)/*.exe
	rm -f $(OBJ_FOLDER)/*.o

restart: clean all

