#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
#include "ROT.h"

//////Main

int rot(int argc, char *argv[], bool __main__)
{
    //Verification nombre d'arguments
    if(argc != 3)
    {
        if(__main__ == true)
            printf("Erreur -> Pototype : ROT <step> <string> -> <string>");
        else
            printf("Erreur -> Pototype : CRYP rot <step> <string> -> <string>");
        return 0;
    }

    //Initialisation variables
    int step = atoi(argv[1])%26;
    int lenMessage = strlen(argv[2]);
    char message[lenMessage+1];
    strncpy(message, "", sizeof(message));

    //Affichage utilisateur
    printf("ROT %d of \"%s\" :\n", atoi(argv[1]), argv[2]);
    printf("=> ");

    //Boucle de chiffrement
    for(int i = 0; i<lenMessage; ++i)
    {
        int caracterInt = (int)(argv[2][i]);
        char newCaracter = caracterInt;

        //Traitement minuscule
        if('a'<=caracterInt && caracterInt<='z') newCaracter = ((caracterInt-'a')+step)%26+'a';
        //Traitement majuscule
        if('A'<=caracterInt && caracterInt<='Z') newCaracter = ((caracterInt-'A')+step)%26+'A';
        
        strncat(message, &newCaracter, 1);
        printf("%c", newCaracter);

    }
    
    //Copie dans le press papier
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, lenMessage+1);
    memcpy(GlobalLock(hMem), message, lenMessage+1);
    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    return 0;
}