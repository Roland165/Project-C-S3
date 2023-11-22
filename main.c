#include "partie2.h"
#include "string.h"
#include "stdio.h"
int main() {
    //partie 1
    List* myList = createEmptyList(5);
    addCellToHeadList(myList, 3, 3);
    addCellToHeadList(myList, 6, 2);
    addCellToHeadList(myList, 9, 3);
    addCellToHeadList(myList, 7, 1);
    addCellToHeadList(myList, 15,1);
    displayCellsInList(myList);

    //partie 2
    int nbLevels = 3;
    int targetValue = 1;
    int targetValue2 = 2;
    List* myList2 = createListFromValue(nbLevels);
    displayCellsInList(myList2);
    Cell* resultLevel0 = searchInTheLowestLevel(myList2, targetValue);
    Cell* resultLevel1 = searchInTheLowestLevel(myList2, targetValue2);
    if (resultLevel0 != NULL) {
        printf("Found %d at level 0.\n", targetValue);
    } else {
        printf("%d not found at level 0.\n", targetValue);
    }
    if (resultLevel1 != NULL) {
        printf("Found %d at level 0.\n", targetValue2);
    } else {
        printf("%d not found at level 0.\n", targetValue2);
    }
    //Cell* cell = findPrevious(myList->cellsHeads.next[myList2->nbLevels - 1], myList2,2);
    //printf("%d\n",cell->value);
    int resultHighestLevel = searchFromHighestLevel(myList2, targetValue);
    int resultHighestLevel1 = searchFromHighestLevel(myList2, targetValue2);
    if (resultHighestLevel != -1) {
        printf("Found %d starting from the level %d.\n", targetValue, resultHighestLevel);
    } else {
        printf("%d not found starting from the highest level.\n", targetValue);
    }
    if (resultHighestLevel1 != -1) {
        printf("Found %d starting from the level %d.\n", targetValue2,resultHighestLevel1);
    } else {
        printf("%d not found starting from the highest level.\n", targetValue2);
    }
    return 0;
}
