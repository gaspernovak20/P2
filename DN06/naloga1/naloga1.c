
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char *zdruzi(char **nizi, char *locilo)
{
    char *nov_niz = (char *)calloc(200 ,sizeof(char));

        for (int i = 0; nizi[i] != NULL; i++)
    {
        strcat(nov_niz, nizi[i]);
        if (nizi[i + 1] != NULL)
            strcat(nov_niz, locilo);
    }

    return nov_niz;
}

int main()
{
    // koda za ro"cno testiranje
    return 0;
}