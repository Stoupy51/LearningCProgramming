
# Makefile

## Qu'est-ce qu'un Makefile ?
Un Makefile est un fichier qui contient des instructions pour compiler un programme.
Ces instructions sont des commandes shell / bash, qui sont exécutées par le programme `make` dans le terminal.
Cela permet d'éviter de taper la commande de compilation à chaque fois qu'on veut compiler le programme,
et de pouvoir compiler plusieurs programmes différents en une seule commande.

## Comment ça marche ?
Le fichier Makefile contient ce qu'on appelle des `règles`, qui sont de la forme suivante :
```makefile

nom_de_la_règle: dépendance_1 dépendance_2
	commande_1
	commande_2

```
Une règle est composée de 3 parties :

- le nom de la règle : c'est le nom qu'on va utiliser pour appeler la règle.
Il doit être unique, et ne doit pas contenir de caractères spéciaux,

- les dépendances : ce sont les règles qui doivent être exécutées avant d'exécuter la règle courante.
Elles sont optionnelles, et doivent être des noms de règles valides dans le fichier Makefile.

- les commandes : ce sont les commandes shell / bash qui seront exécutées par le programme `make`.
Elles sont optionnelles, et doivent être des commandes valides dans le terminal, par exemple `gcc ...`,
elles peuvent être sur plusieurs lignes, mais doivent être précédées d'une tabulation.

## Raccourcis
Il existe des raccourcis pour les règles les plus utilisées, par exemple la règle `all` est exécutée par défaut,
et exécute toutes les règles qui lui sont dépendantes.

Il existe des variables prédéfinies, qui permettent de simplifier l'écriture du Makefile :
- `$@` : nom de la règle courante
- `$^` : liste des dépendances
- `$<` : nom de la première dépendance (Vraiment utile ?)

## Exemple
```makefile

all: main.exe

main.exe: main.c
	gcc -o $@ $^
	# équivalent à `gcc -o main.exe main.o`

```
Dans cet exemple, on a une règle `all` qui dépend de la règle `main.exe`, qui dépend elle-même du fichier `main.c`.
La règle `all` est exécutée par défaut, et exécute la règle `main.exe`, qui compile le fichier `main.c` en un exécutable `main.exe`.
Il est possible d'exécuter seulement une règle en particulier, par exemple la commande
`make main.exe` exécute uniquement la règle `main.exe`.

## Exercice
Ajustez le Makefile présent dans ce dossier pour qu'il compile les deux programmes `main1.c` et `main2.c`
en deux exécutables `main1.exe` et `main2.exe`.
Ces deux programmes n'affichent rien à l'exécution car ce n'est pas le but de l'exercice.
Votre makefile doit donc compiler les deux programmes sans erreur, et sans afficher de warning.

Deux solutions sont proposées dans les fichiers `makefile.solution_X`, mais il en existe beaucoup d'autres.
Regardez les solutions uniquement si vous êtes bloqués ou après avoir essayé.

# Additions
## Règles supplémentaires
Une règle souvent utilisée est la règle `clean`, qui permet de supprimer les fichiers générés par la compilation.
Dans notre cas, on peut supprimer les fichiers `main1.exe` et `main2.exe` avec la règle suivante :

```makefile

# Suppression de tous les fichiers .exe du dossier courant
clean:
	rm *.exe
	rm *.o

```
On supprime aussi les fichiers `.o` qui sont générés par la compilation
dans le cas où on utilise des fichiers `.c` séparés.

Une règle aussi pratique est la règle `restart`, qui permet de lancer la règle `clean` puis la règle `all` :

```makefile

restart: clean all

```

## Variables
Il est possible de définir des variables dans le Makefile, qui peuvent être utilisées dans les règles.
Cela permet de ne pas avoir à répéter plusieurs fois la même chose, par exemple :
- le nom du compilateur
- les options de compilation (flags)

```makefile

# Définition des variables
CC = gcc
COMPILER_FLAGS = -Wall -Wextra -Wpedantic -Werror -O3

# Règles
all: main1.exe main2.exe

main1.exe: main1.c
	$(CC) $(COMPILER_FLAGS) -o $@ $^

main2.exe: main2.c
	$(CC) $(COMPILER_FLAGS) -o $@ $^

clean:
	rm *.exe
	rm *.o

restart: clean all

```
Les flags de compilation sont des options utiles que je conseille fortement d'utiliser, même je vous ordonne !
- `-Wall` : affiche tous les warnings
- `-Wextra` : affiche des warnings supplémentaires
- `-Wpedantic` : affiche des warnings supplémentaires
- `-Werror` : transforme les warnings en erreurs
- `-O3` : optimise le code assemblé (niveau 3)
On ne rentrera pas dans les détails de ces options, vous pouvez les chercher sur internet si vous voulez en savoir plus.

## Makefile bien organisé et générique
### Compilation en fichiers objets
Parlons maintenant de la compilation de plusieurs fichiers `.c` séparés.
Le compilateur `gcc` supporte l'option `-c` qui permet de compiler un fichier source `.c` en un fichier objet `.o` distinctement.
Cela permet de ne pas avoir à recompiler tous les fichiers `.c` à chaque fois qu'on en modifie un seul.
Ainsi, le compilateur ne recompile que les fichiers `.c` qui ont été modifiés depuis la dernière compilation.
Le fichier objet `.o` contient le code compilé en langage machine, il n'est pas exécutable.
Pour le rendre exécutable, il faut compiler les fichiers `.o` ensemble en un exécutable.

Exemple :
```makefile

# Génération du fichier objet main1.o
main1.o: main1.c
	gcc -o $@ -c $^

# Génération de l'exécutable main1.exe à partir du fichier objet main1.o
main1.exe: main1.o
	gcc -o $@ $^

```

### Makefile à votre disposition
Pour mieux organiser son environnement de travail, on peut créer un dossier `src` qui contient tous les fichiers `.c` et `.h`,
un dossier `obj` qui contient tous les fichiers `.o` générés par la compilation, et un dossier `bin` qui contient tous les exécutables.
On crée des variables pour ces dossiers afin d'obtenir ce magnifique Makefile,
le dossier `project_example` contient un exemple de projet organisé de cette manière.

Dans celui-ci, les fichiers sources sont premièrement compilés en fichiers objets, puis les fichiers objets sont liés entre eux pour créer les exécutables. Même si pour notre exemple cela n'est pas utile, cela le sera forcément pour des projets plus complexes.

Plus tard dans les chapitres, je vous présenterai un makefile 100% automatique
qui n'a pas besoin d'être modifié pour fonctionner avec n'importe quel projet.



# Conclusion
- Nous avons vu comment qu'est-ce qu'un Makefile et à quoi il sert
- Nous avons vu comment écrire un Makefile basique
- Nous avons vu comment écrire un Makefile plus avancé (variables, règles supplémentaires, raccourcis)
- Nous avons vu comment compiler un fichier source `.c` séparés en fichier objet `.o` puis en un exécutable
- Nous avons vu (briévement) comment organiser son environnement de travail




