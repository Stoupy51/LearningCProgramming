
# Headers et Includes
Dans ce cours, nous allons voir comment utiliser les fichiers headers et les includes en C.



## 1. Qu'est-ce qu'un fichier header ?
Un fichier header est un fichier qui contient des déclarations de fonctions, de variables, de constantes, de macros, de structures, etc.
<br>Un fichier header est défini par l'extension `.h` et est inclus dans un fichier source avec la directive `#include`.
<br>Les fichiers headers ne doivent contenir que des déclarations et non des définitions, c'est-à-dire que les fonctions, les variables, les constantes, les macros, les structures, etc. ne doivent pas être définies dans un fichier header mais dans un fichier source.

Exemple de fichier header :
```c

#ifndef HEADER_H
#define HEADER_H

// Déclaration de la fonction
void fonction();

#endif
```
Dans cet exemple, nous avons utilisé les directives (de macros) `#ifndef`, `#define` et `#endif` pour éviter les inclusions multiples du fichier header. Cela signifie que si le fichier header est inclus dans plusieurs fichiers sources, on s'assure qu'il ne sera inclus qu'une seule fois.
<br>On peut traduire ces directives par : si le fichier header n'a pas été inclus, on le définit jusqu'à `#endif` sinon, on ne fait rien.

L'utilisation de `HEADER_H` est arbitraire, on peut utiliser n'importe quel nom de macro, mais il est conseillé d'utiliser le nom du fichier header en majuscules, par exemple pour le fichier `functions.h`, on peut utiliser `__FUNCTIONS_H__` comme nom de macro, c'est ainsi plus facile de s'y retrouver.

Par conséquent, entre `#ifndef` et `#endif`, on peut mettre toutes les déclarations que l'on veut
(fonctions, variables, constantes, macros, structures, etc.).
<br>On peut aussi inclure d'autres fichiers headers mais cela n'est pas recommandé, il vaut mieux inclure les fichiers headers dans les fichiers sources qui en ont besoin car cela permet de mieux gérer les dépendances entre les fichiers sources et les fichiers headers.
<br>Cependant, il est possible qu'il soit nécessaire d'inclure un fichier header dans un autre fichier header, par exemple si on a besoin d'une structure définie dans un autre fichier header. C'est le seul cas où je vous autorise de le faire 😠


## 2. Déclaration et définition
Une déclaration permet d'indiquer au compilateur l'existence d'une fonction, d'une variable, d'une constante, d'une macro, d'une structure, etc. sans pour autant la définir.

<br>Une définition permet de définir une fonction, une variable, une constante, une macro, une structure, etc.
<br>Celles-ci peuvent être déclarées et définies dans un fichier source ou dans un fichier header.
<br>Il est généralement conseillé d'éviter les définitions dans les fichiers headers, mais il est possible de le faire.

Pour déclarer une fonction, on utilise la syntaxe suivante :
```c

// Déclaration d'une fonction quelconque
void fonction(int param1, int param2);

```
Afin de la définir, on crée un fichier source du même nom que le fichier header, mais avec l'extension `.c` et on écrit la définition de la fonction après avoir inclus le header, par exemple ici `header.c` :
```c

// Inclusion du fichier header
#include "header.h"

// Définition de la fonction
void fonction(int param1, int param2) {
	// Instructions à écrire ici
}

```


## 3. Les includes
Les includes permettent d'inclure un fichier header dans un fichier source.
Lors de la compilation, il faut imaginer que le compilateur va remplacer chaque directive `#include` par le contenu du fichier header.

Par ailleurs, il existe deux types d'inclusions :
- Les inclusions avec des guillemets : `#include "header.h"`
- Les inclusions avec des chevrons : `#include <header.h>`

Les inclusions avec des guillemets permettent d'inclure un fichier header qui se trouve dans le même répertoire que le fichier source.
<br>Les inclusions avec des chevrons permettent d'inclure un fichier header qui se trouve dans un répertoire spécifique, par exemple dans le répertoire `C:\MinGW\include` pour MinGW.
<br>Aujourd'hui, les deux types d'inclusions fonctionnent mais une convention veut maintenant que l'on utilise les inclusions avec des chevrons pour les fichiers headers de la bibliothèque standard et les inclusions avec des guillemets pour les fichiers headers de l'utilisateur.
<br>C'est pourquoi à partir de maintenant vous inclurez vos headers avec des guillemets " " et non avec des chevrons < > !


## 4. Définitions et Compilation séparée
Comme expliqué dans un chapitre précédent, la compilation séparée permet de compiler chaque fichier source séparément et de les lier ensemble pour former un exécutable.

Chaque fichier source n'a pas besoin de déclarations pour être compilé en fichier objet `.o`, seulement des définitions.
<br>En revanche, pour générer les exécutables, il faut que chaque l'ensemble des définitions et des déclarations soient présentes.
<br>C'est pourquoi il est nécessaire d'inclure les fichiers objets dans la compilation finale pour générer l'exécutable.

Par exemple, si on a deux fichiers sources `main.c` et `functions.c` et un fichier header `functions.h`, où `main.c` utilise des fonctions définies dans `functions.c`, on peut compiler chaque fichier source séparément en fichier objet `.o` :
```bash

gcc -c main.c -o main.o
gcc -c functions.c -o functions.o

# Génération de l'exécutable
gcc main.o functions.o -o main.exe

```


## 5. Arborescence du projet
Maintenant que vous savez comment utiliser les fichiers headers et les includes, j'ai décidé d'adapter l'arborescence du projet.
<br>Contrairement aux chapitres précédents, on peut maintenant faire la distinction entre
- un fichier source `.c` : dédié à la définition des fonctions
- un fichier programme `.c` : dédié à la fonction `main` et à la création de l'exécutable

Par conséquent, j'ai décidé de créer le répertoire `programs` qui contiendra tous les fichiers programmes `.c` et le répertoire `src` qui contiendra tous les fichiers sources `.c` et les fichiers headers `.h` comme avant.
<br>J'ai aussi adapté le Makefile pour bien différencier les fichiers sources `.c` et les fichiers programmes `.c`.

Cette nouvelle arborescence est moins populaire que l'arborescence précédente, mais elle est plus propre et plus facile à comprendre.
<br>Je vous conseille donc de l'utiliser pour vos projets personnels.

Petite précision, dans le Makefile, les fichiers programmes ne sont pas compilés en fichier objet `.o`
<br>car il n'y a pas besoin de les compiler en fichier objet pour générer l'exécutable, aucun fichier source ne les utilise.
<br>Cependant, il est possible de les compiler en fichier objet `.o` si vous le souhaitez,
<br>il suffit de modifier le Makefile en conséquence, bien que cela ne soit pas utile du tout.


## 6. Exercice
Maintenant que vous savez comment utiliser les fichiers headers et les includes, je vous propose de créer le fichier source `functions.c` pour définir les fonctions `power_function` et `swap_function` qui sont déclarées dans le fichier header [`functions.h`](src/functions.h).
<br>Indice : En C, l'opérateur `**` n'existe pas, d'où l'utilité d'une fonction pour calculer une puissance.
<br>Le fichier [`basic_header.c`](programs/basic_header.c) utilise ces deux fonctions, et mesure le temps d'exécution du programme.
<br>Le programme doit donc pouvoir être compilé et exécuté sans erreur, vous pouvez améliorer votre code si vous le souhaitez pour essayer de réduire le temps d'exécution du programme.



# Conclusion
Dans ce chapitre, vous avez appris les points suivants :
- La définition d'un fichier header
- La différence entre déclaration et définition
- L'utilisation des fichiers headers et des includes en C
- Un exercice pour mettre en pratique vos connaissances




