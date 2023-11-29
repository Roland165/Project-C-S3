#include "partie2.h"
#include "string.h"
#include "stdio.h"
int main() {
    //partie 1
    /*List* myList = createEmptyList(5);
    addCellToHeadList(myList, 3, 3);
    addCellToHeadList(myList, 6, 2);
    addCellToHeadList(myList, 9, 3);
    addCellToHeadList(myList, 7, 1);
    addCellToHeadList(myList, 15,1);
    displayCellsInList(myList);*/

    //partie 2
    int nbLevels = 10;
    List* myList2 = createListFromValue(nbLevels);
    displayCellsInList(myList2);

    //Cell* cell = findPrevious(myList->cellsHeads.next[myList2->nbLevels - 1], myList2,2);
    //printf("%d\n",cell->value);
    displaySearchFromHighestLevel(myList2, 8);
    displaySearchFromHighestLevel(myList2, 16);
    displaySearchFromHighestLevel(myList2, 62);
    displaySearchFromHighestLevel(myList2, 100);
    return 0;
}
