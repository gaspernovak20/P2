#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000000

int main(int argc, char const *argv[])
{       
    if(argc != 3){
        printf("[napaka]: program potrebuje 2 argumenta");
        exit(1);
    }

    FILE *in;
    in = fopen(argv[1], "rt");
    if(in == NULL){
        printf("[napaka]: napaka pri branju datoteke %s \n", argv[1]);
        return 1;
    }

    FILE *out;
    out = fopen(argv[2], "wt");

    char *str = (char *)malloc( (MAX_LINE_LENGTH +1) * sizeof(char) );
    int najDolzina = 0;
    char *najStr = NULL;


    //iz toka STREAm prebere vrstico dolzine n (vklucno z \n) in jo shrani v niz str
    while ( fgets(str, MAX_LINE_LENGTH +1 ,in) != NULL )
    {   
        int dolzina = strlen(str);

        if(najDolzina < dolzina){
            najDolzina = dolzina;

            free(najStr);
            najStr = malloc( ( najDolzina + 1 ) *sizeof(char) );
            strcpy(najStr, str);
        }
    }
    free(str);

    fprintf(out, "%s", najStr);
    free(najStr);

    fclose(in);
    fclose(out);
    
    return 0;
}
