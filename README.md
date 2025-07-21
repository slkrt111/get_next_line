# 📜 get_next_line

## 📖 Description
**get_next_line (GNL)** est un projet de l'école 42 qui consiste à écrire une fonction capable de **lire une ligne entière depuis un descripteur de fichier (fd)**, même si la ligne est partiellement lue.  
L’objectif est d’apprendre à gérer les **buffers**, la **lecture partielle**, et la **gestion mémoire** dans un contexte de flux de données.

---

## 🧩 Fonctionnalités
1. **Lecture ligne par ligne**  
   - Lecture d’un fichier ou de l’entrée standard (`stdin`) ligne par ligne.
   - Gestion des retours à la ligne (`\n`) et des fins de fichier.

2. **Gestion de buffer**  
   - Utilisation d’un **BUFFER_SIZE** paramétrable (défini lors de la compilation).  
   - Concaténation des lectures partielles pour reformer une ligne complète.

3. **Gestion multi-fd** (bonus)  
   - Capacité à lire **plusieurs fichiers en parallèle** grâce à un stockage indépendant par descripteur.

4. **Bonus**  
   - Utilisation optimisée de `static` pour stocker les restes de lecture entre appels.
