
# Affichages
Étant donné que le cours précédent était basé sur les Makefile,
<br>chacun des chapitres suivants possèdera un Makefile déjà configuré.
<br>N'hésitez pas à l'utiliser donc !


# <u>Sommaire</u>
- [1. Affichage de base](#1-affichage-de-base)
  - [1.1 %d, %s, %c, %ld, %f](#11-d-s-c-ld-f)
  - [1.2 Exercice](#12-exercice)
  - [1.3 Problème d'affichage](#13-problème-d'affichage)
- [2. Différents flux d'information](#2-différents-flux-d'information)
- [Conclusion](#conclusion)

<br>

## 1. Affichage de base
Dans ce chapitre, nous allons voir comment afficher des informations dans le terminal.

Nous avons pu voir dans le premier chapitre que la fonction `printf` permet d'afficher des informations dans le terminal.
<br>Nous allons voir comment l'utiliser, et comment afficher des informations plus complexes.

<br>

### 1.1 %d, %s, %c, %ld, %f
La fonction `printf` a pour prototype de fonction :

```c
int printf(const char *format, ...);
```

Elle prend en premier argument une chaîne de caractères, et en deuxième argument, une liste d'arguments.
<br>La chaîne de caractères peut contenir des caractères spéciaux, qui seront remplacés par les arguments de la liste.

Par exemple, si on veut afficher un entier, on peut utiliser le caractère spécial `%d` :

```c
int a = 42;
printf("Mon entier vaut %d\n", a);
```

Le caractère spécial `%d` sera remplacé par la valeur de la variable `a` lors de l'exécution du programme.
<br>Le caractère spécial `\n` permet d'ajouter un retour à la ligne, c'est-à-dire que le texte suivant sera affiché à la ligne suivante.

Il existe plusieurs caractères spéciaux, qui permettent d'afficher différents types de données :
- `%d` : entier
- `%s` : chaîne de caractères
- `%c` : caractère
- `%ld` : entier long (type `long`)
- `%f` : flottant (nombre à virgule)
- `%.64f` : flottant avec 64 chiffres après la virgule (on peut remplacer 64 par un autre nombre)
<br>et bien d'autres..., vous pouvez les trouver facilement sur internet.

<br>

### 1.2 Exercice
Complétez le fichier [`main.c`](src/main.c), de façon à ce que le programme affiche :

```
Mon entier vaut 42
Mon caractère vaut 'u'
Ma chaîne de caractères vaut "Hello World!"
Mon entier long vaut 123456789
Mon flottant vaut 3.1415927410125732421875000000000000000000000000000000000000000000
Mon double vaut 3.1415926535897931159979634685441851615905761718750000000000000000
```

Compilez le programme avec la commande `make`, et exécutez-le avec
<br>la commande `./bin/main.exe` ou `.\bin\main.exe` (sous Windows).
<br>(Dossier `bin` créé automatiquement par le Makefile, contenant les exécutables)

<br>

### 1.3 Problème d'affichage
1. Si vous avez essayé de mettre les accents, vous avez sûrement remarqué que le programme n'affiche pas les caractères correctement.
<br>Cela est dû au fait qu'en C, les caractères sont codés sur un octet, c'est-à-dire qu'ils peuvent prendre 256 valeurs différentes.
<br>Or, il existe beaucoup plus de caractères que 256, et donc automatiquement, certains caractères comme les accents sont
<br>décomposés en plusieurs caractères, ex : `è` (int)(-15448) est décomposé en plusieurs caractères selon les encodages utilisés.
<br>Cela peut donc varier selon les systèmes d'exploitation, les encodages, etc.

Pour résoudre ce problème, on va pas le résoudre, car c'est un problème complexe, mais on va le contourner.
<br>On remplacera soi-même les caractères spéciaux, par exemple `è` par `e`, `é` par `e`, `î` par `i`, etc.
<br>Ou alors, vous codez en anglais, et vous n'avez pas ce problème 👍

2. Vous avez sûrement remarqué que le flottant et le double ne sont pas affichés de la même façon.
<br>C'est parce que le flottant est codé sur 32 bits, et le double sur 64 bits.
<br>Le `float` est moins précis que le `double`, mais il prend moins de place en mémoire.
<br>Vous utiliserez donc celui que vous voulez, selon vos besoins.

<br>

## 2. Différents flux d'information
Vous avez peut-être déjà entendu parler de `stdout`, `stderr` et `stdin`.
<br>Si ce n'est pas le cas, pas de panique, on va voir ce que c'est.
- `stdout` est le flux de sortie standard, c'est-à-dire que c'est là où sont affichées les informations avec `printf`.
- `stderr` est le flux d'erreur standard, c'est-à-dire que c'est là où sont affichées les erreurs.
- `stdin` est le flux d'entrée standard, c'est-à-dire que c'est là où sont lues les informations avec `scanf`.

La différence majeure entre `stdout` et `stderr`, c'est la sûreté d'affichage de l'information.
<br>En effet, `stdout` est un flux tamponné, c'est-à-dire que les informations sont stockées dans un tampon,
<br>et affichées quand le tampon est plein, ou quand on force l'affichage avec `fflush(stdout)`.
<br>`stderr` est un flux non tamponné, c'est-à-dire que les informations sont affichées directement.

La différence de performance entre les deux est importante, l'abus de `stderr` ralentira fortement votre programme.
<br>Il y a différentes façons d'afficher des informations dans `stderr` :
- `fprintf(stderr, "Mon entier vaut %d\n", a);` : l'utilisation est la même que `printf`, mais on précise le flux d'affichage en premier argument.
- `perror("Erreur");` : Cette fonction sera vue plus tard dans le chapitre sur les entrées/sorties et gestion d'erreurs, mais elle permet d'afficher une erreur dans `stderr` avec la signification du code `errno` (code d'erreur).

Enfin, `stdin` est un flux non tamponné, c'est-à-dire que les informations sont lues directement.
<br>Il est fortement déconseillé d'insérer des informations dans ce flux, ce n'est pas son but.
<br>On verra plus tard comment lire des informations de ce flux dans le même chapitre que `perror`.

<br>

# Conclusion
- Vous savez maintenant afficher des informations dans le terminal avec `printf`.
- Vous savez utiliser les caractères spéciaux pour afficher des informations plus complexes.
- Vous comprenez les différences entre `stdout`, `stderr` et `stdin`.

Vous pouvez changer le code du fichier [`main.c`](src/main.c) pour tester la fonction fprintf si vous voulez.
<br>Ou alors, vous pouvez passer au chapitre suivant, sur l'allocation mémoire et les pointeurs.


