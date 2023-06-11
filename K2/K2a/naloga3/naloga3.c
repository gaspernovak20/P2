
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02--06: y = 0, koordinate x nara"s"cajo
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

void izpisPoti(int *pot, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", pot[i]);
        if (i != (size - 1))
        {
            printf("->");
        }
    }
    printf("\n");
    return;
}

int razdalja_med_tockama(int *a, int *b)
{
    // int razdalja = ((a[0] - b[0]) * (a[0] - b[0])) + ((a[1] - b[1]) * (a[1] - b[1]));

    int razdalja = ((b[0] - a[0]) * (b[0] - a[0])) + ((b[1] - a[1]) * (b[1] - a[1]));
    return razdalja;
}

void rek(int stKordinat, int maxPot, int **kordinate, int *pot, int prejsnjaRazdalja, int index)
{

    if ((stKordinat - 1) == pot[index - 1])
    {
        izpisPoti(pot, index);
        return;
    }

    for (int i = 1; i < stKordinat; i++)
    {
        int pot_do_i = razdalja_med_tockama(kordinate[pot[index - 1]], kordinate[i]);
        int razdalja_cilj = razdalja_med_tockama(kordinate[i], kordinate[(stKordinat - 1)]);

        // printf("i:%d, prejsni: %d ,pot:%d, prejsnaPot:%d, r:%d\n", i, pot[index - 1], pot_do_i, prejsnjaRazdalja, razdalja_cilj);

        if (razdalja_cilj < prejsnjaRazdalja && pot_do_i <= maxPot)
        {
            pot[index] = i;
            // printf("i: %d\n", pot[index]);
            rek(stKordinat, maxPot, kordinate, pot, razdalja_cilj, index + 1);
        }
    }
    pot[index] = 0;
    return;
}

int main()
{
    // dopolnite ...

    int n, k;

    scanf("%d\n", &n);
    scanf("%d\n", &k);

    int **kordinate = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        kordinate[i] = (int *)malloc(2 * sizeof(int));

        scanf("%d %d", &kordinate[i][0], &kordinate[i][1]);
    }

    int *pot = (int *)calloc(n, sizeof(int));

    rek(n, (k * k), kordinate, pot, razdalja_med_tockama(kordinate[0], kordinate[(n - 1)]), 1);

    return 0;
}
