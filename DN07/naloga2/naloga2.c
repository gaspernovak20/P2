#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vse_mozne(int n, char **array, char *izpis, int zapis_index, int string_index, int char_index)
{

    if (zapis_index == n)
    {
        printf("%s\n", izpis);
        return;
    }
    else if ( string_index < n && char_index < strlen(array[string_index]))
    {   
        izpis[zapis_index] = array[string_index][char_index];
        vse_mozne(n, array, izpis, zapis_index + 1, string_index + 1, 0);
        vse_mozne(n, array, izpis, zapis_index, string_index, char_index + 1);
    }

    return;
}

void print(char **tabela, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", tabela[i]);
    }
}

void free_table(char **table, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(table[i]);
    }

    free(table);
}

int main()
{

    int n;
    scanf("%d", &n);

    char **array = (char **)malloc(n * sizeof(char *));
    char *izpis = (char *)calloc(n, sizeof(char));

    for (int i = 0; i < n; i++)
    {
        array[i] = (char *)calloc(42, sizeof(char));

        scanf("%s", array[i]);
    }

    vse_mozne(n, array, izpis, 0, 0, 0);

    free_table(array, n);

    return 0;
}