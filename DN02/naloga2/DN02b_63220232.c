#include <stdio.h>
#include <stdbool.h>

void izpis(bool jepredznacen)
{
    if (jepredznacen)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}

void unici_niz(int *n)
{
    int h = getchar();

    while (h != ' ' || h !='\n')
    { // unicimo preostanek niza
        h = getchar();
    }
    if(h == '\n'){
        *n = '\n';
    }
}

void odena_dodevet(int *n)
{

    int je_predznacen = true;
    int x = getchar();

    while (x != ' ' && x != '\n')
    {

        if (x < '0' || '9' < x)
        {
            je_predznacen = false;
        }

        if(!je_predznacen){
            unici_niz(&*n);
            break;
        }
        
        x = getchar();
    }

    //koncamo ipis ce je konec niza
    if(x == '\n'){
        *n = '\n';
    }

    izpis(je_predznacen);
}

void odnic_dosedem(int *n)
{
    int je_predznacen = true;
    int x = getchar();

    while (x != ' ' && x != '\n')
    {

        if (x < '0' || '7' < x)
        {
            je_predznacen = false;
        }

        if(!je_predznacen){
            unici_niz(&*n);
            break;
        }

        x = getchar();
    }

    izpis(je_predznacen);
}

void sestnajstisko(int *n)
{
    int je_predznacen = true;
    int x = getchar();

    if(x == ' '){
        je_predznacen = false;
    }

    while (x != ' ' && x != '\n')
    {

        if (x < '0' || ('9' < x && x < 'A') || x > 'F')
        {
            je_predznacen = false;
        }

        if(!je_predznacen){
            unici_niz(&*n);
            break;
        }

        x = getchar();
    }

    izpis(je_predznacen);
}

void dvojisko(int *n)
{
    int je_predznacen = true;
    int x = getchar();

    if(x == ' '){
        je_predznacen = false;
    }

    while (x != ' ' && x != '\n')
    {

        if (x != '0' && x != '1')
        {
            je_predznacen = false;
        }

        if(!je_predznacen){
            unici_niz(&*n);
            break;
        }

        x = getchar();
    }

    izpis(je_predznacen);
}

void zacetek_nic(int *n)
{
    int druga_stevka = getchar();

    if ('0' <= druga_stevka && druga_stevka <= '7')
    {
        // od 0-7
        odnic_dosedem(n);
    }
    else if (druga_stevka == 'x')
    {
        // šesnajstiško stevilo
        sestnajstisko(n);
    }
    else if (druga_stevka == 'b')
    {
        // dvojisko stevilo
        dvojisko(n);
    }
    else if (druga_stevka == ' ' || druga_stevka == '\n')
    {
        // ce je samo stevka 0 je niz predznacen
        izpis(true);
        if(druga_stevka == '\n'){
            *n = '\n';
        }
    }
    else
    {
        // neveljaven vnos
        izpis(false);
        unici_niz(&*n);
    }
}

void nepredzancenost(int *n)
{

    int prva_stevka = getchar();

    if (prva_stevka >= '1' && prva_stevka <= '9')
    {
        // prva stevka je med 1-9
        odena_dodevet(n);
    }
    else if (prva_stevka == '0')
    {
        // prva stevka je 0s
        zacetek_nic(n);
    }
    else if (prva_stevka == '\n')
    {
        // konec niza
        *n = '\n';
    }
    else
    {
        // prva stevka je neveljavna
        izpis(false);
        unici_niz(n);
    }

}

int main()
{
    int n = 0;

    while (n != '\n')
    {
        nepredzancenost(&n);
    }

    return 0;
}
