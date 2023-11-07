//
// Created by Max on 02/11/2023.
//

#include "cellandcells.h"
#include <stdio.h>
#include <stdlib.h>


Cell* createCell(int value, int nbLevels){
    if(nbLevels == 0){
        return NULL;
    }
    else{

        /*
         * newcell -> struct { value = 5; nbLevels = 2 ; cellsNext = Cells { 2 entrées de ptr de Cell} }
         */
        Cell* newCell = (Cell*)malloc(sizeof(Cell));
        newCell->value = value;
        newCell->nbLevels = nbLevels;
        // On alloue de la mémoire pour notre tableau 1D et on le cast en Cell**
        Cell** newCells = (Cell**)malloc(sizeof(Cell*)*nbLevels);
        //Puis on met ce Cell** dans la variable de la struct Cells elle meme contenue dans notre Cell.
        newCell->cellsNext.next = newCells;
        // On met tous les pointeus next de Cells a NULL.
        for(int i = 0; i<nbLevels; i++){
            newCell->cellsNext.next[i] = NULL;
        }
        return newCell;
    }
}

void DEBUGDisplayCell(Cell* myCell){
    printf("value: %d\n",myCell->value);
    printf("nbLevels: %d\n",myCell->nbLevels);
    printf("pointers: \n");
    for(int i = 0; i<myCell->nbLevels; i++){
        printf("    %d: %p\n", i+1, myCell->cellsNext.next[i]);
    }
    printf("\n");
}