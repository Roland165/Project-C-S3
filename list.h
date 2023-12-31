#ifndef PROJET_C_S3_MAX_LIST_H
#define PROJET_C_S3_MAX_LIST_H

#include "cell_and_cells.h"

// Définition de la structure List représentant une liste
typedef struct List {
    Cells cellsHeads;  // Structure de cellules représentant les têtes de chaque niveau de la liste
    int nbLevels;       // Nombre total de niveaux dans la liste
} List;

// Fonction pour créer une liste vide avec un certain nombre de niveaux
List* createEmptyList(int level);

// Fonction pour insérer une cellule dans la liste de manière ordonnée
List* insertCellInOrder(List* list, int value, int level);

// Fonction pour insérer une cellule en tête de liste
List* addCellToHeadList(List* list, int value, int level);

// Fonction pour afficher les cellules pour un niveau spécifique de la liste
void displayCellsForLevel(List* list, int level);

// Fonction pour afficher toutes les cellules de tous les niveaux de la liste
void displayAllLevels(List* list);

#endif
