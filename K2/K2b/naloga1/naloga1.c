
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char **argv)
{
    // dopolnite ...

    FILE *inp = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    char *buffer = malloc(100000 * sizeof(char));
    size_t index = 0;

    bool nova_vrstica = true;
    char ch;

    while ((ch = getc(inp)) != EOF)
    {
        if (nova_vrstica && ch != ' ')
        {

            if (ch != '\n')
            {
                nova_vrstica = false;
            }

            buffer[index] = ch;
            index++;
        }
        else if (!nova_vrstica)
        {

            if (ch == '\n')
            {
                nova_vrstica = true;
            }

            buffer[index] = ch;
            index++;
        }
    }

    fprintf(out, "%s", buffer);

    free(buffer);

    return 0;
}
