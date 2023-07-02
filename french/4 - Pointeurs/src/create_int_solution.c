
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

	// Allocation d'un pointeur sur un entier
	int *ptr = malloc(sizeof(int));

	// Stockage de la valeur dans le pointeur
	*ptr = value;

	// Retour du pointeur
	return ptr;
}

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Elle appelle la fonction create_int et affiche le résultat
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

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	printf("\nFin du programme\n");
	return 0;
}

