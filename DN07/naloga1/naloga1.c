#include <stdio.h>
#include <stdlib.h>

int globina(int **pari, int index)
{
    int globinaL = 0;
    int globinaD = 0;

    if (pari[index][0] == 0 && pari[index][1] == 0)
        return 0;

    if (pari[index][0] != 0)
        globinaL = 1 + globina(pari, index + pari[index][0]);

    if (pari[index][1] != 0)
        globinaD = 1 + globina(pari, index + pari[index][1]);

    if (globinaL > globinaD)
        return globinaL;
    return globinaD;
}

int **pariArray(int size)
{
    int **newArray = (int **)malloc(size * sizeof(int *));

    for (int i = 0; i < size; i++)
    {
        newArray[i] = (int *)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < size; i++)
    {
        for (int y = 0; y < 2; y++)
        {
            scanf("%d", &newArray[i][y]);
        }
    }

    return newArray;
}

void printArray(int size, int **array)
{

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < 2; y++)
        {
            printf("%d ", array[x][y]);
        }
        printf("\n");
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int **pari = pariArray(n);

    printf("%d", globina(pari, 0));
    
    return 0;
}