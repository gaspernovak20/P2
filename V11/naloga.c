
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    // popravite / dopolnite ...
    int vsota = 0;

    while ( zacetek != NULL)
    {
        vsota += zacetek->podatek;
        zacetek = zacetek->naslednje;
    }

    return vsota;

}

int vsotaR(Vozlisce* zacetek) {
    // v1 moja


    // int vsota = 0;

    // if(zacetek == NULL){
    //     return 0;
    // }else{
    //     vsota += vsotaR(zacetek->naslednje);
    //     vsota += zacetek->podatek;
    // }
    //return vsota;

    if(zacetek == NULL){
        return 0;
    }

    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce *createNode(int data, Vozlisce *next_node){
    Vozlisce *new_node = malloc(sizeof(*new_node));
    new_node->podatek = data;
    new_node->naslednje = next_node;
    return new_node;
}


Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    // popravite / dopolnite ...
    if (zacetek == NULL || element < zacetek->podatek)
    {
        // dodamo na zacetek ali v prazen seznam
        return createNode(element, zacetek);
    }else
    {
        //dodamo na sredino ali konec
        Vozlisce *seznam = zacetek;

        while (seznam->naslednje != NULL && seznam->naslednje->podatek < element)
        {
            seznam = seznam->naslednje;
        }

        Vozlisce *new_node = createNode(element, seznam->naslednje);
        seznam->naslednje = new_node;
    }
    
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {

    if(zacetek == NULL || zacetek->podatek > element){
        return createNode(element, zacetek);
    }else{
        zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
        return zacetek;
    }
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
