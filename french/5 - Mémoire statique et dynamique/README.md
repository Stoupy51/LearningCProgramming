
# Allocation mémoire statique et dynamique
Attention ! Ce chapitre est sûrement le plus compliqué de tous, mais il est très important de le comprendre.


# <u>Sommaire</u>
- [1. Allocations mémoire](#1-allocations-mémoire)
  - [1.1 Allocation statique](#11-allocation-statique)
  - [1.2 Allocation dynamique](#12-allocation-dynamique)
- [2. Tableaux](#2-tableaux)
  - [2.1 Tableaux statiques](#21-tableaux-statiques)
  - [2.2 Tableaux dynamiques](#22-tableaux-dynamiques)
  - [2.3 Tableaux à plusieurs dimensions](#23-tableaux-à-plusieurs-dimensions)
  - [2.4 Similitudes entre tableaux et pointeurs](#24-similitudes-entre-tableaux-et-pointeurs)
- [3. Exercice](#3-exercice)
- [4. realloc(), calloc()](#4-realloc-calloc)
- [5. Petit avertissement avant la conclusion](#5-petit-avertissement-avant-la-conclusion)
- [Conclusion](#conclusion)

<br>

## 1. Allocations mémoire
### 1.1 Allocation statique
L'allocation statique est la plus simple, elle consiste à déclarer une variable en lui donnant une valeur.

```c

int a = 42;
char b = 'u';
char hello[] = "Hello World!";
int joli_tableau[] = {1, 2, 3, 4, 5};

```
Les variables déclarées de cette manière sont aussi appelées variables "locales" car elles sont déclarées dans une fonction.
<br>c'est-à-dire qu'elles ne sont accessibles que dans la fonction où elles sont déclarées.
<br>Elles sont supprimées de la mémoire à la fin de la fonction dans laquelle elles sont déclarées.

Imaginons donc un programme qui utilise une fonction qui renvoie un pointeur vers une variable locale :
```c

// Déclaration d'une fonction qui renvoie un pointeur vers un entier
int* my_function() {
	int a = 42;
	return &a;
}

// Fonction main
int main() {

	// Appel de la fonction my_function
	int *a_pointer = my_function();

	// Affichage de la valeur de la variable a
	printf("a = %d\n", *a_pointer);

	// Ce message ne devrait pas s'afficher car le programme plante : 'Segmentation fault'
	printf("Tu ne devrais pas voir ce message\n");

	return 0;
}

```
Dans cet exemple, la fonction `my_function` renvoie un pointeur vers un entier.
<br>Ce pointeur est stocké dans la variable `a_pointer` dans la fonction `main`.
<br>La variable `a` est déclarée dans la fonction `my_function`, elle est donc locale à cette fonction.
<br>La variable `a` est supprimée de la mémoire à la fin de la fonction `my_function`.
<br>Le pointeur `a_pointer` pointe donc vers une zone mémoire qui n'est plus allouée.

Lorsque l'on essaie d'accéder à la valeur de la variable `a` à partir du pointeur `a_pointer`,
on accède à une zone mémoire interdite, ce qui provoque une erreur de segmentation.

<br>

### 1.2 Allocation dynamique
L'allocation dynamique permet de créer des variables qui ne sont pas locales à une fonction mais globales au programme.
<br>Ces variables sont créées dans une zone mémoire appelée "tas" (heap en anglais).
<br>Elles ne sont pas supprimées de la mémoire à la fin de la fonction dans laquelle elles sont déclarées.

En C, on utilise la fonction `malloc` pour allouer de la mémoire dans le tas.
<br>Ainsi, pour que notre exemple précédent fonctionne,
<br>il suffit de remplacer la déclaration de la variable `a` par un appel à `malloc` :

```c

// Déclaration d'une fonction qui renvoie un pointeur vers un entier
int* my_function() {

	// Allocation de mémoire pour un entier (4 octets sur la plupart des architectures)
	int *a = malloc(sizeof(int));

	// On affecte la valeur 42 à la variable a
	*a = 42;

	// On renvoie le pointeur vers la variable a
	return a;
}

// Fonction main
int main() {

	// Appel de la fonction my_function
	int *a_pointer = my_function();

	// Affichage de la valeur de la variable a
	printf("a = %d\n", *a_pointer);

	// Ce message devrait s'afficher
	printf("Tu devrais voir ce message\n");

	// On libère la mémoire allouée pour la variable a
	free(a_pointer);

	return 0;
}

```
La fonction `malloc` prend en paramètre la taille de la zone mémoire à allouer en octets.
<br>Ici, on alloue la taille d'un entier avec `sizeof(int)` (4 octets sur la plupart des architectures).
<br>La fonction `malloc` renvoie un pointeur vers la zone mémoire allouée.

Contrairement à la déclaration statique, il faut libérer la mémoire dynamique allouée une fois que l'on n'en a plus besoin.
<br>Pour cela, on utilise la fonction `free` en lui passant en paramètre le pointeur vers la zone mémoire à libérer.
<br>Ici, on en a plus besoin à la fin de la fonction `main`, on libère donc
<br>la mémoire allouée pour la variable `a` à la fin de la fonction `main`.

<br>

## 2. Tableaux
### 2.1 Tableaux statiques
Un tableau est une suite de valeurs du même type, stockées les unes à la suite des autres en mémoire.
<br>En C, on peut déclarer un tableau statique en lui donnant une taille et en lui affectant des valeurs.

```c

///// Il y a plusieurs façons de déclarer un tableau statique
// Déclarations d'un tableau statique de 5 entiers
int tableau[5] = {1, 2, 3, 4, 5};
int tableau2[] = {1, 2, 3, 4, 5};

// Déclaration d'un tableau statique de 5 entiers initialisé à 0
int tableau3[5] = {0};

```
Au niveau mémoire, les valeurs du tableau sont stockées les unes à la suite des autres, dans l'ordre de déclaration.

<br>On peut accéder à une valeur du tableau en utilisant l'opérateur `[]` en lui passant en paramètre l'indice de la valeur à accéder.

```c

// Affichage de toutes les valeurs du tableau à l'aide d'une boucle for
int i;
int taille_tableau = 5;
for (i = 0; i < taille_tableau; i++) {
	printf("tableau[%d] = %d\n", i, tableau[i]);
}

```
Si on essaie d'accéder à une valeur du tableau qui n'existe pas, on accède à une zone mémoire interdite,
<br>ce qui provoque une erreur de segmentation.

<br>

### 2.2 Tableaux dynamiques
En C, on peut allouer un tableau dynamique en utilisant la fonction `malloc`.

```c

// Déclaration d'un tableau dynamique de 5 entiers (5 * 4 octets = 20 octets)
int taille_tableau = 5;
int *tableau = malloc(taille_tableau * sizeof(int));

// On affecte des valeurs au tableau
tableau[0] = 1;
tableau[1] = 2;
tableau[2] = 3;
tableau[3] = 4;
tableau[4] = 5;

// Affichage de toutes les valeurs du tableau à l'aide d'une boucle for
int i;
for (i = 0; i < taille_tableau; i++) {
	printf("tableau[%d] = %d\n", i, tableau[i]);
}

// On libère la mémoire allouée pour le tableau
free(tableau);

```

<br>

### 2.3 Tableaux à plusieurs dimensions
Imaginons qu'on souhaite créer une matrice de 3 lignes et 4 colonnes.
<br>On peut créer un tableau à deux dimensions en créant un tableau de tableaux.

```c

///// Version statique
int matrice[3][4] = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12}
};

///// Version dynamique
int lignes = 3;
int colonnes = 4;
int **matrice = malloc(lignes * sizeof(int*));
int i;
for (i = 0; i < lignes; i++) {
	matrice[i] = malloc(colonnes * sizeof(int));
}

// On affecte des valeurs à la matrice
matrice[1][2] = 7; // On affecte la valeur 7 à la case de la ligne 1 et de la colonne 2
...

// On libère la mémoire allouée pour la matrice
for (i = 0; i < lignes; i++) {
	free(matrice[i]);
}
free(matrice);


```
La version statique est plus simple à utiliser mais la version dynamique est plus flexible car elle peut dépendre de variables.
<br>Dans cet exemple, on a créé un tableau de pointeurs vers des tableaux. Chaque pointeur pointe vers un tableau de 4 entiers.
<br>On peut accéder à une valeur de la matrice en utilisant deux fois l'opérateur `[]` pour les deux versions :

```c

// Affichage de toutes les valeurs de la matrice à l'aide de deux boucles for
int lignes = 3, colonnes = 4;
int i, j;
for (i = 0; i < lignes; i++) {
	for (j = 0; j < colonnes; j++) {
		printf("matrice[%d][%d] = %d\n", i, j, matrice[i][j]);
	}
}

```

<br>

### 2.4 Similitudes entre tableaux et pointeurs
En fait en C, un tableau est toujours un pointeur vers la première valeur du tableau.
<br>Cela signifie que l'on peut utiliser un tableau comme un pointeur et inversement.

```c

// Déclaration d'un tableau statique de 5 entiers
int tableau[5] = {1, 2, 3, 4, 5};

// Déclaration d'un tableau qui pointe vers le tableau statique, on peut utiliser les deux notations
int *pointeur = &tableau[0];
int *pointeur2 = tableau;

// On peut accéder à la première valeur du tableau à l'aide de deux notations
printf("tableau[0] = %d\n", tableau[0]);
printf("tableau[0] = %d\n", *tableau);

// On peut accéder à la deuxième valeur du tableau à l'aide de trois notations
printf("tableau[1] = %d\n", tableau[1]);
printf("tableau[1] = %d\n", *(tableau + 1));
int *pointeur3 = tableau + 1;
printf("tableau[1] = %d\n", *pointeur3);

// On en vient à la conclusion que tableau[i] est équivalent à *(tableau + i)

```
Lorsqu'on incrémente un pointeur, il pointe vers la valeur suivante au niveau mémoire.
<br>CEPENDANT, cela ne fonctionne que pour des pointeurs typés car le compilateur doit savoir
<br>de combien d'octets il doit incrémenter le pointeur pour qu'il pointe vers la valeur suivante.

Si on incrémente un pointeur non typé, le compilateur ne sait pas de combien d'octets il doit incrémenter le pointeur,
<br>il incrémente donc de 1 octet ou plante selon les compilateurs.

```c

// Déclaration d'un tableau statique de 2 entiers
int tableau[2] = {1, 2};

// Déclaration d'un pointeur non typé qui pointe vers le tableau statique
void *pointeur = tableau;

// On incrémente le pointeur de 1 octet
pointeur++;

// Affichage de la valeur pointée par le pointeur (on obtient une valeur éronnée : un mix des deux premières valeurs du tableau)
printf("*pointeur = %d\n", *(int*)pointeur);

```
En mémoire, notre tableau de 2 entiers est stocké sur 8 octets (2 * 4 octets),
<br>l'affichage héxadécimal de ces 8 octets est le suivant :
- 00 00 00 01
- 00 00 00 02

Si on incrémente le pointeur de 1 octet, il pointe vers le deuxième octet du premier entier,
<br>ce qui fait que la valeur affichée sera :
- 00 00 01 00

Alors, pour incrémenter un pointeur non typé, il faut d'abord le caster en pointeur typé :

```c

// Déclaration d'un tableau statique de 2 entiers
int tableau[2] = {1, 2};
void *pointeur = tableau;

// On incrémente le pointeur de 4 octets (1 * 4 octets)
pointeur = (int*)pointeur + 1;

// Affichage de la valeur pointée par le pointeur (on obtient correctement la deuxième valeur du tableau)
printf("*pointeur = %d\n", *(int*)pointeur);

```

<br>

## 3. Exercice
Cela fait beaucoup de théorie, il est temps de passer à la pratique !
<br>Analysez le fichier [`main.c`](src/main.c) et son jeu de pointeurs,
<br>il crée plusieurs pointeurs à l'aide d'une seule allocation dynamique.
<br>Compléter le code pour allouer une matrice de 3 lignes et 4 colonnes avec une seule allocation dynamique.

<br>

## 4. realloc(), calloc()
Il existe deux autres fonctions pour allouer de la mémoire : `realloc()` et `calloc()`.
- `realloc()` permet de réallouer de la mémoire à un pointeur déjà alloué, par exemple si on veut augmenter la taille d'un tableau.
<br>Mais cela n'est pas sans risque, si la mémoire n'est pas disponible, `realloc()` retourne `NULL` et le pointeur n'est pas modifié.
<br>De plus, si la mémoire n'est pas contigüe, `realloc()` va :
- allouer une nouvelle zone mémoire
- copier les données de l'ancienne zone mémoire vers la nouvelle
- et libérer l'ancienne zone mémoire

ce qui peut être très coûteux en terme de performances et peut provoquer des erreurs si le pointeur était utilisé ailleurs.

Il existe aussi la fonction suivante :
- `calloc()`, elle permet d'allouer de la mémoire et de l'initialiser à 0,
<br>c'est l'équivalent de `malloc()` suivi d'un `memset()` à 0.

En général, `calloc()` est plus lent que `malloc()` car il doit initialiser la mémoire allouée,
<br>on ne l'utilise donc que si on a vraiment besoin d'une mémoire initialisée à 0.

<br>

## 5. Petit avertissement avant la conclusion
Lorsqu'on alloue de la mémoire, il faut toujours la libérer, sinon on aura des fuites mémoires
<br>et on risque de saturer la mémoire de la machine.

Autre point important, l'allocation dynamique est souvent mal utilisée et peut être remplacée par
<br>des allocations statiques dans la plupart des cas, allocations qui sont plus rapides et plus sûres.

<br>

# Conclusion
- Les différents types d'allocation mémoire.
- Quels sont les avantages et les inconvénients de l'allocation dynamique.
- Comment allouer de la mémoire à un tableau à une ou plusieurs dimensions.
- Comment allouer de la mémoire à un ensemble de variables de différents types.
- Les similitudes entre tableaux et pointeurs.
- Les fonctions `malloc()`, `free()`, `realloc()` et `calloc()`.
- L'importance de libérer la mémoire allouée dynamiquement.

On peut maintenant passer à la suite !



