#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverte(char *palavra);

int main()
{
    char *palavra = (char *)malloc(100 * sizeof(char));

    while (scanf(" %[^\n]", palavra) && strcmp(palavra, "FIM") != 0)
        inverte(palavra);

    free(palavra);

    return 0;
}

// inverte string
void inverte(char *palavra)
{
    char newPalavra[strlen(palavra) + 1];
    int aux = 0;

    // loop principal
    for (int i = strlen(palavra) - 1; i >= 0; i--)
    {
        newPalavra[aux] = palavra[i];
        aux++;
    }

    // fecha String
    newPalavra[aux] = '\0';

    printf("%s\n", newPalavra);
}