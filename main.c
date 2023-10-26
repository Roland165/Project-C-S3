#include <stdio.h>
#include "list.h"
int main() {
    List myList = createList();
    addCellToList(&myList, 5, 0);
    addCellToList(&myList, 8, 0);
    addCellToList(&myList, 16, 1);
    addCellToList(&myList, 414, 2);
    displayList(myList);

    return 0;
}
