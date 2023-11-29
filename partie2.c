#include "partie2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

List* createListFromValue(int n){
    // numLevels est en réalité numCells (le nombre de cells dans la liste entière)
    int numLevels = pow(2, n) - 1;
    int* levels = (int*)malloc(sizeof(int) * numLevels);
    // boucle for qui initialise le niveau de toutes les cellules à 1.
    for (int i = 0; i < numLevels; i++) {
        levels[i] = 1;
    }
    // What the hell is Z ??
    int z = 1;
    // Z va de 1 à nombre maxi de niveaux (de la liste)
    while (z < n) {
        int v = pow(2, z);
        //boucle qui pour chaque Z, parcours toutes les cells (Avec j : indice de cellule)
        for (int j = 1; j < numLevels; j++) {
            //Si l'indice de notre cellule(j) modulo v(v est une puissance de n) égal 0, alors on rajoute un niveau à notre cellule.
            if ((j %v) == 0) {
                levels[j-1]++;
            }
        }
        z++;
    }

    List* newList = createEmptyList(n);
    for (int i = 0; i < numLevels; i++) {
        addCellToHeadList(newList, i + 1, levels[i]);
    }

    free(levels);

    return newList;
}

Cell* searchInTheLowestLevel(List* myList, int target) {
    Cell* current = myList->cellsHeads.next[0];

    while (current != NULL) {
        if (current->value == target) {
            return current;
        }
        current = current->cellsNext.next[0];
    }

    return NULL;
}

Cell* searchFromHighestLevel(List* myList, int target) {
        int highestLevel = myList->nbLevels - 1;
        Cell *current = myList->cellsHeads.next[highestLevel];

        while (current != NULL) {
            if (current->value == target) {
                return current;
            }

            if (current->nbLevels > 0) {
                current = current->cellsNext.next[current->nbLevels - 1];
            }
        }
    return NULL;
}
