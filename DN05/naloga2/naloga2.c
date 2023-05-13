
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include <stdio.h>

#include "naloga2.h"

void zamenjaj(int **a, int **b)
{
    int *c = *a;

    *a = *b;
    *b = c;
}

void uredi(int **a, int **b, int **c)
{
    if(**a > **b){
        zamenjaj(a,b);
    }

    if(**a > **c){
        zamenjaj(a,c);
    }

    if(**b > **c){
        zamenjaj(b,c);
    }
    
}

#ifndef test

int main()
{
    // koda za ro"cno testiranje (po "zelji)

    // int a = 1;
    // int b = 2;

    // int *p_a = &a;
    // int *p_b = &b;

    // int **pp_a = &p_a;
    // int **pp_b = &p_b;

    // printf("%d, %d", **p_a, **p_b);

    return 0;
}

#endif
