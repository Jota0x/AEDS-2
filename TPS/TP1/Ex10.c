#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isVogal(char *palavra, int tam);
bool isConsoante(char *palavra, int tam);
bool isInteiro(char *palavra, int tam);
bool isReal(char *palavra, int tam, int aux);

int main()
{
    char *palavra = (char *)malloc(1000 * sizeof(char));

    while (scanf(" %[^\n]", palavra) && strcmp(palavra, "FIM") != 0)
    {

        int tam = strlen(palavra);

        if (isVogal(palavra, tam))
            printf("SIM ");
        else
            printf("NAO ");

        if (isConsoante(palavra, tam))
            printf("SIM ");
        else
            printf("NAO ");

        if (isInteiro(palavra, tam))
            printf("SIM ");
        else
            printf("NAO ");

        if (isReal(palavra, tam, 0))
            printf("SIM\n");
        else
            printf("NAO\n");

    }

    free(palavra);

    return 0;
}

bool isVogal(char *palavra, int tam)
{
    if (tam < 0)
        return true;

    if (!(palavra[tam] == 'a' || palavra[tam] == 'e' || palavra[tam] == 'i' || palavra[tam] == 'o' || palavra[tam] == 'u' ||
          palavra[tam] == 'A' || palavra[tam] == 'E' || palavra[tam] == 'I' || palavra[tam] == 'O' || palavra[tam] == 'U'))
        return false;

    return isVogal(palavra, tam - 1);
}

bool isConsoante(char *palavra, int tam)
{
    if (tam < 0)
        return true;

    if (!((palavra[tam] >= 'a' && palavra[tam] <= 'z') || (palavra[tam] >= 'A' && palavra[tam] <= 'Z')))
        return false;

    if (palavra[tam] == 'a' || palavra[tam] == 'e' || palavra[tam] == 'i' || palavra[tam] == 'o' || palavra[tam] == 'u' ||
        palavra[tam] == 'A' || palavra[tam] == 'E' || palavra[tam] == 'I' || palavra[tam] == 'O' || palavra[tam] == 'U')
        return false;

    return isConsoante(palavra, tam - 1);
}

bool isInteiro(char *palavra, int tam)
{
    if (tam < 0)
        return true;

    if (palavra[tam] > '9' || palavra[tam] < '0')
        return false;

    return isInteiro(palavra, tam - 1);
}

bool isReal(char *palavra, int tam, int aux)
{
    if (tam < 0)
        return true;

    if (palavra[tam] == '.' || palavra[tam] == ',')
    {
        aux++;
        if (aux > 1)
            return false;
        return isReal(palavra, tam - 1, aux);
    }

    if (palavra[tam] < '0' || palavra[tam] > '9')
        return false;

    return isReal(palavra, tam - 1, aux);
}
