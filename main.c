#include "partie2.h"
#include "agenda.h"

int main() {
    // PARTIE 1 :

    Cell *cell1 = createCell(4, 3);
    List *myList1 = createEmptyList(6);
    addCellToHeadList(myList1, 4,3);
    addCellToHeadList(myList1, 1,4);
    addCellToHeadList(myList1, 7,2);
    displayCellsForLevel(myList1, 1);
    displayAllLevels(myList1);

    //PARTIE 2

    List *myList2 = createListFromValue(3);
    displayAllLevels(myList2);
    displaySearchInLowestLevel(myList2,4);
    displaySearchFromHighestLevel(myList2,8);
    displayTimeBothSearches(12,100000);


    //PARTIE 3

    ListAgenda *myList3=createEmptyListAgenda();
    Entree *entreepaulo = createContactInList(myList3, "Dybala", "Paulo");
    Entree *entreeyassine = createContactInList(myList3, "Bounou", "Yassine");

    createRDVForEntree(10,05,2017,12,45,"Blessure grave",entreepaulo);
    createRDVForEntree(15,07,2018,10,05,"Visite anuelle",entreepaulo);
    createRDVForEntree(18,07,2018,11,30,"Visite anuelle",entreeyassine);
    deleteRDVFromEntreeByObject(entreepaulo,"Blessure grave");

    displayContact(&entreepaulo->myContact);
    displayInformationFromSomeone("Dybala", *myList3);

    displayAgendaInList(myList3);
    displayList(*myList3);
}
