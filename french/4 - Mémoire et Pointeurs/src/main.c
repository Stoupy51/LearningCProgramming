
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Introduction aux allocations mémoires et aux pointeurs
 * 
 * @return int
 */
int main() {

	///// Exemple de pointeur sur un entier
	// Déclaration d'un entier et d'un pointeur sur un entier
	int a = 42;
	int *a_pointer = NULL; // le type de a_pointer est (int*)
	printf("a_pointer = 0x%p\n", (void*)a_pointer);

	// Affectation de l'adresse de a à a_pointer et affichage
	a_pointer = &a;
	printf("a = %d\n", a);
	printf("a_pointer = 0x%p\n", (void*)a_pointer);
	printf("*a_pointer = %d\n", *a_pointer);
	printf("\n");



	///// Création de pointeurs sur plusieurs types de données
	// Déclaration des variables
	size_t size = 0;	// size_t est un type de données pour représenter des tailles en octets
	char *char_pointer = NULL;
	int *int_pointer = NULL;
	long *long_pointer = NULL;
	float *float_pointer = NULL;
	double *double_pointer = NULL;

	// Allocation de mémoire pour les pointeurs
	size = sizeof(char) + sizeof(int) + sizeof(long) + sizeof(float) + sizeof(double);
	printf("Allocation de %zu octets\n", size);
	void *void_pointer = malloc(size);

	// Affectation des pointeurs
	char_pointer = (char*)void_pointer;
	int_pointer = (int*)(char_pointer + 1);	// On ajoute 1 à l'adresse de char_pointer pour passer à l'adresse suivante (+1 octet étant donné que char_pointer est un pointeur sur un char)
	long_pointer = (long*)(int_pointer + 1); // On ajoute 1 à l'adresse de int_pointer pour passer à l'adresse suivante (+4 octets étant donné que int_pointer est un pointeur sur un int)
	float_pointer = (float*)(long_pointer + 1); // On ajoute 1 à l'adresse de long_pointer pour passer à l'adresse suivante (+8 octets étant donné que long_pointer est un pointeur sur un long)
	double_pointer = (double*)(float_pointer + 1); // On ajoute 1 à l'adresse de float_pointer pour passer à l'adresse suivante (+4 octets étant donné que float_pointer est un pointeur sur un float)

	// Autre méthode pour affecter les pointeurs (elle est plus élégante mais c'est exactement le même principe)
	char_pointer = (char*)void_pointer;
	int_pointer = (int*)&char_pointer[1];
	long_pointer = (long*)&int_pointer[1];
	float_pointer = (float*)&long_pointer[1];
	double_pointer = (double*)&float_pointer[1];

	// Cette méthode est aussi possible, mais tu ne vas pas l'utiliser hein !
	char_pointer = (char*)*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&void_pointer;

	// Affectation des valeurs
	*char_pointer = 'u';
	*int_pointer = 42;
	*long_pointer = 123456789;
	*float_pointer = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;
	*double_pointer = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;

	// Affichage des valeurs
	printf("char_pointer = 0x%p | *char_pointer = '%c'\n", (void*)char_pointer, *char_pointer);
	printf("int_pointer = 0x%p | *int_pointer = %d\n", (void*)int_pointer, *int_pointer);
	printf("long_pointer = 0x%p | *long_pointer = %ld\n", (void*)long_pointer, *long_pointer);
	printf("float_pointer = 0x%p | *float_pointer = %.64f\n", (void*)float_pointer, *float_pointer);
	printf("double_pointer = 0x%p | *double_pointer = %.64f\n", (void*)double_pointer, *double_pointer);
	printf("\n");

	// Libération de la mémoire
	free(void_pointer);	// Étant donné que void_pointer pointe vers le début de la mémoire allouée, il n'est pas nécessaire de libérer les autres pointeurs



	///// Création d'une matrice d'entiers avec un seul malloc() (En fait, il y a deux malloc() tkt)
	///// Le but est de créer un tableau de pointeurs sur des tableaux d'entiers
	///// Le premier pointeur pointe vers le premier tableau d'entiers (0)
	///// Le deuxième pointeur pointe vers le deuxième tableau d'entiers (colonnes * 1)
	///// Le troisième pointeur pointe vers le troisième tableau d'entiers (colonnes * 2)
	///// etc.
	///// Les seules choses à modifier sont les lignes avec des TODO
	// Déclaration des variables
	int **matrix = NULL, *matrix_pointer = NULL;
	int lignes = 3;
	int colonnes = 4;
	size_t matrix_size = 0;

	// Allocation de mémoire pour la matrice
	matrix_size = 0; // TODO: Calculer la taille de la matrice
	printf("Allocation de %zu octets\n", matrix_size);
	matrix_pointer = NULL; // TODO: Allouer la mémoire pour la matrice

	// Allocation de mémoire pour les lignes
	matrix = malloc(sizeof(int*) * lignes); // Cadeau celui-ci

	// Affectation des pointeurs
	int i;
	for (i = 0; i < lignes; i++) {
		matrix[i] = NULL; // TODO: Affecter les pointeurs. Astuce : '& matrix_pointer[???]' ou 'matrix_pointer + ???'
	}

	// Affichage des valeurs de la matrice (Cela sera donc des valeurs aléatoires : les octets dans la mémoire qu'il y avait avant)
	// Interdit de modifier le code ci-dessous, il doit fonctionner.
	int j;
	for (i = 0; i < lignes; i++) {
		for (j = 0; j < colonnes; j++) {
			printf("matrix[%d][%d] = %d\n", i, j, matrix[i][j]);
		}
	}

	// Libération de la mémoire
	free(matrix_pointer);
	free(matrix);

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	printf("\nFin du programme\n");
	return 0;
}

