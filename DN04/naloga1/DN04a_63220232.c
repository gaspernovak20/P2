#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool zamik(int *p_prva, int indeks, int *p_druga, int velikost)
{
    int i = 0;
    int j = indeks;

    while (i < velikost)
    {

        if (p_prva[j] != p_druga[i])
        {
            return false;
        }

        i++;
        j++;

        if (j >= velikost)
        {
            j = j - velikost;
        }
    }

    return true;
}

int *vnos_zaporedja(int size)
{

    int *p_zaporedje = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", p_zaporedje + i);
    }

    return p_zaporedje;
}

void izpis(int *p_zacetek, int velikos)
{

    for (int i = 0; i < velikos; i++)
    {
        printf("%d", p_zacetek[i]);
    }
}

int main()
{

    int n = 0;

    scanf("%d", &n);

    int *p_prvo = vnos_zaporedja(n);

    int *p_drugo = vnos_zaporedja(n);

    // izpis(p_prvo, n);

    bool pravilnost_zamika = false;

    for (int j = 0; j < n; j++)
    {

        if (*p_drugo == p_prvo[j])
        {
            pravilnost_zamika = zamik(p_prvo, j, p_drugo, n);
        }

        if (pravilnost_zamika)
        {
            printf("%d", j);
            break;
        }
    }

    return 0;
}
