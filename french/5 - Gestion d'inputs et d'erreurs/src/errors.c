
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

	// TODO Vérifier que l'utilisateur a bien passé 3 arguments au programme
	if (argc != -1) {

		// Afficher un message d'erreur
		char error_msg[] = "Usage: %s <number> <float> <text>\n";
		// TODO Afficher un message d'erreur pertinent avec le nom du programme (argv[0])

		// On retire le "unused variable" warning
		error_msg[0] = error_msg[0];

		// Return -1 pas touche celui là
		return -1;
	}

	// TODO vérifier que le premier argument est bien un entier, le deuxième un flottant et le troisième une chaine de caractères
	// Càd que les fonctions atoi, atof et strlen ne renvoient pas une mauvaise valeur (checkez la doc de ces fonctions)
	// (0 ou -1 selon les architectures)
	if (atoi(argv[1]) == -1 || atof(argv[2]) == 0 || strlen(argv[3]) == 0) {
		fprintf(stderr, "\nLes arguments ne sont pas valides\n");
	}

	// Ouverture d'un fichier inexistant
	char filename[] = "super_inexistant.uwu";
	FILE *file = fopen(filename, "r");
	// TODO : C'est un pointeur, donc on peut le comparer à NULL

	// Mauvaise allocation mémoire (100 000 000 000 octets : 100 Go)
	void *ptr = malloc(100000000000);
	// TODO

	// Suppression d'un fichier inexistant
	int code = remove(filename);	// On peut vérifier le code de retour de la fonction remove
	// TODO

	// Libération d'une zone mémoire déjà libérée
	// (nan je déconne, c'est pas possible, le programme crash avant), free() n'a pas de valeur de retour

	// Comparaison de deux chaines de caractères
	char *str1 = "Hello World!";
	char *str2 = "Hello Wurld!";
	code = strcmp(str1, str2);
	// TODO : attention y'a 3 valeurs de retour possibles

	// On retire le "unused variable" warning
	code = code;
	ptr = ptr;
	char *unused = argv[0];
	unused = unused;

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur (même si ce n'est pas le cas x)
	printf("\nFin du programme\n");
	return 0;
}

