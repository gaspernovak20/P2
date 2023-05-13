#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 50000000

static int array[M] = {};

void vnos_zaporedja(int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

int *put_in_order(int n, int size)
{

    int *ordered_array = (int *)calloc((size + 1), sizeof(int));

    if (ordered_array == NULL)
        exit(1);

    for (int i = 0; i < n; i++)
    {
        ordered_array[array[i]]++;
    }

    return ordered_array;
}

void izpis(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

long stetje_parov(int *array, int size, int k)
{
    long st_parov = 0;

    for (int i = 1; i <= (k - i); i++)
    {

        if (i == (k - i))
        {
            for (long plus = (long)(array[i] - 1) ; plus > 0; plus--)
            {
                st_parov += plus;
            }
        }
        else
        {
            st_parov += (long)(array[i]) * (long)(array[k - i]);
        }
    }

    return st_parov;
}

int main()
{

    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    vnos_zaporedja(n);

    int biggest_int = array[n - 1];

    int *ordered_array = put_in_order(n, biggest_int);

    long st_parov = stetje_parov(ordered_array, biggest_int, k);
    printf("%ld\n", st_parov);

    return 0;
}