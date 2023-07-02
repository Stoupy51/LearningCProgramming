
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/int_array.h"
#include "../src/universal_utils.h"

/**
 * @brief Fonction exécutée à la fin du programme (automatiquement)
 * [enregistrée avec atexit()] dans la fonction main().
 * 
 * @return void
 */
void exitProgram() {

	// Print end of program
	INFO_PRINT("exitProgram(): End of program, press enter to exit\n");
	getchar();
	exit(EXIT_SUCCESS);
}

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Introduction à l'utilisation des structures
 * 
 * @return int
 */
int main() {

	// Affichage de l'en-tête du programme et enregistrement de la fonction exitProgram() avec atexit()
	mainInit("main(): int_array test program\n");
	atexit(exitProgram);

	// Déclaration d'un tableau d'entiers
	int_array_t int_array;

	// Initialisation du tableau d'entiers
	int code = int_array_init(&int_array, 10);
	ERROR_HANDLE_INT_RETURN_INT(code, "main(): Erreur lors de l'initialisation du tableau d'entiers\n");

	// Affichage du tableau d'entiers
	int_array_print(int_array, INFO_LEVEL);

	// Libération de la mémoire allouée pour le tableau d'entiers
	int_array_free(&int_array);

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	INFO_PRINT("\nFin du programme !\n");
	return 0;
}

