
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

int **ap2pp(int (*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic)
{

    int el_per_row = sizeof(*kazalec) / sizeof(int);
    int num_elements = el_per_row * izvornoStVrstic;

    int new_el_per_row = num_elements / ciljnoStVrstic;

    int **table = (int **)malloc(ciljnoStVrstic * sizeof(int *));

    for (int i = 0; i < ciljnoStVrstic; i++)
    {
        table[i] = (int *)calloc(new_el_per_row + 1, sizeof(int));
    }

    for (int x = 0; x < num_elements; x++)
    {
        table[x / new_el_per_row][x % new_el_per_row] = kazalec[x / el_per_row][x % el_per_row];
    }

    return table;
}

int (*pp2ap(int **kazalec, int izvornoStVrstic, int *ciljnoStVrstic))[N]
{
    // popravite / dopolnite
    return NULL;
}

#ifndef test

int main()
{
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
