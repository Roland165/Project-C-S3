//
// Created by Max on 02/11/2023.
//



#ifndef PROJET_C_S3_MAX_LIST_H
#define PROJET_C_S3_MAX_LIST_H

#include "cellandcells.h"

typedef struct List{
    Cells cellsHeads;
    int nbLevels;
}List;

List* createEmptyList(int nbLevelsMaxi);
List* addCellToHeadList(List* myList, int value, int nbLevels);
void displayCellsInListByLevel(List* myList, int level);
void displayCellsInList(List* myList);


#endif //PROJET_C_S3_MAX_LIST_H
