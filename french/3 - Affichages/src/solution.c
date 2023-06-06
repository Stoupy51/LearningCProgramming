
#include <stdio.h>

/**
 * @brief Fonction principale exécutée au lancement du programme
 * Elle crée un affichage de la forme suivante:
 * 
 * Mon entier vaut 42
 * Mon caractere vaut 'u'
 * Ma chaine de caracteres vaut "Hello World!"
 * Mon entier long vaut 123456789
 * Mon flottant vaut 3.1415927410125732421875000000000000000000000000000000000000000000
 * Mon double vaut 3.1415926535897931159979634685441851615905761718750000000000000000
 * 
 * @return int
 */
int main() {

	// Déclaration des variables
	int my_int = 42;
	char my_char = 'u';
	char my_string[] = "Hello World!";
	long my_long = 123456789;
	float my_float = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;
	double my_double = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;

	///// Completez le programme ici /////
	printf("Mon entier vaut %d\n", my_int);
	printf("Mon caractère vaut '%c'\n", my_char);
	printf("Ma chaine de caracteres vaut \"%s\"\n", my_string);
	printf("Mon entier long vaut %ld\n", my_long);
	printf("Mon flottant vaut %.64f\n", my_float);
	printf("Mon double vaut %.64f\n", my_double);

	// Retourne 0 pour indiquer que le programme s'est exécuté sans erreur
	return 0;
}

