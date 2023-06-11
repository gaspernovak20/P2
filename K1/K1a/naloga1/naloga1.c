
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//nipotrebno sm previru ce pravilno berem zaporedje
void izpis(int *zaporedje, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", zaporedje[i]);
    }

    return;
}

void polnjenje(int *zaporedje, int size)
{

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &zaporedje[i]);
    }

    // izpis(zaporedje, size);

    return;
}

void kognitivna_vsota(int *zaporedje, int size)
{

    int kognitivnost = true;
    int sum = 0;

    //previrjamo kognitivnos ter seštevamo vsoto zaporedja
    for (int i = 0; i < (size / 2); i++)
    {
        if (zaporedje[i] != zaporedje[((size - 1) - i)])
        {
            kognitivnost = false;
        }

        sum += zaporedje[i];
        sum += zaporedje[((size - 1) - i)];
    }

    //vsoti zaporedja prištejemo se sredinski člen če je zaporedje liho
    if (size % 2 != 0)
    {
        sum += zaporedje[(size / 2)];
    }

    // izpis rezultatov

    if (kognitivnost)
    {
        printf("DA\n");
    }
    else
    {
        printf("NE\n");
    }

    printf("%d", sum);

    return;
}

int main()
{
    // dopolnite ...

    int n;
    scanf("%d", &n);

    int *zaporedje = (int *)malloc(n * sizeof(int));

    polnjenje(zaporedje, n);

    kognitivna_vsota(zaporedje, n);

    free(zaporedje);

    return 0;
}
