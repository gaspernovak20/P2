
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int kombinacije(int koncna_vsota, int m, int a, int vsota)
{
    int kom = 0;

    if (vsota > koncna_vsota)
    {
        return 0;
    }
    else if (vsota == koncna_vsota)
    {
        return 1;
    }
    else
    {
        for (int b = m; b <= koncna_vsota; b++)
        {

            if (a < b)
            {
                kom += kombinacije(koncna_vsota, m, 1, (vsota + a * b));
            }
        }
        if ((a + 1) < koncna_vsota)
        {
            kom += kombinacije(koncna_vsota, m, a + 1, vsota);
        }
        return kom;
    }
}

int main()
{
    // dopolnite ...

    int n, m;

    scanf("%d %d", &n, &m);

    int st_kombinacij = kombinacije(n, m, 1, 0);

    printf("%d", st_kombinacij);

    return 0;
}
