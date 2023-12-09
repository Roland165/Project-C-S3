#include "cell_and_cells.h"
#include <stdio.h>
#include <stdlib.h>


// Fonction pour créer une nouvelle cellule
Cell* createCell(int value, int nbLevels) {
    if (nbLevels == 0) {
        return NULL;
    } else {
        Cell* newCell = (Cell*)malloc(sizeof(Cell));
        newCell->value = value;
        newCell->nbLevels = nbLevels;

        // Allocation dynamique du tableau de pointeurs pour les niveaux suivants
        newCell->cellsNext.next = (Cell**)malloc(sizeof(Cell*) * nbLevels);

        // Initialisation de chaque pointeur à NULL
        for (int i = 0; i < nbLevels; i++) {
            newCell->cellsNext.next[i] = NULL;
        }
        return newCell;
    }
}
