//
// Created by Max on 02/12/2023.
//
#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>


char* scanString(){
    char* tempStr = (char*)malloc(200*sizeof(char));
    printf("Scanning:");
    scanf("%s",tempStr);
    return tempStr;
}