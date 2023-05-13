#include <stdio.h>
#include <stdbool.h>

void od1_do9();

void nic();

void minus_plus();

void izpis(bool rez);

void predznacena_desetiska_konstanta(int *x);

int main()
{
    int x = 0;

    while (x != '\n')
    {
        predznacena_desetiska_konstanta(&x);
    }

    return 0;
}

void predznacena_desetiska_konstanta(int *x)
{
    int prvi_znak = getchar();

    if (prvi_znak == '0')
    {
        nic();
    }
    else if (prvi_znak >= '1' && prvi_znak <= '9')
    {
        od1_do9();
    }
    else if (prvi_znak == '+' || prvi_znak == '-')
    {
        minus_plus();
    }
    else if (prvi_znak = '\n')
    {
        *x = '\n';
    }
    else
    {
        izpis(false);
    }
}

void izpis(bool rez)
{
    if (rez)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}

void nic()
{
    bool veljavnost = true;
    int x = getchar();

    while (x != ' ' && x != '\n')
    {
        if (x != ' ')
        {
            veljavnost = false;
        }
        x = getchar();
    }

    izpis(veljavnost);
}

void od1_do9()
{

    bool veljavnost = true;
    int x = getchar();

    while (x != ' ' && x != '\n')
    {
        if (x < '0' || x > '9')
        {
            veljavnost = false;
        }
        x = getchar();
    }

    izpis(veljavnost);
}

void minus_plus()
{
    int x = getchar();

    if (x == '0')
    {
        nic();
    }
    else if (x >= '1' && x <= '9')
    {
        od1_do9();
    }
    else if (x == ' ')
    {
        izpis(false);
    }
    else
    {
        while (x != ' ')
        {
            x = getchar();
        }

        izpis(false);
    }
}
