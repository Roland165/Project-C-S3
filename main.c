#include "partie2.h"
#include "agenda.h"

int main() {
    //partie 1
    /*
    List *myList = createEmptyList(5);
    addCellToHeadList(myList, 5, 2);
    insertCellInOrder(myList, 3, 3);
    insertCellInOrder(myList, 6, 2);
    insertCellInOrder(myList, 9, 3);
    insertCellInOrder(myList, 7, 0);
    insertCellInOrder(myList, 2, 4);
    addCellToHeadList(myList, 8, 4);
    displayAllLevels(myList);
    displayCellsForLevel(myList,2);
    displayCellsForLevel(myList,4);

    //partie 2
    int nbLevels = 8;
    List *myList2 = createListFromValue(nbLevels);
    displaySearchInLowestLevel(myList2, 9);
    displaySearchInLowestLevel(myList2, 3000);
    displaySearchInLowestLevel(myList2, 17);
    displaySearchInLowestLevel(myList2, 998);
    displaySearchFromHighestLevel(myList2, 8);
    displaySearchFromHighestLevel(myList2, 16);
    displaySearchFromHighestLevel(myList2, 62);
    displaySearchFromHighestLevel(myList2, 100);
    displayAllLevels(myList2);
    displayTimeBothSearches(11, 100000);
    */
    //partie 3
    LLCRDV *llcrdv =createLLCRDV();

    RDV* myRDV = createRDV(01,10,2000,23,59,"Coucou les musulmans moi je mange de la glace");
    RDV* secondRDV = createRDV(20,18,2057,14,18,"Ca marche?");
    //RDV* thirdRDV = createRDV(20,18,2057,14,18,"Ca marche?");

    //addRDVtoLLCRDV(myRDV,llcrdv);
    //addRDVtoLLCRDV(secondRDV,llcrdv);
    //addRDVtoLLCRDV(thirdRDV,llcrdv);

    //displayLLCRDV(*llcrdv);

    ListAgenda *listagenda = createEmptyListAgenda();
    Contact *emmanouel = createContact("Dupont","Emmanouel");
    Entree *entreeemmanouel= createEntree(*emmanouel);
    addRDVtoLLCRDV(myRDV,llcrdv);
    entreeemmanouel->myLLCRDV=*llcrdv;
    addRDVtoLLCRDV(secondRDV,llcrdv);
    addEntreetoAllList(listagenda, entreeemmanouel);
    Contact *nathan = createContact("Dugrond","Nathan");
    Entree *entreenathan= createEntree(*nathan);
    addEntreetoAllList(listagenda, entreenathan);
    Contact *roland = createContact("Fontanes","Roland");
    Entree *entreeroland= createEntree(*roland);
    addEntreetoAllList(listagenda, entreeroland);
    Contact *elia = createContact("Eglantine","Elia");
    Entree *entreeelia= createEntree(*elia);
    addEntreetoAllList(listagenda, entreeelia);
    displayList(*listagenda);
    displayAgendaInList(listagenda);
    char* try = (char *) "Dupont";
    displayInformationFromSomeone(try, *listagenda);
    //menu();
}
