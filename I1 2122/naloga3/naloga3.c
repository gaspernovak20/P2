
/*
Ro"cno testiranje (npr. za primer test01.in):

gcc naloga3.c
./a.out < test01.in

Samodejno testiranje:

export name=naloga3
make test

Testni primeri:

test01: primer iz besedila
test02..test08: "se nekaj dodatnih testov

.in: testni vhod
.outA: pri"cakovani izhod (poljubna permutacija vrstic je tudi v redu)
.outB: pri"cakovani izhod za 0.6 to"cke (poljubna permutacija vrstic je tudi v redu)
.outC: pri"cakovani izhod za 0.3 to"cke (poljubna permutacija vrstic je tudi v redu)
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

void izpisi(char *izpis, int length)
{
    bool st = false;
    bool c_m = false;
    bool c_v = false;

    for (int i = 0; i < length; i++)
    {
        char znak = izpis[i];

        if ('0' <= znak && znak <= '9')
        {
            st = true;
        }
        if ('a' <= znak && znak <= 'z')
        {
            c_m = true;
        }
        if ('A' <= znak && znak <= 'Z')
        {
            c_v = true;
        }
    }

    if (st && c_m && c_v)
    {
        printf("%s\n", izpis);
    }
    return;
}

void rek(int d, char *string, int n, char *izpis, int i_input, int i_output)
{

    if (n == i_input)
    {
        izpisi(izpis, n);
        return;
    }
    else if (i_output < d)
    {
        izpis[i_input] = string[i_output];

        rek(d, string, n, izpis, (i_input + 1), 0);
        izpis[(i_input + 1)] = 0;
        rek(d, string, n, izpis, i_input, (i_output + 1));
    }

    return;
}

int main()
{
    // dopolnite ...

    int d;
    scanf("%d ", &d);

    char *string = (char *)malloc(d * sizeof(char));
    scanf("%s ", string);

    int n;
    scanf("%d", &n);

    char *izpis = (char *)calloc(n, sizeof(char));

    rek(d, string, n, izpis, 0, 0);

    return 0;
}
