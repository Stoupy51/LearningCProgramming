
# TODO: Installation de l'environnement de développement

1. Install MSYS2:
- Go to the MSYS2 website: https://www.msys2.org/
- Download the installer appropriate for your system (32-bit or 64-bit).
- Run the installer and follow the installation instructions.
- When prompted to choose the installation directory, you can keep the default or choose a different location.
- Close the installer once the installation is complete.

2. Update MSYS2 packages:
- Open the "MSYS2 MinGW 64-bit" or "MSYS2 MinGW 32-bit" shortcut from the Start menu or the installation directory.
- In the terminal window that opens, type the following command and press Enter:
(This command can take a while to complete.)
```bash
pacman -Syu
```
- This command will update the package database and upgrade the installed packages. Follow the prompts if any updates or installations are required.

3. Install GCC and Make:
- In the same terminal window, type the following command and press Enter:
```bash
pacman -S mingw-w64-ucrt-x86_64-gcc make
```
- If you're using a 32-bit system, replace mingw-w64-x86_64-toolchain with mingw-w64-i686-toolchain.
- This command will install the GCC compiler and Make along with their dependencies. Follow the prompts to proceed with the installation.

4. Install VSCode:
# TODO Extensions

5. Variables d'environnement





## GCC
## Make

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


