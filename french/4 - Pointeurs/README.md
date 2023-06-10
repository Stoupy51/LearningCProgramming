
# Pointeurs en C
Concentrez-vous bien car les deux prochains chapitres sont les plus importants du cours,
mais aussi les plus difficiles à comprendre. Mais une fois maitrisés,
vous vous en sortirez très bien dans la programmation en C.



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



## 2. Exemples d'utilisation des pointeurs
### 2.1. Permutation de deux variables
Imaginons que nous voulons écrire une fonction qui permute les valeurs de deux variables.
```c

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

```
Cette fonction ne fonctionne pas car les variables `a` et `b` sont des copies des variables passées en paramètres.
Pour que la fonction fonctionne, il faut passer les adresses des variables en paramètres.
Par conséquent, la fonction `swap` doit prendre deux pointeurs en paramètres.

### 2.2. Exercice 1
Corrigez la fonction `swap` du fichier [`swap.c`](src/swap.c) pour qu'elle fonctionne correctement.

### 2.3. Allocation dynamique de mémoire
En C, il est possible d'allouer de la mémoire à l'exécution du programme.
Pour cela, on utilise la fonction `malloc` qui prend en paramètre la taille en octets de la mémoire à allouer.
```c

// Allouer 4 octets de mémoire pour un entier
int *a_pointer = malloc(sizeof(int));

```
La fonction `malloc` renvoie un pointeur vers la mémoire allouée, il faut donc un pointeur pour stocker cette adresse.
Il n'y a donc aucune variable statique qui pointe vers cette mémoire, il faut donc libérer la mémoire manuellement
lorsqu'on n'en a plus besoin.
```c

// Libérer la mémoire allouée
free(a_pointer);

```
Cela sera expliqué plus en détail dans le chapitre suivant.

### 2.4. Exercice 2
Écrivez une fonction qui prend en paramètre un entier `x` et qui renvoie un pointeur initialisé avec la valeur de `x`.
Pour cela, compléter la fonction `create_int` du fichier [`create_int.c`](src/create_int.c),
ainsi que la fonction `main` pour tester votre fonction.



# Conclusion
- Nous avons vu qu'est-ce qu'un pointeur.
- Comment l'utiliser pour modifier la valeur d'une variable.
- Quelques exemples d'utilisation des pointeurs.
- Et une mise en pratique avec deux exercices.


