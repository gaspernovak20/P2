
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Javni testni primeri (po te"zavnosti):
 * -- 02, 03, 04: en sam vhodni niz;
 * -- 05, 06, 07: vsi vhodni nizi so enako dolgi;
 * -- 01, 08, 09, 10: splo"sni primeri.
 *
 * Javni testni primeri (po na"cinu priprave):
 * -- 01: primer iz besedila;
 * -- 01, 02, 05: ro"cno ustvarjeni;
 * -- ostali: samodejno generirani.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

//=============================================================================

int najdalsi_niz(char **nizi, int stVhodnih)
{

    int najvecji = strlen(nizi[0]);

    for (int i = 1; i < stVhodnih; i++)
    {
        if (najvecji < strlen(nizi[i]))
        {
            najvecji = strlen(nizi[i]);
        }
    }

    return najvecji;
}

char **poStolpcih(char **nizi, int stVhodnih, int *stIzhodnih)
{

    *stIzhodnih = najdalsi_niz(nizi, stVhodnih);

    char **array = (char **)malloc(*stIzhodnih * sizeof(char *));

    for (int x = 0; x < *stIzhodnih; x++)
    {
        char *nov_niz = (char *)calloc(stVhodnih, sizeof(char));
        int index = 0;

        for (int y = 0; y < stVhodnih; y++)
        {
            if (strlen(nizi[y]) > x)
            {
                nov_niz[index] = nizi[y][x];
                index++;
            }
        }
        array[x] = nov_niz;
    }

    return array;
}

//=============================================================================

#ifndef test

int main()
{
    // "Ce "zelite funkcijo poStolpcih testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
