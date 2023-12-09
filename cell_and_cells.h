#ifndef PROJET_C_S3_MAX_CELL_AND_CELLS_H
#define PROJET_C_S3_MAX_CELL_AND_CELLS_H


// Définition d'une structure Cells représentant un tableau de pointeurs vers des Cell
typedef struct Cells {
    struct Cell** next;  // Tableau de pointeurs vers les cellules au niveau suivant
} Cells;

// Définition d'une structure Cell représentant une cellule avec plusieurs niveaux
typedef struct Cell {
    int value;           // Valeur stockée dans la cellule
    Cells cellsNext;     // Structure Cells représentant les niveaux suivants
    int nbLevels;        // Nombre de niveaux dans la liste à niveaux
} Cell;


Cell* createCell(int, int);
#endif
