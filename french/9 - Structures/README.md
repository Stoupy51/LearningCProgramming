
# Structures
Aujourd'hui, nous allons voir les structures en C, à quoi elles servent, comment les utiliser, et quelles sont leurs spécificités mémoire.


# <u>Sommaire</u>
- TODO


## 1. Qu'est-ce qu'une structure ?
Une structure est un type de données qui permet de regrouper plusieurs variables de différents types sous un même nom.
<br>Une structure est déclarée à l'aide du mot-clé `struct` suivi du nom de la structure et des variables qui la composent.
<br>Exemple de structure permettant de stocker les coordonnées d'un point dans un espace à 3 dimensions :

```c

struct point_3d_t {
	int x;
	int y;
	int z;
};

```
Ici, on a déclaré une structure `point_3d_t` qui contient 3 variables de type `int` : `x`, `y` et `z`.

Par convention, les noms de structures sont suffixés par `_t` (comme `point_3d_t`), mais ce n'est pas obligatoire.
<br>Cependant, je le recommande fortement, car cela permet de les différencier des autres variables.

Une fois la structure déclarée, on peut l'utiliser comme n'importe quel autre type de données.
<br>Exemple :

```c

struct point_3d_t point;
struct point_3d_t *point_ptr;

```
Ici, on a déclaré une variable `point` de type `struct point_3d_t` et un pointeur `point_ptr` de type `struct point_3d_t *`.

<br>

## 2. Utilisation des structures
On peut ensuite accéder aux variables de la structure en utilisant l'opérateur `.` (point).
<br>Exemple :

```c

// Affection de valeurs aux variables de la structure
point.x = 10;
point.y = 20;
point.z = 30;

```
Les variables `point.x`, `point.y` et `point.z` sont maintenant égales à 10, 20 et 30 respectivement,
<br>et on peut les utiliser comme n'importe quelle autre entier.

On peut aussi utiliser l'opérateur `->` (pointeur) pour accéder aux variables d'une structure via un pointeur.
<br>Exemple :

```c

struct point_3d_t *point_ptr = &point;

// Affection de valeurs aux variables de la structure
point_ptr->x = 10;
point_ptr->y = 20;
point_ptr->z = 30;

```
C'est exactement la même chose que l'exemple précédent, sauf qu'on utilise un pointeur au lieu d'une variable.

Il est possible de déclarer une structure sans lui donner de nom, c'est ce qu'on appelle une structure anonyme.
<br>Exemple :

```c

struct {
	int x;
	int y;
	int z;
};

```
Elle ne peut pas être utilisée directement, mais on peut l'utiliser pour déclarer des variables :
<br>Exemple :

```c

struct {
	int x;
	int y;
	int z;
} point;

```
Ici, on a déclaré une variable `point` de type `struct { int x; int y; int z; }`.
<br>L'avantage de cette méthode est qu'on peut déclarer une structure à la volée, sans avoir à la déclarer au préalable.
<br>Le gros inconvénient est qu'on ne peut pas déclarer de pointeurs vers une structure anonyme, je vous conseille donc de ne pas l'utiliser.

Il est aussi possible de déclarer une structure à l'intérieur d'une autre structure.
<br>Exemple :

```c

struct triangle_t {
	struct point_3d_t a;
	struct point_3d_t b;
	struct point_3d_t c;
};

```
Ici, on a déclaré une structure `triangle_t` qui contient 3 variables de type `struct point_3d_t` : `a`, `b` et `c`.

On peut ensuite accéder aux variables de la structure `triangle_t` en utilisant l'opérateur `.` (point) :

```c

struct triangle_t triangle;

triangle.a.x = 10;
triangle.a.y = 20;
triangle.a.z = 30;

triangle.b = triangle.a;
triangle.c = triangle.a;

```


## 3. Spécificités mémoire
Les structures sont stockées en mémoire de manière contiguë, c'est-à-dire que les variables qui la composent sont stockées les unes à la suite des autres.

Cela signifie que la taille d'une structure est égale à la somme des tailles de ses variables, ou non ?
<br>Et bien non, si je vous montre la structure suivante :

```c

struct how_many_bytes_t {
	char a;
	int b;
	char c;
};

```
Vous allez me dire que la taille de cette structure est égale à 1 + 4 + 1 = 6 octets, mais vous vous trompez.
<br>La taille de cette structure est en réalité égale à 12 octets.

Pourquoi ? Et bien c'est parce que les processeurs lisent les données en mémoire par blocs.
<br>Ainsi, un entier (int) ne peut être lu que si son adresse est un multiple de 4, un long ne peut être lu que si son adresse est un multiple de 8, etc.
<br>C'est ce qu'on appelle l'alignement mémoire, c'est utile pour optimiser les performances, mais ça peut aussi être un problème.

Afin de respecter l'alignement mémoire, le compilateur va ajouter des octets de padding
<br>à la fin de la structure donnant un résultat final de 12 octets :

```c

struct how_many_bytes_t {

	// 4 octets
	char a;
	char padding_1[3];

	// 4 octets
	int b;

	// 4 octets
	char c;
	char padding_2[3];
};

```
On peut voir que le compilateur a ajouté 3 octets de padding après la variable `a` et 3 autres octets de padding après la variable `c`.

Pour éviter ce problème, vous devez donc déclarer vos variables dans l'ordre décroissant de leur taille au mieux.
<br>Cependant, ne vous prenez pas trop la tête avec cela si vous n'avez pas besoin d'optimiser les performances de votre programme.

<br>

## 4. Typedef
Il peut être redondant de devoir écrire `struct` à chaque fois qu'on veut utiliser une structure.
<br>Heureusement, il existe une solution à ce problème : le mot-clé `typedef`.

`typedef` permet de définir un alias pour un type de données.
<br>Par exemple, vous pouvez définir un alias `point_3d_t` pour `struct point_3d_t`, il suffit de déclarer la structure comme ceci :

```c

typedef struct point_3d_t {
	int x;
	int y;
	int z;
} point_3d_t;

```
Ainsi, vous pouvez utiliser `point_3d_t` au lieu de `struct point_3d_t`
<br>(et `point_3d_t *` au lieu de `struct point_3d_t *` pour les pointeurs).

<br>

## 5. Exercice 1
# TODO





