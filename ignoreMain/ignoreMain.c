#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* toLowerCase (char* str)
{
    for (int i = 0; str[i]!='\0'; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i]+32;
        }
    }
    return str;
}

int main(int argc, char *argv[]){
    FILE *fp1, *fp2, *fp3;
    char ch;

    char filecpy[strlen(argv[1])+10];
    strcat(filecpy, "../src/");
    strcat(filecpy, argv[1]);
    strcat(filecpy, ".c");

    char filepast[strlen(argv[1])+14];
    strncpy(filepast, "", sizeof(filepast));
    strcat(filepast, "../src/");
    strcat(filepast, argv[1]);
    strcat(filepast, "_tmp.c");

    // ouvrir le fichier en lecture
    fp1 = fopen(filecpy, "r");
    // ouvrir le fichier en écriture
    fp2 = fopen(filepast, "w");

    fp3 = fopen("header.txt", "r");

    // Lire le contenu du fichier
    
    
    int i = 0;
    int Header = 0;

    // Lire le contenu du fichier
    while((ch = getc(fp1)) != EOF)
        if(ch=='/' && Header==0){
            putc(ch, fp2);
            i++;
            if(i==4){
                Header = 1;
                putc('\n', fp2);
                while((ch = getc(fp3)) != EOF)
                {
                    if(ch=='#')
                        fputs(toLowerCase(argv[1]), fp2);
                    else putc(ch, fp2);
                }
            }
        }else{
            i=0;
            putc(ch, fp2);
        }
  
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 1;
}
