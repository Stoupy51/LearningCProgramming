
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/functions.h"

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Introduction à l'utilisation des headers
 * 
 * @return int
 */
int main() {

	// Variables
	int my_int = 3;
	int power = 2000000000;
	clock_t start = clock();

	// Afficher le résultat de la fonction power
	printf("\n(Le resultat ne peut pas etre superieur a 2 puissance 31 comme c'est un int)\n");
	printf("%d**%d = %d\n", my_int, power, power_function(my_int, power));

	// Afficher le résultat de la fonction swap
	swap_function(&my_int, &power);
	printf("%d**%d = %d\n", my_int, power, power_function(my_int, power));

	// Récupérer le temps de fin
	clock_t end = clock();

	// Afficher le temps d'exécution
	double milliseconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nTemps d'execution : %.3f secondes\n", milliseconds);

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	printf("\nFin du programme\n");
	return 0;
}

