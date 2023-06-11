
# Premier programme en C
Pour commencer, nous allons créer un programme qui affiche "Hello World" à l'écran, le fameux truc basique.
<br>Mais avec deux déclarations de la fonction `main` différentes.

La différence entre les deux est que la première est une fonction qui ne prend aucun argument,
<br>et la deuxième est une fonction qui prend deux arguments.

## <u>Sommaire</u>
- [Premier hello world](#1-premier-hello-world)
  - [1.1 Compilation du programme](#11-compilation-du-programme)
  - [1.2 Comment ça il veut pas compiler ?](#12-comment-ça-il-veut-pas-compiler-)
  - [1.3 Exécution du programme](#13-exécution-du-programme)
- [Deuxième hello world](#2-deuxième-hello-world)
- [Conclusion](#conclusion)



## 1. Premier hello world
Nous allons utiliser la fonction `printf` pour afficher "Hello World" à l'écran.
<br>Le fichier [`hello_world_1.c`](hello_world_1.c) contient le code source pour ce programme.

<br>

### 1.1 Compilation du programme
Afin de l'exécuter, il faut compiler le programme à l'aide de la commande `gcc`
<br>Pour cela, ouvrez un terminal et placez-vous dans le dossier où se trouve le fichier `hello_world_1.c`.
<br>Une fois qu'on a placé le terminal dans le bon dossier, la syntaxe est la suivante :

```bash
gcc -o "hello_world_1.exe" "hello_world_1.c" -Werror
```

Dans cette commande, les guillemets sont facultatifs, voici ce que signifie chaque partie :
- `gcc` est le compilateur : c'est la commande qui permet de compiler un programme écrit en C,

- `-o` est l'option qui permet de spécifier le nom du fichier exécutable, ici `hello_world_1.exe`.
Le `.exe` est facultatif, mais je conseille de le mettre pour savoir que c'est un exécutable.
Certaines personnes mettent `.o` à la place, mais c'est une mauvaise pratique car les fichiers `.o`
sont des fichiers objets, et non des exécutables.
D'autres personnes ne mettent juste rien, mais c'est pas très pratique pour savoir que c'est un exécutable ou pas ;-;

- `hello_world_1.c` est le nom du fichier source, il peut y avoir plusieurs fichiers sources dans cette partie,
séparés par des espaces. Ce qui n'est pas le cas ici puisqu'il n'y a qu'un seul fichier source.

- `-Werror` est l'option qui permet de transformer les warnings en erreurs, histoire que votre programme ne compile pas si vous avez des warnings.

<br>

### 1.2 Comment ça il veut pas compiler ?
Lors du lancement de la commande de compilation, le compilateur nous gueule dessus, comprenons ensemble pourquoi.

Premièrement, il nous dit 3 choses, mais cela ne veut pas dire qu'il y a 3 erreurs.
<br>Lisons la première erreur :

```bash
hello_world_1.c: In function 'main':
hello_world_1.c:11:9: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
   11 |         printf("Hello World!\n");
      |         ^~~~~~
```
Il nous dit qu'une fonction n'est pas déclarée, et qu'on l'utilise quand même.
<br>En effet, la fonction `printf` n'est pas déclarée, car elle est définie dans le fichier d'en-tête `stdio.h`.

Il faut donc inclure ce fichier d'en-tête dans notre programme, et oh ça tombe bien,
<br>le compilateur nous donne la ligne où il faut l'inclure.

```bash
hello_world_1.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 |
```
Il nous dit d'ajouter en début de fichier la ligne `#include <stdio.h>`.

La deuxième erreur est la suivante :
```bash

hello_world_1.c:11:9: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
   11 |         printf("Hello World!\n");
      |         ^~~~~~
hello_world_1.c:11:9: note: include '<stdio.h>' or provide a declaration of 'printf'
```
Il nous signale que la déclaration implicite de la fonction `printf` est incompatible avec la déclaration implicite
<br>de la fonction `printf` qu'il a lui-même définie, et qu'il faut inclure le fichier d'en-tête `stdio.h`.
<br>On peut donc ignorer cette erreur, car elle est liée à la première.

Une fois qu'on a ajouté la ligne `#include <stdio.h>` en début de fichier,
<br>on peut relancer la commande de compilation et aucun message d'erreur ne s'affiche !
<br>Mission réussie !

<br>

### 1.3 Exécution du programme
Une fois que le programme est compilé, il suffit de l'exécuter en tapant dans le terminal :

```bash
# Sous système UNIX ou Windows 11 :
./hello_world_1.exe

# Sous Windows 10 (cmd) :
.\hello_world_1.exe
```
Utile à savoir : l'autocomplétion du nom du fichier fonctionne dans le terminal,
<br>il suffit de taper les premières lettres sans mettre `./` ou `.\` et d'appuyer sur la touche `TAB`.
<br>c'est-à-dire taper `he` puis `TAB` pour appuyer sur `ENTER` fonctionne pour exécuter le programme.

<br>

## 2. Deuxième hello world
La deuxième façon de déclarer la fonction `main` est de lui donner deux arguments.
<br>Ceux-ci sont les suivants :
- `int argc` : le nombre d'arguments passés au programme lors de son exécution,
- `char *argv[]` : un tableau de chaînes de caractères contenant les arguments passés au programme lors de son exécution.

Par exemple, si on exécute le programme avec la commande `./hello_world_2.exe arg1 arg2`,
<br>alors `argc` vaudra `3` et `argv` sera un tableau de 4 chaînes de caractères :
- `argv[0]` sera la chaîne de caractère `./hello_world_2.exe`,
- `argv[1]` vaudra `arg1`,
- `argv[2]` vaudra `arg2`.

Le fichier [`hello_world_2.c`](hello_world_2.c) contient le code source pour ce programme.
<br>Le code est le même que pour le premier programme, sauf que la fonction `main` est déclarée différemment.
<br>L'include du fichier d'en-tête `stdio.h` est cette fois-ci déjà présent en début de fichier.

Essayez de modifier la commande de compilation pour compiler le deuxième programme.

<br>

# Conclusion
- Nous avons vu comment créer un programme en C qui affiche "Hello World" à l'écran.
- Nous avons vu deux façons de déclarer la fonction `main` :
une qui ne prend aucun argument, et une qui en prend deux.
- Nous avons vu comment compiler un programme en C à l'aide de la commande `gcc`.
- Nous avons vu comment comprendre les messages d'erreur du compilateur.
- Nous avons vu comment exécuter un programme en C.

Pour aller plus loin, vous pouvez essayer de modifier le programme pour qu'il affiche "Hello World" deux fois à l'écran.
<br>Ou bien continuer avec le chapitre suivant.

