#include <stdio.h>

#include "cellandcells.h"
#include "list.h"

int main() {
    Cell* myCell = createCell(5,2);
    //DEBUGDisplayCell(myCell);
    List* myList = createEmptyList(3);
    addCellToHeadList(myList, 3, 3);
    addCellToHeadList(myList, 6, 2);
    addCellToHeadList(myList, 7, 1);
    //myList->cellsHeads.next[1] =  myList->cellsHeads.next[0]->cellsNext.next[0];
    displayCellsInListByLevel(myList,2);
    displayCellsInList(myList);

    return 0;
}
