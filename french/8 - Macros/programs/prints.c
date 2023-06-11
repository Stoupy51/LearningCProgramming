
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/utils.h"


// Définition d'une macro pour utiliser la fonction (sleep) de manière portable (Linux et Windows en l'occurence)
#ifdef _WIN32
	#include <windows.h>
	#define sleep(x) Sleep(x * 1000)
#else
	#include <unistd.h>
#endif


/**
 * @brief Fonction interne au fichier (non visible à l'extérieur)
 * Elle ne fait rien d'autre qu'afficher des messages
 * 
 * @return int
 */
int internal_function() {
	INFO_PRINT("Internal function\n");

	DEBUG_PRINT("Debug message 1\n");
	sleep(1);

	DEBUG_PRINT("Debug message 2\n");
	sleep(1);

	INFO_PRINT("Internal function end\n");
	return -1;
}

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Introduction à l'utilisation des macros
 * 
 * @return int
 */
int main() {

	// Début du programme
	INFO_PRINT("Program starting\n");

	// Appel de la fonction interne
	int code = internal_function();
	if (code < 0) {
		ERROR_PRINT("Error while executing internal function\n");
	}
	else {
		INFO_PRINT("Fonction interne executee avec succès\n");
	}

	// Affichage d'un message de warning
	WARNING_PRINT("ATTENTION : Ce message est un warning\n");

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	INFO_PRINT("Fin du programme, cette couleur doit etre celle par defaut !\n");
	return 0;
}

