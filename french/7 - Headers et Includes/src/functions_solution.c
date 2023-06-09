
#include "functions.h"

/**
 * @brief Fonction qui calcule la puissance d'un nombre
 * Utilise l'exponentiation rapide : https://fr.wikipedia.org/wiki/Exponentiation_rapide
 * (Algorithme non-récursif plus efficace que l'exponentiation naïve utilisant une boucle for)
 * 
 * @param a		Le nombre à élever à la puissance n
 * @param n		La puissance
 * 
 * @return int
 */
int power_function(int a, int n) {
	
	// Variables
	int result = 1;
	int multiplier = a;

	// Tant que n est supérieur à 0
	while (n > 0) {
		
		// Si n est impair, multiplier le résultat par le multiplicateur
		if (n % 2 == 1) {
			result *= multiplier;
		}
		
		// On divise n par 2
		n /= 2;
		
		// On met le multiplicateur au carré (multiplication par soi-même)
		multiplier *= multiplier;
	}

	// On retourne le résultat
	return result;
}

/**
 * @brief Fonction qui échange les valeurs de deux variables
 * 
 * @param a		La première variable
 * @param b		La deuxième variable
 * 
 * @return void
 */
void swap_function(int *a, int *b) {
	
	// Variable temporaire
	int temp = *a;
	
	// On échange les valeurs
	*a = *b;
	*b = temp;
}

