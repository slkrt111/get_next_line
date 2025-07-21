# 📜 get_next_line

**get_next_line** est un projet de l'école 42 qui consiste à écrire une fonction permettant de lire un fichier ligne par ligne.  
L’objectif est de comprendre la gestion des buffers, la lecture en continu depuis un descripteur de fichier, et la manipulation efficace de chaînes de caractères.

---

## 📑 Sommaire
- [📘 Description](#-description)
- [⚙️ Fonctionnalités](#-fonctionnalités)
- [📂 Structure du projet](#-structure-du-projet)
- [💻 Compilation et Utilisation](#-compilation-et-utilisation)
- [📋 Prototype et Comportement](#-prototype-et-comportement)
- [🔗 Ressources](#-ressources)

---

## 📘 Description

Le projet **get_next_line** consiste à écrire une fonction :  
```c
char *get_next_line(int fd);
qui retourne une ligne lue depuis un descripteur de fichier fd, incluant le caractère \n (s'il existe), et NULL si la fin du fichier est atteinte ou en cas d'erreur.

⚙️ Fonctionnalités
🔧 Lecture ligne par ligne depuis un fichier ou stdin

🧵 Gestion d’un buffer configurable via la macro BUFFER_SIZE

📜 Support des appels multiples sur le même descripteur de fichier

📚 Support de plusieurs descripteurs de fichiers ouverts simultanément (bonus)

📂 Structure du projet
Le projet est généralement composé des fichiers suivants :

get_next_line.c – Contient l’implémentation principale de get_next_line.

get_next_line_utils.c – Fonctions utilitaires (ex. ft_strlen, ft_strjoin, etc.).

get_next_line.h – Fichier d’en-tête avec le prototype de la fonction et les includes nécessaires.

💻 Compilation et Utilisation
Pour compiler le projet, vous pouvez utiliser :

bash
Copier
Modifier
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
Exemple d’utilisation dans un fichier main.c :

c
Copier
Modifier
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("fichier.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
📋 Prototype et Comportement
Prototype
c
Copier
Modifier
char *get_next_line(int fd);
Comportement attendu
Retourne la ligne suivante lue depuis le descripteur fd à chaque appel.

Retourne NULL quand la fin du fichier est atteinte ou en cas d’erreur.

Gère un buffer de taille BUFFER_SIZE pour lire efficacement.

🔗 Ressources
📘 read() — Manuel POSIX

📚 Gestion des fichiers en C

📜 Documentation officielle de l'école 42

📖 Stack Overflow — Gestion de buffers en C
