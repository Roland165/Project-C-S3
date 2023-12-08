#include "partie2.h"
#include "agenda.h"

int main() {
    //partie 1
    /*
    List* myList = createEmptyList(5);
    addCellToHeadList(myList, 3, 3);
    addCellToHeadList(myList, 6, 2);
    addCellToHeadList(myList, 9, 3);
    addCellToHeadList(myList, 7, 1);
    addCellToHeadList(myList, 15,1);
    displayCellsInList(myList);

    //partie 2
    int nbLevels = 15;
    List* myList2 = createListFromValue(nbLevels);
    displaySearchInTheLowestLevel(myList2, 9);
    displaySearchInTheLowestLevel(myList2, 3000);
    displaySearchInTheLowestLevel(myList2, 17);
    displaySearchInTheLowestLevel(myList2, 998);
    displaySearchFromHighestLevel(myList2, 8);
    displaySearchFromHighestLevel(myList2, 16);
    displaySearchFromHighestLevel(myList2, 62);
    displaySearchFromHighestLevel(myList2, 100);
    displayTimeBothSearchesForNbrLevelsMaxAndNbrValues(14,100000);
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
