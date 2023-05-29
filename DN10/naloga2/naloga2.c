
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

Ulomek *k_invert(Premica premica)
{
    Ulomek *k_1 = (Ulomek *)malloc(sizeof(Ulomek));

    Ulomek k = premica.k;

    //zamenjamo im in st ce st != 0
    if (k.st != 0)
    {
        k_1->st = k.im;
        k_1->im = k.st;
    }else{
        k_1->st = k.st;
        k_1->im = k.im; 
    } 

    //zagotovimo da im ni negativni int
    if (k_1->im < 0)
    {
        k_1->st *=-1;
        k_1->im *=-1;
    }

    return k_1;
}

Tocka projekcija(Tocka t, Premica p)
{
    //T: x in y 
    Ulomek x = t.x;
    Ulomek y = t.y;

    Ulomek *k_1 = k_invert(p);

    Ulomek *kx = (Ulomek*)malloc(sizeof(Ulomek));


    kx->st = 

    return (Tocka){(Ulomek){0, 1}, (Ulomek){0, 1}};
}

#ifndef test

int main()
{
    return 0;
}

#endif
