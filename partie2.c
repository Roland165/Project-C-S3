#include "partie2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "timer.h"

List *createListFromValue(int n) {
    if (n == 0) {
        return NULL;
    }
    // numLevels est en réalité numCells (le nombre de cells dans la liste entière)
    int numLevels = pow(2, n) - 1;
    int *levels = (int *) malloc(sizeof(int) * numLevels);
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
            if ((j % v) == 0) {
                levels[j - 1]++;
            }
        }
        z++;
    }

    List *newList = createEmptyList(n);
    for (int i = 0; i < numLevels; i++) {
        addCellToHeadList(newList, i + 1, levels[i]);
    }

    free(levels);

    return newList;
}

Cell *searchInTheLowestLevel(List *myList, int target) {
    Cell *current = myList->cellsHeads.next[0];

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
    if(target < myList->cellsHeads.next[0]->value){
        return NULL;
    }
    while (current->value > target){
        highestLevel = highestLevel - 1;
        current = myList->cellsHeads.next[highestLevel];
    }
    if (current->value == target) {
        return current;
    }
    while (highestLevel >= 0){
        if (current->cellsNext.next[highestLevel] != NULL && current->cellsNext.next[highestLevel]->value == target) {
            return current->cellsNext.next[highestLevel];
        }
        if (current->cellsNext.next[highestLevel] == NULL || current->cellsNext.next[highestLevel]->value > target) {
            highestLevel--;
        } else {
            current = current->cellsNext.next[highestLevel];
        }
    }
    return NULL;
}

void displaySearchFromHighestLevel(List *myList, int target) {
    Cell *resultHighestLevel = searchFromHighestLevel(myList, target);
    if (resultHighestLevel != NULL) {
        printf("Found %d at level %d.\n", target, resultHighestLevel->nbLevels - 1);
    } else {
        printf("%d not found starting from the highest level.\n", target);
    }
}

void displaySearchInTheLowestLevel(List *mylist, int target) {
    Cell *resultLevel0 = searchInTheLowestLevel(mylist, target);

    if (resultLevel0 != NULL) {
        printf("Found %d at level 0.\n", target);
    } else {
        printf("%d not found at level 0.\n", target);
    }
}


int searchForNbrValuesFromLowestLevel(List *myList, int nbLevels, int nbrValues) {
    if ((nbrValues != 0) && (myList != NULL)) {
        //initialisation de la seed de random
        srand(31);
        //valeur maxi qu'on doit chercher dans la liste (pour le random)
        int maxiValueInList = (pow(2, nbLevels)) - 1;
        int iterNbrValues = 1;
        while (iterNbrValues <= nbrValues) {
            int valueToSearch = rand() % (maxiValueInList+1);
            //printf("DEBUG: random valueToSearch = %d\n", valueToSearch);
            searchInTheLowestLevel(myList, valueToSearch);
            iterNbrValues++;
        }
        return 1;
    }
    return 0;
}


int searchForNbrValuesFromHighestLevel(List *myList, int nbLevels, int nbrValues) {
    if ((nbrValues != 0) && (myList != NULL)) {
        //initialisation de la seed de random
        srand(31);
        //valeur maxi qu'on doit chercher dans la liste (pour le random)
        int maxiValueInList = (pow(2, nbLevels)) - 1;
        int iterNbrValues = 1;
        while (iterNbrValues <= nbrValues) {
            int valueToSearch = rand() % (maxiValueInList+1);
            //printf("DEBUG: random valueToSearch = %d\n", valueToSearch);
            searchFromHighestLevel(myList, valueToSearch);
            iterNbrValues++;
        }
        return 1;
    }
    return 0;
}


void displayTimeBothSearchesForOneLevelAndNbrValues(int level, int nbrValues){
    List* myList = createListFromValue(level);
    startTimer();
    if((searchForNbrValuesFromLowestLevel(myList, level, nbrValues))==1){
        stopTimer();
        printf("Lowest Level Seach: nbrValues=%d; level=%d; ",nbrValues,level);
        printf("%s",getTimeAsString());
        printf("\n");
    }
    startTimer();
    if((searchForNbrValuesFromHighestLevel(myList, level, nbrValues))==1){
        stopTimer();
        printf("Highest Level Seach: nbrValues=%d; level=%d; ",nbrValues,level);
        printf("%s",getTimeAsString());
        printf("\n");
    }
    printf("Both Searches for nbrValues=%d; level=%d DONE.\n",nbrValues,level);
}



void displayTimeBothSearchesForNbrLevelsMaxAndNbrValues(int maxLevels, int nbrValues){
    // MIN LEVEL IS 7
    for(int nbrLevels = 7; nbrLevels <= maxLevels; nbrLevels++){
        displayTimeBothSearchesForOneLevelAndNbrValues(nbrLevels, nbrValues);
    }
}
