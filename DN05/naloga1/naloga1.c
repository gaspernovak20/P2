
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "naloga1.h"

int *poisci(int *t, int *dolzina, int **konec)
{
    int lenght = 1;
    int *p_array_start = t;
    int *p_array_and = t;

    // LEVA STARN
    while (*p_array_start != 0)
    {
        p_array_start--;
        lenght++;
    }

    // DESNA STARN
    while (*p_array_and != 0)
    {
        p_array_and++;
        lenght++;
    }

    *dolzina = lenght - 2;
    *konec = p_array_and - 1;

    return p_array_start + 1;
}

#ifndef test

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
