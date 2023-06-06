
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Introduction à la gestion d'erreurs
 * 
 * @param argc		Nombre d'arguments passés au programme
 * @param argv		Arguments passés au programme
 * 
 * @return int
 */
int main(int argc, char* argv[]) {

	///// IMPORTANT, Pour l'exemple, on ne retournera pas -1 en cas d'erreur afin de continuer l'exécution du programme /////

	// Vérifier que l'utilisateur a bien passé 3 arguments au programme
	if (argc != 3) {

		// Afficher un message d'erreur
		char error_msg[] = "\nUsage: %s <number> <float> <text>\n";
		// Afficher un message d'erreur pertinent avec le nom du programme (argv[0])
		fprintf(stderr, error_msg, argv[0]);

		// vérifier que le premier argument est bien un entier, le deuxième un flottant et le troisième une chaine de caractères
		// Càd que les fonctions atoi, atof et strlen ne renvoient pas 0
		if (atoi(argv[1]) == 0 || atof(argv[2]) == 0 || strlen(argv[3]) == 0) {
			fprintf(stderr, "\nLes arguments ne sont pas valides\n");
		}
	}

	// Ouverture d'un fichier inexistant
	FILE *file = fopen("super_inexistant.uwu", "r");
	if (file == NULL) {
		fprintf(stderr, "\nErreur lors de l'ouverture du fichier: %s\n", strerror(errno));
	}

	// Mauvaise allocation mémoire (100 000 000 000 octets : 100 Go)
	void *ptr = malloc(100000000000);
	if (ptr == NULL) {
		fprintf(stderr, "\nErreur lors de l'allocation memoire: %s\n", strerror(errno));
	}

	// Suppression d'un fichier inexistant
	int code = remove("super_inexistant.uwu");
	if (code != 0) {
		fprintf(stderr, "\nErreur lors de la suppression du fichier: %s\n", strerror(errno));
	}


	// Fermeture d'un fichier déjà fermé
	code = fclose(file);
	if (code != 0) {
		fprintf(stderr, "\nErreur lors de la fermeture du fichier: %s\n", strerror(errno));
	}

	// Comparaison de deux chaines de caractères
	char *str1 = "Hello World!";
	char *str2 = "Hello Wurld!";
	code = strcmp(str1, str2);
	// Attention y'a 3 valeurs de retour possibles
	if (code != 0) {
		fprintf(stderr, "\nErreur lors de la comparaison des chaines de caracteres\n");
	}

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur (même si ce n'est pas le cas x)
	printf("\nFin du programme\n");
	return 0;
}

