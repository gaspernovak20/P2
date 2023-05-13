
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
 * -- 02, 03: dol"zina vsakega vhodnega niza je enaka ciljnaDolzina;
 * -- 04, 05, 06, 07: dol"zina vsakega vhodnega niza je enaka 1;
 * -- 01, 08, 09, 10: splo"sni primeri.
 *
 * Javni testni primeri (po na"cinu priprave):
 * -- 01: primer iz besedila;
 * -- 01, 02, 04: ro"cno ustvarjeni;
 * -- ostali: samodejno generirani.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

//=============================================================================

char **naSredino(char **nizi, int ciljnaDolzina)
{

    // num of elements

    int num_elements = 0;

    for (int i = 0; nizi[i] != NULL; i++)
    {
        num_elements++;
    }
    char **array = (char **)malloc(num_elements * sizeof(char *));

    for (int i = 0; i < num_elements; i++)
    {
        array[i] = (char *)calloc(ciljnaDolzina+1, sizeof(char));

        // dolocanje pik
        int index = 0;
        int size_char = strlen(nizi[i]);
        int pike = ciljnaDolzina - size_char;

        int star_pike = pike / 2;

        while (index < star_pike)
        {
            array[i][index] = '.';
            index++;
        }

        int a = 0;

        while (index < (star_pike + size_char))
        {
            array[i][index] = nizi[i][a];
            index++;
            a++;
        }

        while (index < ciljnaDolzina)
        {
            array[i][index] = '.';
            index++;
        }
    }

    array[num_elements] = NULL;

    return array;
}

//=============================================================================

#ifndef test

char *NIZI[] = {
    "Danes",
    "je",
    "kolokvij",
    "pri_P2!",
    NULL};

int main()
{
    // "Ce "zelite funkcijo naSredino testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    char **izhodni = naSredino(NIZI, 9);

    int stNizov = sizeof(NIZI) / sizeof(NIZI[0]) - 1;
    for (int i = 0; i < stNizov; i++)
    {
        printf("%d: \"%s\"\n", i, izhodni[i]);
        free(izhodni[i]);
    }
    printf("%s\n", (izhodni[stNizov] == NULL) ? ("NULL") : ("NAPAKA"));

    free(izhodni);
    return 0;
}

#endif
