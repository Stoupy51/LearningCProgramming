
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Introduction à l'input utilisateur avec scanf
 * 
 * @return int
 */
int main() {

	// Variables
	int my_int = 0;
	char my_string[64] = {0};

	///// Objectif: Demander à l'utilisateur de saisir un entier et une chaine de caractères
	// 1. Demander à l'utilisateur de saisir un entier
	printf("Saisissez un entier: ");
	// 2. Récupérer l'entier saisi par l'utilisateur
	scanf("%d", &my_int);
	printf("\n");
	// 3. Demander à l'utilisateur de saisir une chaine de caractères
	printf("Saisissez une chaine de caracteres: ");
	// 4. Récupérer la chaine de caractères saisie par l'utilisateur
	scanf("%63s", my_string);

	// Afficher les valeurs saisies par l'utilisateur
	printf("Vous avez saisi l'entier %d et la chaine de caracteres '%s'\n\n\n", my_int, my_string);

	///// Objectif: Demander à l'utilisateur de saisir des valeurs jusqu'à ce qu'il saisisse "q"
	///// Avec cela, vous pouvez experimenter le scanf, par exemple mettre en input "1 2 3 4 5 6 7 8 9 10 q" et voir ce qui se passe
	char input[64] = {0};
	int my_int_array_size = 1;
	int *my_int_array = malloc(my_int_array_size * sizeof(int));
	while (1) {

		// Récupérer l'input utilisateur
		printf("Saisissez une valeur (q pour quitter): ");
		scanf("%63s", input);
		printf("\n");

		// Si l'utilisateur a saisi "q", on quitte la boucle
		if (input[0] == 'q') {
			break;
		}

		// Sinon, on ajoute la valeur saisie à notre tableau d'entiers
		else {

			// On ajoute la valeur saisie à la fin du tableau
			my_int_array[my_int_array_size - 1] = atoi(input);

			// On affiche le tableau d'entiers (Astuce: on affiche le premier element, puis on affiche les autres en ajoutant une virgule avant)
			int i;
			printf("[%d] = {%d", my_int_array_size, my_int_array[0]);
			for (i = 1; i < my_int_array_size; i++) {
				printf(", %d", my_int_array[i]);
			}
			printf("}\n");

			// On agrandit le tableau d'entiers
			my_int_array_size += 1;
			my_int_array = realloc(my_int_array, my_int_array_size * sizeof(int));
		}
	}

	// On libère la mémoire allouée pour le tableau d'entiers
	free(my_int_array);

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	printf("\nFin du programme\n");
	return 0;
}

