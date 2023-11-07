#include <stdio.h>

#include "cellandcells.h"
#include "list.h"

int main() {
    Cell* myCell = createCell(5,2);
    //DEBUGDisplayCell(myCell);
    List* myList = createEmptyList(2);
    addCellToHeadList(myList, 3, 1);
    addCellToHeadList(myList, 6, 1);
    displayCellsInListByLevel(myList,1);

    return 0;
}
