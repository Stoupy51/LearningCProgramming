
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Introduction à l'input utilisateur avec les arguments
 * 
 * @param argc		Nombre d'arguments passés au programme
 * @param argv		Arguments passés au programme
 * 
 * @return int
 */
int main(int argc, char* argv[]) {

	// Vérifier que l'utilisateur a bien passé 3 arguments au programme
	if (argc != 3) {

		// Afficher un message d'erreur
		fprintf(stderr, "Usage: %s <number> <text>\n", argv[0]);

		// Afficher un message d'exemple
		fprintf(stderr, "Example: '%s 42 \"Hello World!\"'\n", argv[0]);

		// Retourner 1 pour indiquer que le programme s'est exécuté avec une erreur
		return 1;
	}

	// Convertir le premier argument en entier
	int my_int = atoi(argv[1]);

	// Mettre dans une variable le nombre de caractères de la chaine de caractères
	int my_string_length = strlen(argv[2]);

	// Copie de la chaine de caractères dans une variable
	char *my_string = strdup(argv[2]);

	// Afficher les variables
	printf("Mon entier vaut %d\n", my_int);
	printf("Ma chaine de caracteres vaut '%s' et fait %d caracteres\n", my_string, my_string_length);

	// Libérer la mémoire allouée
	free(my_string);

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	printf("\nFin du programme\n");
	return 0;
}

