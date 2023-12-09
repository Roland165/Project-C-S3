#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Création d'une nouvelle liste vide avec le nombre maximal de niveaux spécifié
List* createEmptyList(int nbLevelsMaxi) {
    if (nbLevelsMaxi == 0) {
        return NULL;
    }

    List* newList = (List*)malloc(sizeof(List));
    newList->nbLevels = nbLevelsMaxi;

    // Allocation dynamique du tableau de pointeurs pour les niveaux de la liste
    newList->cellsHeads.next = (Cell**)malloc(sizeof(Cell*) * nbLevelsMaxi);

    // Initialisation de chaque pointeur à NULL
    for (int i = 0; i < nbLevelsMaxi; i++) {
        newList->cellsHeads.next[i] = NULL;
    }

    return newList;
}

// Ajout d'une cellule avec la valeur spécifiée à la tête de la liste
List* addCellToHeadList(List* myList, int value, int nbLevels) {
    Cell* newCell = createCell(value, nbLevels);

    // Boucle pour parcourir les niveaux et insérer la nouvelle cellule
    for (int i = 0; i < nbLevels; i++) {
        Cell** current = &myList->cellsHeads.next[i];
        while (*current != NULL && (*current)->value < value) {
            current = &(*current)->cellsNext.next[i];
        }
        newCell->cellsNext.next[i] = *current;
        *current = newCell;
    }

    return myList;
}


// Affichage des cellules d'un niveau spécifié dans la liste
void displayCellsInListByLevel(List* myList, int level) {
    if (myList->cellsHeads.next[0] == NULL) {
        printf("This list is empty.\n");
        return;
    }

    if (level < 0 || level >= myList->nbLevels) {
        printf("Error: Cannot display this level. The level of a list starts at 0 and is less than or equal to the total number of levels.\n");
        return;
    }

    Cell* temp = myList->cellsHeads.next[level];
    printf("Display of list by level %d : ", level);

    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->cellsNext.next[level];
    }

    printf("NULL\n");
}



// Affichage de toutes les cellules dans la liste, par niveau
void displayCellsInList(List* myList) {
    if (myList == NULL) {
        printf("DisplayCellsInList error: List is empty (NULL).\n");
        return;
    }

    for (int level = 1; level <= myList->nbLevels; level++) {
        Cell* temp = myList->cellsHeads.next[0];
        printf("[list head_%d @-]--", level - 1);

        while (temp != NULL) {
            // Affichage de la cellule si elle a un niveau suffisant
            if (temp->nbLevels >= level) {
                printf(">[ %d|@-]--", temp->value);
            } else {
                printf("----------");
            }
            temp = temp->cellsNext.next[0];
        }

        printf(">NULL\n");
    }
}
