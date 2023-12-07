#include "partie2.h"
#include "string.h"
#include "stdio.h"
#include "agenda.h"


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
    //int nbLevels = 3;
    //List* myList2 = createListFromValue(nbLevels);
    //displayCellsInList(myList2);
    //displaySearchFromHighestLevel(myList2, 8);

    //printf("debug search low bool = %d\n",searchForNbrValuesFromLowestLevel(myList2, 4, 30));
    //printf("debug search high bool = %d\n",searchForNbrValuesFromHighestLevel(myList2, 4, 30));

    //displayTimeBothSearchesForNbrLevelsMaxAndNbrValues(15,1000);
    //displayTimeBothSearchesForNbrLevelsMaxAndNbrValues(15,10000);
    //displayTimeBothSearchesForNbrLevelsMaxAndNbrValues(15,100000);

    //partie 3

    //char* myStr = scanString();
    //printf("result: %s\n",myStr);
    //char* myStr2 = scanString();
    //printf("result: %s \n",myStr2);

    //Contact* myContact = createContact(myStr,myStr2);
    //displayContact(myContact);


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
    addEntreetoList(listagenda, entreeemmanouel);
    Contact *nathan = createContact("Dugrond","Nathan");
    Entree *entreenathan= createEntree(*nathan);
    addEntreetoList(listagenda, entreenathan);
    Contact *roland = createContact("Fontanes","Roland");
    Entree *entreeroland= createEntree(*roland);
    addEntreetoList(listagenda, entreeroland);
    Contact *elia = createContact("Eglantine","Elia");
    Entree *entreeelia= createEntree(*elia);
    addEntreetoList(listagenda, entreeelia);
    displayList(*listagenda);

    return 0;
}
