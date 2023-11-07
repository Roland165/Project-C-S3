//
// Created by Max on 02/11/2023.
//

#ifndef PROJET_C_S3_MAX_CELLANDCELLS_H
#define PROJET_C_S3_MAX_CELLANDCELLS_H


typedef struct Cells{
    struct Cell **next;
}Cells;

typedef struct Cell{
    int value;
    struct Cells cellsNext;
    int nbLevels; //nombre de cases dans le tab 1D Cells
}Cell;



Cell* createCell(int value, int nbLevels);
void DEBUGDisplayCell(Cell* myCell);

#endif //PROJET_C_S3_MAX_CELLANDCELLS_H
