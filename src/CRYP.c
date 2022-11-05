#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ROT.h"

char* toLowerCase (char*);

int main(int argc, char *argv[])
{
    //Verification nombre d'arguments
    if(argc == 1)
    {
        printf("Erreur -> Pototype : CRYP <Algo de chiffrement> <Arguments du chiffrement ...> -> <string>");
        return 0;
    }

    //Separation des arguments avec le type d'algo et les autres arguments utiles pour les autres fonctions
    //Varuable qui contient le type d'algo (rot ...)
    char Algo[strlen(argv[1]+1)];
    strcpy(Algo, toLowerCase(argv[1]));
    //On enleve 1 car on supprime l'agument algo qui a été extrait dans une autre variable
    int newArgc = argc-1;
    //Suppression du premier argument (type d'algo sui ne sera plus utile)
    char *newArgv[newArgc];
    for(int i = 0; i < newArgc ; i++)
        newArgv[i] = argv[i+1];


    //Comparaison pour choisir le bon algo
    if(strcmp(Algo,"rot") == 0)
        rot(newArgc, newArgv, false);
    
    return 1;
}

char* toLowerCase (char* str)
{
    for (int i = 0; str[i]!='\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i]+32;
        }
    }
    return str;
}