
#include "int_array.h"
#include "universal_utils.h"

/**
 * @brief Fonction d'initialisation d'un tableau d'entiers
 * 
 * @param array		Pointeur vers un int_array_t
 * @param size		Taille du tableau d'entiers
 * 
 * @return int		-1 en cas d'erreur, 0 sinon
 */
int int_array_init(int_array_t* array, int size) {
	// TODO: Implémenter la fonction
	return 0;
}


/**
 * @brief Fonction d'affichage d'un tableau d'entiers
 * 
 * @param array			int_array_t à afficher
 * @param print_level	Niveau d'affichage
 * 
 * @return void
 */
void int_array_print(int_array_t array, int print_level) {

	// Variable de boucle
	int i;
	
	// Affichage du préfixe de niveau d'affichage
	PREFIX_PRINT(print_level);

	// Affichage du début du tableau
	if (array.size == 0) {
		PRINTER("int_array de taille 0: []\n");
	}
	else {
		PRINTER("int_array de taille %d: [%d", array.size, array.data[0]);
	}

	// Affichage du reste du tableau
	for (i = 1; i < array.size; i++)
		PRINTER(", %d", array.data[i]);
	
	// Affichage de la fin du tableau
	PRINTER("]\n");
}


/**
 * @brief Fonction de libération de la mémoire allouée pour un tableau d'entiers
 * 
 * @param array		Pointeur vers un int_array_t
 * 
 * @return void
 */
void int_array_free(int_array_t* array) {

	// Libération de la mémoire allouée pour le tableau d'entiers
	free(array->data);

	// Réinitialisation du tableau d'entiers
	array->data = NULL;
	array->size = 0;
}

