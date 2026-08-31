#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isVogal(char *palavra, int tam);
bool isConsoante(char *palavra, int tam);
bool isInteiro(char *palavra, int tam);
bool isReal(char *palavra, int tam, int aux);
bool ehFim(char *palavra);

int main()
{
    char *palavra = (char *)malloc(1000 * sizeof(char));

    scanf(" %[^\n]", palavra);

    while (!ehFim(palavra))
    {
        int tam = strlen(palavra) - 1;

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

        scanf(" %[^\n]", palavra);
    }

    free(palavra);
    return 0;
}

// Verifica FIM
bool ehFim(char *palavra)
{
    if (strlen(palavra) != 3)
        return false;

    return palavra[0] == 'F' && palavra[1] == 'I' && palavra[2] == 'M';
}

// Verifica Vogal
bool isVogal(char *palavra, int tam)
{
    if (tam < 0)
        return true;
    if (!(palavra[tam] == 'a' || palavra[tam] == 'e' || palavra[tam] == 'i' || palavra[tam] == 'o' || palavra[tam] == 'u' ||
          palavra[tam] == 'A' || palavra[tam] == 'E' || palavra[tam] == 'I' || palavra[tam] == 'O' || palavra[tam] == 'U'))
        return false;
    return isVogal(palavra, tam - 1);
}

// Verifica Consoante
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

// Verifica Inteiro
bool isInteiro(char *palavra, int tam)
{
    if (tam < 0)
        return true;
    if (palavra[tam] > '9' || palavra[tam] < '0')
        return false;
    return isInteiro(palavra, tam - 1);
}

// Verifica Real
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