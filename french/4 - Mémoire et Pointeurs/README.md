
# Allocation mémoire et pointeurs
Attention ! Ce chapitre est un peu plus compliqué que les précédents, mais il est très important de le comprendre.



## 1. Qu'est-ce qu'un pointeur ?
Un pointeur est une variable qui contient l'adresse d'une autre variable.
En C, on déclare un pointeur en ajoutant un astérisque `*` devant le nom de la variable, ainsi 
Le caractère `&` permet de récupérer l'adresse d'une variable.
Exemple :
```c

int a = 42;
int *a_pointer = &a;

```
Dans cet exemple, la variable `a` contient la valeur `42`.
La variable `a_pointer` contient l'adresse de la variable `a`.
On peut accéder à la valeur de la variable `a` en utilisant le pointeur `a_pointer` :
```c

// Modifier la valeur de la variable a en utilisant le pointeur
*a_pointer = 21;

// Afficher la valeur de la variable a
printf("a = %d\n", *a_pointer);

// Afficher l'adresse de la variable a
printf("a_pointer = 0x%p\n", (void*)a_pointer);

```
Ici, on utilise le caractère `*` pour accéder à la valeur de la variable `a` à partir du pointeur `a_pointer`.

On utilise `%p` pour afficher l'adresse d'une variable sous la forme `0000000000000000`,
j'ai pris la liberté d'ajouter un `0x` devant l'adresse pour la rendre plus lisible.
Le cast en `(void*)` est nécessaire pour éviter un warning du compilateur, il permet de convertir le pointeur en un type `void*`
qui est un type générique qui peut contenir l'adresse de n'importe quel type de variable.

Sur la plupart des architectures, les pointeurs sont codées sur 64 bits, soit 8 octets.
C'est-à-dire qu'un pointeur occupe 8 octets en mémoire peu importe le type de la variable pointée (int, char, float, ...).

Il est possible de déclarer un pointeur sans lui donner d'adresse,
mais il faut faire attention à ne pas l'utiliser avant de lui avoir donné une adresse
car cela peut provoquer une erreur de segmentation (accès à une zone mémoire interdite).
```c

// Déclaration d'un pointeur sans lui donner d'adresse
int *a_pointer;

// Il est préférable d'initialiser le pointeur à NULL pour une meilleure
// lisibilité et pouvoir vérifier si le pointeur est initialisé
int *b_pointer = NULL;

```
`NULL` est une constante qui représente l'adresse `0x0000000000000000`, elle est définie dans une sous-bibliothèque de `stdio.h`.



## 2. Allocations mémoire
### 2.1 Allocation statique
L'allocation statique est la plus simple, elle consiste à déclarer une variable en lui donnant une valeur.
```c

int a = 42;
char b = 'u';
char hello[] = "Hello World!";
int joli_tableau[] = {1, 2, 3, 4, 5};

```
Les variables déclarées de cette manière sont aussi appelées variables "locales" car elles sont déclarées dans une fonction.
c'est-à-dire qu'elles ne sont accessibles que dans la fonction où elles sont déclarées.
Elles sont supprimées de la mémoire à la fin de la fonction dans laquelle elles sont déclarées.
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
Ce pointeur est stocké dans la variable `a_pointer` dans la fonction `main`.
La variable `a` est déclarée dans la fonction `my_function`, elle est donc locale à cette fonction.
La variable `a` est supprimée de la mémoire à la fin de la fonction `my_function`.
Le pointeur `a_pointer` pointe donc vers une zone mémoire qui n'est plus allouée.
Lorsque l'on essaie d'accéder à la valeur de la variable `a` à partir du pointeur `a_pointer`,
on accède à une zone mémoire interdite, ce qui provoque une erreur de segmentation.

### 2.2 Allocation dynamique
L'allocation dynamique permet de créer des variables qui ne sont pas locales à une fonction mais globales au programme.
Ces variables sont créées dans une zone mémoire appelée "tas" (heap en anglais).
Elles ne sont pas supprimées de la mémoire à la fin de la fonction dans laquelle elles sont déclarées.

En C, on utilise la fonction `malloc` pour allouer de la mémoire dans le tas.
Ainsi, pour que notre exemple précédent fonctionne, il suffit de remplacer la déclaration de la variable `a` par un appel à `malloc`.
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
Ici, on alloue la taille d'un entier avec `sizeof(int)`.
La fonction `malloc` renvoie un pointeur vers la zone mémoire allouée.

Contrairement à la déclaration statique, il faut libérer la mémoire dynamique allouée une fois que l'on n'en a plus besoin.
Pour cela, on utilise la fonction `free` en lui passant en paramètre le pointeur vers la zone mémoire à libérer.
Ici, on en a plus besoin à la fin de la fonction `main`, on libère donc la mémoire allouée pour la variable `a` à la fin de la fonction `main`.



## 3. Tableaux
### 3.1 Tableaux statiques
Un tableau est une suite de valeurs du même type, stockées les unes à la suite des autres en mémoire.
En C, on peut déclarer un tableau statique en lui donnant une taille et en lui affectant des valeurs.
```c

///// Il y a plusieurs façons de déclarer un tableau statique
// Déclarations d'un tableau statique de 5 entiers
int tableau[5] = {1, 2, 3, 4, 5};
int tableau2[] = {1, 2, 3, 4, 5};

// Déclaration d'un tableau statique de 5 entiers initialisé à 0
int tableau3[5] = {0};

```
Au niveau mémoire, les valeurs du tableau sont stockées les unes à la suite des autres, dans l'ordre de déclaration.
On peut accéder à une valeur du tableau en utilisant l'opérateur `[]` en lui passant en paramètre l'indice de la valeur à accéder.
```c

// Affichage de toutes les valeurs du tableau à l'aide d'une boucle for
int i;
int taille_tableau = 5;
for (i = 0; i < taille_tableau; i++) {
	printf("tableau[%d] = %d\n", i, tableau[i]);
}

```
Si on essaie d'accéder à une valeur du tableau qui n'existe pas, on accède à une zone mémoire interdite,
ce qui provoque une erreur de segmentation.

### 3.2 Tableaux dynamiques
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

### 3.3 Tableaux à plusieurs dimensions
Imaginons qu'on souhaite créer une matrice de 3 lignes et 4 colonnes.
On peut créer un tableau à deux dimensions en créant un tableau de tableaux.
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
Dans cet exemple, on a créé un tableau de pointeurs vers des tableaux. Chaque pointeur pointe vers un tableau de 4 entiers.
On peut accéder à une valeur de la matrice en utilisant deux fois l'opérateur `[]` pour les deux versions.
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

### 3.4 Similitudes entre tableaux et pointeurs
En fait en C, un tableau est toujours un pointeur vers la première valeur du tableau.
Cela signifie que l'on peut utiliser un tableau comme un pointeur et inversement.
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
Lorsqu'on incrémente un pointeur, il pointe vers la valeur suivante du tableau.
CEPENDANT, cela ne fonctionne que pour des pointeurs typés car le compilateur doit savoir de combien d'octets il doit incrémenter le pointeur pour qu'il pointe vers la valeur suivante.
Si on incrémente un pointeur non typé, le compilateur ne sait pas de combien d'octets il doit incrémenter le pointeur, il incrémente donc de 1 octet ou plante selon les compilateurs.
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
En mémoire, notre tableau de 2 entiers est stocké sur 8 octets (2 * 4 octets), l'affichage héxadécimal de ces 8 octets est le suivant :
- 00 00 00 01
- 00 00 00 02
Si on incrémente le pointeur de 1 octet, il pointe vers le deuxième octet du premier entier, ce qui fait que la valeur affichée sera
- 00 00 01 00

Pour incrémenter un pointeur non typé, il faut d'abord le caster en pointeur typé.
```c

// Déclaration d'un tableau statique de 2 entiers
int tableau[2] = {1, 2};
void *pointeur = tableau;

// On incrémente le pointeur de 4 octets (1 * 4 octets)
pointeur = (int*)pointeur + 1;

// Affichage de la valeur pointée par le pointeur (on obtient correctement la deuxième valeur du tableau)
printf("*pointeur = %d\n", *(int*)pointeur);

```



## 4. Exercice
Cela fait beaucoup de théorie, il est temps de passer à la pratique !
Analysez le fichier [main.c](src/main.c) et son jeu de pointeurs, il crée plusieurs pointeurs à l'aide d'une seule allocation dynamique.
Compléter le code pour allouer une matrice de 3 lignes et 4 colonnes avec une seule allocation dynamique.



## 5. realloc(), calloc()
Il existe deux autres fonctions pour allouer de la mémoire : `realloc()` et `calloc()`.
- `realloc()` permet de réallouer de la mémoire à un pointeur déjà alloué, par exemple si on veut augmenter la taille d'un tableau.
Mais cela n'est pas sans risque, si la mémoire n'est pas disponible, `realloc()` retourne `NULL` et le pointeur n'est pas modifié.
De plus, si la mémoire n'est pas contigüe, `realloc()` va allouer une nouvelle zone mémoire, copier les données de l'ancienne zone mémoire vers la nouvelle et libérer l'ancienne zone mémoire, ce qui peut être très coûteux en terme de performances et peut provoquer des erreurs si le pointeur était utilisé ailleurs.
- `calloc()` permet d'allouer de la mémoire et de l'initialiser à 0, c'est l'équivalent de `malloc()` suivi d'un `memset()` à 0.
En général, `calloc()` est plus lent que `malloc()` car il doit initialiser la mémoire allouée, on ne l'utilsie donc que si on a besoin d'une mémoire initialisée à 0.



## 6. Petit avertissement avant la conclusion
Lorsqu'on alloue de la mémoire, il faut toujours la libérer, sinon on aura des fuites mémoires et on risque de saturer la mémoire de la machine.
Autre point important, l'allocation dynamique est souvent mal utilisée et peut être remplacée par des allocations statiques dans la plupart des cas, allocations qui sont plus rapides et plus sûres.



# Conclusion
- Nous avons vu qu'est-ce qu'un pointeur et comment l'utiliser.
- Les différents types d'allocation mémoire.
- Quels sont les avantages et les inconvénients de l'allocation dynamique.
- Comment allouer de la mémoire à un tableau à une ou plusieurs dimensions.
- Comment allouer de la mémoire à un ensemble de variables de différents types.
- Les similitudes entre tableaux et pointeurs.
- Les fonctions `malloc()`, `free()`, `realloc()` et `calloc()`.
- L'importance de libérer la mémoire allouée dynamiquement.
On peut maintenant passer à la suite !



