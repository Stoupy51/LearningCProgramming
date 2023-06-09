
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Fonction qui crée un pointeur sur un entier
 * 
 * @param value		Entier à stocker dans le pointeur
 * 
 * @return int*		Pointeur sur un entier
 */
int* create_int(int value) {
	// TODO : Allouer un pointeur sur un entier, stocker la valeur dans le pointeur et retourner le pointeur
	value = value; // Supprime l'avertissement "unused parameter 'value'"
	return NULL;
}

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Elle appelle la fonction swap pour échanger les valeurs de deux variables
 * 
 * @return int
 */
int main() {

	// Déclaration de variables
	int *a = create_int(51);
	if (a == NULL) {
		perror("Allocation non-faite");
		return -1;
	}
	printf("a = %d (adresse : 0x%p)\n", *a, (void*)a);

	// TODO : Libérer la mémoire allouée pour le pointeur

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	printf("\nFin du programme\n");
	return 0;
}

