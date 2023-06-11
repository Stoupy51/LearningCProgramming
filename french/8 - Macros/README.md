
# Macros
Dans ce chapitre, nous allons voir comment définir des macros en C, à quoi elles servent, leurs différents types et comment les utiliser.


# <u>Sommaire</u>
- [1. Définition](#1-définition)
- [2. Macros de couleur](#2-macros-de-couleur)
- [3. Fonctions macros](#3-fonctions-macros)
  - [3.1. Fonctions macros simples](#31-fonctions-macros-simples)
  - [3.2 Exercice 1](#32-exercice-1)
- [4. Macros conditionnelles](#4-macros-conditionnelles)
  - [4.1. Macros conditionnelles simples](#41-macros-conditionnelles-simples)
  - [4.2. Fonctions macros sur plusieurs lignes](#42-fonctions-macros-sur-plusieurs-lignes)
  - [4.3. Exercice 2](#43-exercice-2)
- [5. Fichier Utils.h cadeau](#5-fichier-utilsh-cadeau)
- [Conclusion](#conclusion)

<br>

## 1. Définition
Qu'est-ce qu'une macro ? Une macro est un texte ou une instruction qui est remplacée par son contenu lors de la compilation.
<br>Pour l'instant, vous ne connaissez que les macros des fichiers d'en-tête (headers) comme `#define __HEADER_H__`.
<br>Mais il existe d'autres types de macros, que nous allons voir dans ce chapitre.

Il existe des instructions pour vérifier la présence ou l'absence de macros, pour définir des macros,
<br>pour les remplacer par leur contenu, etc. Voici un aperçu des instructions les plus courantes :

- `#ifdef` : Si la macro est définie, alors le code entre `#ifdef` et `#endif` sera compilé.
- `#ifndef` : Si la macro n'est pas définie, alors le code entre `#ifndef` et `#endif` sera compilé.
- `#define` : Définit une macro.
- `#undef` : Supprime la définition d'une macro (Très rarement utilisé car dangereux).
- `#if` : Si la condition est vraie, alors le code entre `#if` et `#endif` sera compilé.
- `#elif` : Sinon si la condition est vraie, alors le code entre `#elif` et `#endif` sera compilé.
- `#else` : Sinon, le code entre `#else` et `#endif` sera compilé.
- `#endif` : Fin de la condition.
- `#error` : Affiche un message d'erreur à la compilation.
- `#warning` : Affiche un message d'avertissement à la compilation.

Il existe d'autres instructions, mais je ne les présenterai pas ici car elles sont très peu utilisées.

Les macros sont très utiles pour rendre le code plus lisible, possiblement plus rapide à écrire et plus facile à maintenir.
<br>Elles permettent également de rendre le code plus portable, c'est-à-dire qu'il pourra être compilé
<br>sur différents systèmes d'exploitation sans avoir à modifier le code source si les macros sont bien utilisées.

Lorsqu'on utilisera des fonctionnalités spécifiques à un système d'exploitation,
<br>je vous expliquerai comment les rendre portables à l'aide de macros.
<br>Toutefois, cela a été fait dans fichier [`prints.c`](programs/prints.c) de ce chapitre, pour l'usage de la fonction `sleep()`.

<br>

## 2. Macros de couleur
Première chose à savoir avant d'entamer cette partie, le compilateur remplace
<br>les chaînes de caractères qui se suivent directement par une seule chaîne de caractères,
<br>ex : "Bonjour" " " "tout" " " "le" " " "monde" sera remplacé par "Bonjour tout le monde".

Maintenant que vous savez ça, nous allons voir comment colorer le texte affiché dans la console !
<br>Très utile pour afficher des messages d'erreur en rouge, des messages d'avertissement en jaune, etc.
<br>En bref, ça permet de rendre le texte plus lisible !

Pour cela, nous allons utiliser des macros. Voici les macros que nous allons utiliser :
```c

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

```
Ces macros définissent ce qu'on appelle des ANSI escape codes, qui permettent de modifier la couleur du texte affiché dans la console.
<br>Ils sont supportés par la plupart des consoles, mais pas toutes.

Tous les systèmes UNIX les supportent par défaut, mais Windows ne les supporte qu'à partir de Windows 11.
<br>Cependant, il existe une astuce pour les utiliser sur Windows 10, elle consiste à lancer une commande PowerShell vide lors du lancement du programme.
<br>Pour une raison encore inconnue, cela permet de les utiliser. En tout cas, ça fonctionne sur mon Windows 10.

Voici un exemple d'utilisation de ces macros pour afficher un message d'erreur en rouge :
```c

// Affiche "[ERROR] " en rouge, puis "Impossible d'ouvrir le fichier." en blanc.
fprintf(stderr, RED "[ERROR] " RESET "Impossible d'ouvrir le fichier.\n");

// Le compilateur remplace les macros par leur contenu, donc le code ci-dessus est équivalent à :
fprintf(stderr, "\033[0;31m[ERROR] \033[0mImpossible d'ouvrir le fichier.\n");
// Vraiment pas pratique à écrire, n'est-ce pas ?

```
Si vous oubliez de mettre `RESET` après une macro de couleur, tout le texte affiché après sera de la même couleur que la macro,
<br>même après avoir quitté le programme ! Faites donc attention.

<br>

## 3. Fonctions macros
### 3.1. Fonctions macros simples
Il existe un autre type de macros, les fonctions macros.
<br>Elles sont très utiles pour simplifier des tâches qui prennent beaucoup de temps à écrire,
<br>comme par exemple afficher un message d'erreur dans la console.

On peut alors définir une fonction macro qui prend en paramètre un message d'erreur
<br>et qui affiche ce message d'erreur en rouge dans la console :

```c

#define ERROR_PRINT(message) fprintf(stderr, RED "[ERROR] " RESET message)

// Affiche "[ERROR] Impossible d'ouvrir le fichier." avec [ERROR] en rouge.
ERROR_PRINT("Impossible d'ouvrir le fichier.\n");

```
On voit ici que la fonction macro `ERROR_PRINT` prend en paramètre un message d'erreur et l'affiche en rouge dans la console.
<br>Cela signifie que des macros peuvent utiliser d'autres macros, comme par exemple `ERROR_PRINT` qui utilise `RED` et `RESET`.
<br>On peut donc imaginer une fonction macro pour chaque type de message (WARNING, INFO, DEBUG, etc.).

Cependant, comment faire si on veut afficher un message d'erreur avec un paramètre,
<br>comme par exemple le nom du fichier qui n'a pas pu être ouvert ?
<br>L'utilisation de `printf` semble impossible car il faut pouvoir passer une infinité de paramètres à la fonction macro.

Heureusement, il existe une solution, les macros à nombre variable d'arguments !
<br>L'instruction `__VA_ARGS__` permet de récupérer tous les paramètres non nommés qui sont passés à la fonction macro :

```c

#define ERROR_PRINT(...) fprintf(stderr, RED "[ERROR] " RESET __VA_ARGS__)

// Affiche "[ERROR] Impossible d'ouvrir le fichier 'fichier.txt'." avec [ERROR] en rouge.
ERROR_PRINT("Impossible d'ouvrir le fichier '%s'.\n", "fichier.txt");

```
Ceci est vraiment ultra pratique.

<br>

### 3.2 Exercice 1
Maintenant que vous savez comment utiliser les macros, je vous propose un exercice pour vous entraîner.

Vous allez écrire un fichier header `utils.h` qui contiendra des fonctions macros pour afficher avec des couleurs :
- des messages d'erreur
- d'avertissement
- d'information
- et de débogage (debug)

Voici les macros que vous devez définir :
```c

RED
GREEN
YELLOW
BLUE
MAGENTA
CYAN
RESET

// Couleurs proposées : INFO = green, DEBUG = cyan, WARNING = yellow, ERROR = red

INFO_PRINT(...)
DEBUG_PRINT(...)
WARNING_PRINT(...)
ERROR_PRINT(...)

```
Veillez à ce que le programme [`prints.c`](programs/prints.c) compile et s'exécute correctement !

<br>

## 4. Macros conditionnelles
### 4.1. Macros conditionnelles simples
En C, vous pouvez définir des macros que vous pouvez utiliser conditionnellement dans votre code.
<br>Par exemple, vous pouvez définir une macro si vous êtes en mode debug,
<br>puis ainsi afficher des messages de débogage uniquement en mode debug.

Pour cela, il existe plusieurs instructions comme `#ifdef`, `#ifndef`, `#if`, `#elif`, `#else` et `#endif`.
<br>Voici un exemple d'utilisation de ces instructions :

```c

// Si la macro DEBUG est définie, alors on affiche un message de débogage.
// Sinon, on affiche un message d'erreur.
#ifdef DEBUG
	DEBUG_PRINT("Message de débogage.\n");
#else
	ERROR_PRINT("Message d'erreur.\n");
#endif

// Alternativement, utilisation de macros pour le niveau d'information.
#define INFO_LEVEL 1
#define DEBUG_LEVEL 2
#define WARNING_LEVEL 4
#define ERROR_LEVEL 8
// Il suffit de changer la valeur de DEBUG_STATES pour changer le niveau d'information :
#define DEBUG_STATES (INFO_LEVEL | DEBUG_LEVEL | WARNING_LEVEL | ERROR_LEVEL)
// Ici, DEBUG_STATES vaut 15, car 1 | 2 | 4 | 8 = 15. (En binaire : 0001 | 0010 | 0100 | 1000 = 1111)

// Les macros suivantes permettent de savoir si le niveau d'info nécessaire est présent.
#define IS_INFO_LEVEL (DEBUG_STATES & INFO_LEVEL)
#define IS_DEBUG_LEVEL (DEBUG_STATES & DEBUG_LEVEL)
#define IS_WARNING_LEVEL (DEBUG_STATES & WARNING_LEVEL)
#define IS_ERROR_LEVEL (DEBUG_STATES & ERROR_LEVEL)

// Ainsi, on peut afficher un message d'information uniquement si le niveau d'information est présent.
#if IS_INFO_LEVEL
	#define INFO_PRINT(...) { printf(GREEN "[INFO] " RESET __VA_ARGS__); }
#else
	#define INFO_PRINT(...) {}
#endif

```
Vous pouvez aussi utiliser `#elif` pour faire des conditions plus complexes :
```c

// Si la macro DEBUG est définie, alors on affiche un message de débogage.
// Sinon, si la macro INFO est définie, alors on affiche un message d'information.
// Sinon, on affiche un message d'erreur.
#ifdef DEBUG
	DEBUG_PRINT("Message de débogage.\n");
#elif IS_INFO_LEVEL
	INFO_PRINT("Message d'information.\n");
#else
	ERROR_PRINT("Message d'erreur.\n");
#endif

```

<br>

### 4.2. Fonctions macros sur plusieurs lignes
Il est possible de définir des fonctions macros sur plusieurs lignes en utilisant le caractère `\` à la fin de chaque ligne :
```c

#define ERROR_PRINT(...) { \
	fprintf(stderr, RED "[ERROR] " RESET __VA_ARGS__); \
}

```

<br>

### 4.3. Exercice 2
Je vous propose un exercice à nouveau utile, vous allez compléter le fichier header `utils.h`
<br>pour ajouter des macros utiles au contrôle d'erreurs de vos programmes.

C'est-à-dire par exemple une macro qui prend en paramètre un code de retour et un message d'erreur,
<br>cette macro affiche le message d'erreur si le code de retour est inférieur à 0 et retourne le code de retour.

Voici les différentes macros que vous devez définir :
```c

// Affiche un message d'erreur si le code de retour est inférieur à 0 et retourne le code de retour.
ERROR_HANDLE_INT_RETURN_INT(code, ...)

// Affiche un message d'erreur si le code de retour est inférieur à 0 et retourne NULL.
ERROR_HANDLE_INT_RETURN_NULL(code, ...)

// Affiche un message d'erreur si le pointeur est NULL et retourne le code de retour.
ERROR_HANDLE_PTR_RETURN_INT(ptr, ...)

// Affiche un message d'erreur si le pointeur est NULL et retourne NULL.
ERROR_HANDLE_PTR_RETURN_NULL(ptr, ...)

```

<br>

## 5. Fichier Utils.h cadeau
Si vous avez réussi les exercices précédents, vous pouvez utiliser les fichiers utils.h et utils.c
<br>fournis dans le dossier [`cadeau`](cadeau/universal_utils.h).

Ils contiennent des macros et fonctions utiles pour le contrôle d'erreurs, l'affichage de messages, le setup d'un programme, etc.
<br>Vous pouvez les utiliser dans vos projets mais dans tous les cas, ils seront utilisés dans les prochains chapitres.

<br>

# Conclusion
En résumé, dans ce chapitre, vous avez appris :
- Qu'est-ce qu'une macro, à quoi ça sert et comment en définir une.
- L'existence des ANSI Escape Codes et comment les utiliser pour afficher des couleurs dans le terminal.
- Comment utiliser les macros à nombre variable d'arguments.
- Comment utiliser les macros conditionnelles.
- Comment définir des fonctions macros sur plusieurs lignes.

Direction prochain chapitre : les structures de données en C !


