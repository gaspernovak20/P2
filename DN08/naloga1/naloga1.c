#include <stdio.h>
#include <stdlib.h>

void polnjenje_tabele(int *tabele, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tabele[i]);
    }

    return;
}

void print_table(int *table, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", table[i]);
    }
    printf("\n");

    return;
}

int main(int argc, char const *argv[])
{

    int n, k, r;

    scanf("%d %d %d", &n, &k, &r);

    int *tabela = (int *)malloc(n * sizeof(int));
    if(tabela == NULL) exit(1);

    polnjenje_tabele(tabela, n);


    return 0;
}
