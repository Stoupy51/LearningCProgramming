
# Installation de l'environnement de développement sur Linux

1. Installez GCC et Make :
```bash
sudo apt install gcc make
```

2. Installez Visual Studio Code :
- Cette étape n'est pas obligatoire, mais je vous conseille d'utiliser un vrai
éditeur de texte pour écrire vos programmes plutôt que le bloc-notes.
- Téléchargez l'installeur de Visual Studio Code et installez-le.
- Une fois installé, je vous conseille les deux extensions suivantes :
  - C/C++ Extension Pack
  - TODO Tree
Elles vous permettront de bénéficier de la coloration syntaxique et de l'autocomplétion pour le C/C++.



# Installation de l'environnement de développement sur Windows

1. Installez le logiciel MSYS2 :
- Aller sur le site web de MSYS2 : https://www.msys2.org/
- Téléchargez l'installeur pour votre système (32-bit ou 64-bit).
- Exécutez le programme d'installation et suivez les instructions d'installation.
- Lorsque vous êtes invité à choisir le répertoire d'installation, vous pouvez conserver l'emplacement par défaut ou en choisir un autre. Je conseille de conserver le répertoire par défaut.
- Fermez le programme d'installation une fois l'installation terminée.



2. Mettre à jour les packages MSYS2 :
- Ouvrez l'application en recherchant le nom `MSYS2 MSYS`.
- Dans la fenêtre de terminal qui s'ouvre, tapez la commande suivante et appuyez sur Entrée :
(Cette commande peut prendre un certain temps).
```bash
pacman -Syu
```
- Cette commande met à jour la base de données des packages et met à niveau les packages installés.
Il est possible que vous devez appuyer sur `Y` pour confirmer la mise à jour des packages.



3. Installez GCC and Make :
- Dans la même fenêtre de terminal, tapez la commande suivante et appuyez sur Entrée :
```bash
pacman -S gcc make
```
- Cette commande installera le compilateur GCC et Make ainsi que leurs dépendances.
Suivez les instructions pour procéder à l'installation (genre appuyez sur `Y` pour confirmer)



4. Installez Visual Studio Code :
- Cette étape n'est pas obligatoire, mais je vous conseille d'utiliser un vrai
éditeur de texte pour écrire vos programmes plutôt que le bloc-notes.
- Téléchargez l'installeur de Visual Studio Code et installez-le.
- Une fois installé, je vous conseille les deux extensions suivantes :
  - C/C++ Extension Pack
  - TODO Tree
Elles vous permettront de bénéficier de la coloration syntaxique et de l'autocomplétion pour le C/C++.



5. Variables d'environnement
TODO






# Premier programme en C
# Makefile
# Printf en masse
# Allocation mémoire et pointeurs
# Input et gestion d'erreurs
# Création d'un fichier header
# Macros

# Variables globales
# linked list
# struct


