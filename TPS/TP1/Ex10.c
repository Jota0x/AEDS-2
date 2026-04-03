#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    return 0;
}

bool isVogal(char *palavra, int tam)
{
    if (tam < 0)
        return true;

    if (palavra[tam] != 'a' || palavra[tam] != 'e' || palavra[tam] != 'i' || palavra[tam] != 'o' || palavra[tam] != 'u')
        return false;
    else
        return isVogal(palavra, tam - 1);
}

bool isConsoante(char *palavra, int tam)
{
    if (tam < 0)
        return true;

    if (palavra[tam] == 'a' || palavra[tam] == 'e' || palavra[tam] == 'i' || palavra[tam] == 'o' || palavra[tam] == 'u')
        return false;
    else
        return isConsoante(palavra, tam - 1);
}

bool isInteiro(char *palavra, int tam)
{
    if (tam < 0)
        return true;

    if (palavra[tam] > 9 || palavra[tam] < 0)
        return false;
    else
        return isInteiro(palavra, tam - 1);
}

bool isReal()
