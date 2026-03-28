#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagrama(char *palavra);

int main()
{
    char *palavra = (char *)malloc(100 * sizeof(char));

    while (scanf(" %[^\n]", palavra) && strcmp(palavra, "FIM") != 0)
    {
        if (isAnagrama(palavra))
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    free(palavra);

    return 0;
}

bool isAnagrama(char *palavra)
{
    int fim = strlen(palavra) - 1;

    for (int i = 0; i < fim / 2; i++)
    {
        if (palavra[i] != palavra[fim])
            return false;

        fim--;
    }

    return true;
}