
# Gestion d'inputs et d'erreurs
Dans ce chapitre, nous allons voir comment gérer les entrées de l'utilisateur et les erreurs.

# <u>Sommaire</u>
- TODO

<br>

## 1. Entrées de l'utilisateur
Il y a plusieurs manières de gérer les entrées de l'utilisateur, nous allons voir les deux principales.

<br>

### 1.1. Arguments de la fonction main
La première manière est de passer les arguments de la fonction `main` à notre programme.
<br>Comme expliqué dans un chapitre précédent, la fonction `main` peut prendre deux arguments :
- `argc` : le nombre d'arguments passés à notre programme
- `argv` : un tableau de chaînes de caractères contenant les arguments passés à notre programme

Ainsi, on peut récupérer l'entrée utilisateur en utilisant le tableau `argv`.
<br>Cependant, ce tableau contient aussi le nom du programme, c'est-à-dire `argv[0]`.
<br>Chaque argument est une chaîne de caractères, cela signifie que lorsqu'on souhaite récupérer un nombre,
<br>il faut le convertir dans le type souhaité.

Voici un exemple de programme qui récupère le premier argument et le convertit en entier :
```c

#include <stdio.h>

int main(int argc, char *argv[]) {
	int number = atoi(argv[1]);
	printf("Le nombre est %d\n", number);
	return 0;
}

```
La fonction `atoi` permet d'interpréter une chaîne de caractères en entier.
<br>Il existe aussi `atof` pour convertir en flottant, et `atol` pour convertir en long.

<br>

### 1.2 Exercice
Complétez le début du programme [`args.c`](src/args.c) pour qu'il affiche correctement les deux arguments passés au programme.
<br>Soit, un entier et une chaîne de caractères.

Il est dit dans l'exercice que vous devez copier la chaîne de caractères,
<br>pour cela, vous devez utiliser la fonction `strlen` du fichier d'en-tête `string.h` pour connaître la taille de la chaîne,
<br>puis allouer la mémoire nécessaire avec la fonction `malloc` du fichier d'en-tête `stdlib.h`.
<br>Cela vous introduira unn concept important en C.

Une fois que votre programme fonctionne ou plante lors de l'affichage de la chaines de caractères copiée,
lisez la suite juste en dessous.

<br>

### 1.3. Chaînes de caractères
En C, une chaîne de caractères est un tableau de caractères terminé par le caractère nul `\0`.
<br>Par conséquent, la chaine "Hey" est en réalité le tableau `['H', 'e', 'y', '\0']`.

Cela signifie que pour copier une chaîne de caractères, il faut copier tous les caractères jusqu'au caractère nul `\0` compris.
<br>C'est pour cela que la fonction `strlen` renvoie la taille de la chaîne sans compter le caractère nul, soit 3 pour "Hey".

L'allocation de mémoire avec `malloc` doit donc être de la taille de la chaîne + 1 pour le caractère nul `\0` :
```c

int main() {
	char str[] = "Hey";
	size_t size = strlen(str);
	char *copy = malloc(size + 1);
	memcpy(copy, str, size + 1);
	return 0;
}

```
Bien sûr, il y a plus simple et sûre pour copier une chaîne de caractères, la fonction `strdup` du fichier d'en-tête `string.h`.
```c

int main() {
	char str[] = "Hey";
	char *copy = strdup(str);
	return 0;
}

```
Elle fait exactement la même chose que le code précédent, mais en une seule ligne, wow !
<br>Vous pouvez maintenant corriger l'exercice [`args.c`](src/args.c) !

<br>

### 1.4. Saisie de l'utilisateur
La deuxième manière de récupérer l'entrée de l'utilisateur est d'utiliser la fonction `scanf` du fichier d'en-tête `stdio.h`.
<br>Cette fonction permet de lire l'entrée de l'utilisateur en fonction d'un format à n'importe quel endroit du programme.
<br>Par exemple, si on souhaite récupérer un entier, on peut utiliser le format `%d` :

```c

int main() {
	int number;
	scanf("%d", &number);
	printf("Le nombre est %d\n", number);
	return 0;
}

```
La fonction `scanf` prend en premier argument le format, puis des pointeurs vers les variables à remplir d'où le `&number`.

Cette fonction ne crée aucun affichage de par elle-même, il faut donc afficher le nombre après l'avoir récupéré si on souhaite le voir.

Elle lit le flux d'entrée standard `stdin`, et attend que l'utilisateur appuie sur la touche entrée pour valider son entrée.

Au niveau technique, elle lit les caractères un par un jusqu'à ce qu'elle trouve un caractère blanc
<br>(espace, tabulation, retour à la ligne, ...).
<br>Elle convertit ensuite la chaîne de caractères en fonction du format, et remplit la variable pointée.

Il est possible de passer plusieurs formats à la fonction `scanf`, mais c'est plutôt déconseillé et les cas d'utilisation sont rares.

Maintenant, si on souhaite récupérer une chaîne de caractères, on pourrait se dire qu'on peut utiliser le format `%s` :
```c

int main() {
	char str[10] = {'\0'};
	scanf("%s", str);
	printf("La chaîne est %s\n", str);
	return 0;
}

```
Cependant, cette manière de faire est dangereuse, car si l'utilisateur entre une chaîne de caractères de plus de 10 caractères,
<br>il y aura un dépassement de mémoire, et donc un comportement indéfini, le caractère `\0` n'étant pas présent dans le tableau.
<br>Cela s'appelle un *buffer overflow*, et c'est une des failles de sécurité les plus connues en informatique.

Il faut donc spécifier la taille du tableau dans le format `%s` :
```c

int main() {
	char str[10] = {'\0'};
	scanf("%9s", str);
	printf("La chaîne est %s\n", str);
	return 0;
}

```
Le format `%9s` permet de lire au maximum 9 caractères, le 10ème étant le caractère nul `\0`.
<br>Ainsi, si l'utilisateur entre une chaîne de caractères de plus de 9 caractères, cette chaîne sera tronquée !

<br>

### 1.5. Exercice
Complétez le programme [`scanf.c`](src/scanf.c) pour qu'il affiche correctement les deux entrées de l'utilisateur.

Vous avez même un petit exemple fonctionnel de programme qui scan des entiers, les ajoute dans une liste,
<br>et les affiche tant que l'utilisateur n'entre pas 'q' pour quitter.

Vous pouvez utiliser la fonction `strcmp` du fichier d'en-tête `string.h` pour comparer deux chaînes de caractères,
<br>mais étant donné qu'on cherche que le premier caractère, vous pouvez aussi utiliser l'opérateur `==` avec [0].

Attention, il est strictement impossible de comparer deux chaînes de caractères avec l'opérateur `==` !
<br>Cela ne compare que les adresses mémoires des deux chaînes, et non leur contenu -_-'.

<br>

## 2. Gestion d'erreurs
Comme précisé dans le chapitre sur les affichages, il existe plusieurs façons d'afficher des erreurs.
<br>Les fonctions que vous utiliserez n'afficheront presque quasiment jamais d'erreurs, vous devez
<br>vous-même contrôler les valeurs de retour de celles-ci pour savoir si elles ont échoué.

<br>

### 2.1. Valeurs de retour
Par exemple, la fonction `malloc` renvoie `NULL` si elle n'a pas pu allouer la mémoire demandée.

Voici un exemple de programme qui affiche une erreur si l'allocation de mémoire a échoué :

```c

int main() {

	// On alloue 10 octets de mémoire
	char *str = malloc(10 * sizeof(char));

	// On vérifie si l'allocation a échoué (pointeur NULL)
	if (str == NULL) {
		fprintf(stderr, "Erreur d'allocation de mémoire\n");
		return -1;
	}

	// On libère la mémoire et on quitte le programme
	free(str);
	return 0;
}

```
Cependant, il peut manquer des informations pour comprendre l'erreur.

La fonction `perror` du fichier d'en-tête `stdio.h` permet d'afficher le message d'erreur correspondant à la valeur de `errno`.
- `errno` est une variable globale (int) qui contient le code d'une erreur, et qui est modifiée par les fonctions qui échouent.
<br>vous pouvez également la modifier vous-même, mais c'est déconseillé si vous ne savez pas ce que vous faites (librairie).
- `perror` affiche le message d'erreur correspondant à la valeur de `errno` sur la sortie d'erreur `stderr`.

Ainsi, si on souhaite afficher le message d'erreur correspondant à l'allocation de mémoire, on peut faire :
```c

int main() {
	char *str = malloc(10 * sizeof(char));
	if (str == NULL) {
		perror("Erreur d'allocation de mémoire");
		return -1;
	}
	free(str);
	return 0;
}

```
L'affichage sera le suivant : `Erreur d'allocation de mémoire: Cannot allocate memory`.
<br>Le problème avec `perror` est qu'il n'est pas possible de spécifier autre chose
<br>qu'un message d'erreur fixe, rendant l'usage de `%s` impossible.

Une autre manière d'afficher des erreurs est d'utiliser la fonction `strerror` du fichier d'en-tête `string.h`.
<br>Cette fonction prend en argument un code d'erreur, et renvoie un message d'erreur correspondant (char*).
<br>Ce char* ne doit pas être modifié, et n'est pas forcément alloué dynamiquement, il ne faut donc pas le libérer.
<br>En général, on cherche sur internet si la fonction renvoie un char* alloué dynamiquement ou non pour savoir si on doit le libérer.

Ainsi, si on souhaite afficher le message d'erreur correspondant à l'allocation de mémoire, on peut faire :
```c

int main() {
	char nom_programme[] = "exemple";
	char *str = malloc(10 * sizeof(char));
	if (str == NULL) {
		fprintf(stderr, "[%s] Erreur d'allocation de mémoire: %s\n", nom_programme, strerror(errno));
		return -1;
	}
	free(str);
	return 0;
}

```

<br>

### 2.2. Exercice
Complétez le programme [`errors.c`](src/errors.c) pour qu'il affiche toutes les erreurs possibles des fonctions utilisées.

L'exercice est simple, mais ce qui compte est la pertinence des messages d'erreurs.
<br>Ils doivent être compréhensibles afin de vous aider à débugger votre programme.

<br>

# Conclusion
- Dans ce chapitre, vous avez appris les différentes façons de traiter les entrées de l'utilisateur.
- L'utilisation des fonctions `printf` et `scanf` permettent de lire et d'écrire sur la sortie standard.
- Les risques de buffer overflow sont à prendre en compte lors de l'utilisation de `scanf`.
- Les fonctions `perror` et `strerror` permettent d'afficher des erreurs, combinées avec `fprintf` et `stderr`.
- La variable globale `errno` contient le code d'erreur de la dernière fonction qui a échoué.

Prochain chapitre, les fichiers headers !

