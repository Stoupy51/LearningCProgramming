
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Fonction qui échange les valeurs de deux variables
 * // TODO : Corriger la fonction pour qu'elle fonctionne correctement
 * 
 * @param a		???
 * @param b		???
 * 
 * @return void
 */
void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Elle appelle la fonction swap pour échanger les valeurs de deux variables
 * 
 * @return int
 */
int main() {

	// Déclaration de variables
	int a = 5, b = 10;
	printf("a = %d, b = %d\n", a, b);
	swap(a, b);	// TODO : Corriger l'appel de la fonction
	printf("a = %d, b = %d\n", a, b);

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	printf("\nFin du programme\n");
	return 0;
}

