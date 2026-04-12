#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo funcao
void ciframento(char *palavra, int tam);

int main()
{
    char *palavra = (char *)malloc(1000 * sizeof(char));

    while (scanf(" %[^\n]", palavra) && strcmp(palavra, "FIM") != 0)
    {
        int tam = strlen(palavra) - 1;

        ciframento(palavra, tam);
        printf("\n");
    }

    free(palavra);

    return 0;
}

// Ciframento recursivo
void ciframento(char *palavra, int tam)
{
    if (tam < 0)
        return;

    ciframento(palavra, tam - 1);

    printf("%c", palavra[tam] + 3);
}
