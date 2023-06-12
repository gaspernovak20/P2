
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool contains(char c, char *nadomestni)
{
    for (int i = 0; i < 6; i++)
    {
        if (c == nadomestni[i])
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char **argv)
{

    FILE *inp = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    char *buffer = malloc(100000 * sizeof(char));
    char *nadomestni = "CcSsZz";

    size_t index = 0;

    char prev = fgetc(inp);
    char next;

    bool change = false;

    while ((next = fgetc(inp)) != EOF)
    {
        if (!change)
        {
            if (prev == '"' && contains(next, nadomestni))
            {
                buffer[index] = next;
                index++;
                change = true;
            }
            else
            {
                buffer[index] = prev;
                index++;
            }
        }
        else
        {
            change = false;
        }

        prev = next;
    }

    fprintf(out, "%s", buffer);
    
    //fwrite(buffer, sizeof(char) , index ,out);

    fclose(inp);
    fclose(out);

    return 0;
}
