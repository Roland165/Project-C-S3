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
    int nbLevels = 3;
    List* myList2 = createListFromValue(nbLevels);
    //displayCellsInList(myList2);
    //displaySearchFromHighestLevel(myList2, 8);

    //printf("debug search low bool = %d\n",searchForNbrValuesFromLowestLevel(myList2, 4, 30));
    //printf("debug search high bool = %d\n",searchForNbrValuesFromHighestLevel(myList2, 4, 30));

    displayTimeBothSearchesForNbrLevelsMaxAndNbrValues(14,100000);

    //partie 3
    /*List agenda;

    int option;
    do {
        displayMenu(&agenda);
        printf("Enter your choice (1-8, 0 to exit): ");
        scanf("%d", &option);

        if (option >= 1 && option <= 8) {
            executeMenuOption(&agenda, option);
        } else if (option != 0) {
            printf("Invalid choice. Please enter a number between 0 and 8.\n");
        }*/
    return 0;
}
