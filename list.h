#ifndef PROJET_C_S3_MAX_LIST_H
#define PROJET_C_S3_MAX_LIST_H

#include "cell_and_cells.h"

typedef struct List{
    Cells cellsHeads;
    int nbLevels;
}List;

List* createEmptyList(int);
void displayCellsForLevel(List* myList, int level);
List* insertCellInOrder(List*, int, int);
void displayAllLevels(List*);


#endif
