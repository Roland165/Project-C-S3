#include "partie2.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

List* createListFromValue(int n) {
    int numLevels = pow(2, n) - 1;
    int* levels = (int*)malloc(sizeof(int) * numLevels);
    for (int i = 0; i < numLevels; i++) {
        levels[i] = 1;
    }

    int z = 1;
    while (z < n) {
        for (int j = 1; j < numLevels; j++) {
            int v = pow(2, z);
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
    int highestLevel = myList->nbLevels -1;
    Cell *current = myList->cellsHeads.next[highestLevel];
    while(current->value>target){
        highestLevel=highestLevel-1;
        current = myList->cellsHeads.next[highestLevel];
    }
    if (current->value == target){
        return current;
    }
    while (highestLevel>=0){
        if(current->cellsNext.next[highestLevel]!= NULL && current->cellsNext.next[highestLevel]->value == target){
            return current->cellsNext.next[highestLevel];
        }
        if (current->cellsNext.next[highestLevel]== NULL || current->cellsNext.next[highestLevel]->value>target){
            highestLevel --;
        }
        else{
            current = current->cellsNext.next[highestLevel];
        }
    }
    return NULL;
}

void displaySearchFromHighestLevel(List* myList, int target){
    Cell *resultHighestLevel = searchFromHighestLevel(myList, target);
    if (resultHighestLevel != NULL) {
        printf("Found %d at level %d.\n", target, resultHighestLevel->nbLevels);
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