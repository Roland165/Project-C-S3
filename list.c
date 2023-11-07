//
// Created by Max on 02/11/2023.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List* createEmptyList(int nbLevelsMaxi){
    if(nbLevelsMaxi == 0){
        return NULL;
    }
    else{
        List* newList = (List*)malloc(sizeof(List));
        newList->nbLevels = nbLevelsMaxi;
        Cell** newCells = (Cell**)malloc(sizeof(Cell*) * nbLevelsMaxi);
        newList->cellsHeads.next = newCells;
        for(int i = 0; i < nbLevelsMaxi; i++){
            newList->cellsHeads.next[i] = NULL;
        }
        return newList;
    }
}

List* addCellToHeadList(List* myList, int value, int nbLevels){
    Cell* newCell = createCell(value, nbLevels);
    newCell->cellsNext.next[0] = myList->cellsHeads.next[0];
    myList->cellsHeads.next[0] = newCell;
    return myList;
}

void displayCellsInListByLevel(List* myList, int level){
    if(myList->nbLevels == 0){
        printf("Error: nblevels of list is equal to 0.\n");
        return;
    }
    else{
        if(myList->cellsHeads.next[0] == NULL){
            printf("This list is empty.\n");
            return;
        }
        else{
            if(level <= 0){
                printf("Error: cannot display this level, the level of a list begins at 1.\n");
                return;
            }
            else {
                Cell *temp = myList->cellsHeads.next[level - 1];
                printf("Display of list by level %d: ", level);
                while (temp != NULL) {
                    printf("%d ", temp->value);
                    temp = temp->cellsNext.next[level - 1];
                }
                printf("\n");
                return;
            }
        }
    }
}