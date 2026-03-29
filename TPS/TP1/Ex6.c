#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isAnagrama(char *palavra1, char *palavra2);
char *ordena(char *palavra);

int main()
{
    char *palavra1 = (char *)malloc(100 * sizeof(char));
    char *palavra2 = (char *)malloc(100 * sizeof(char));

    while (scanf("%s%s", palavra1, palavra2) && (strcmp(palavra1, "FIM") != 0 || strcmp(palavra2, "FIM") != 0))
    {
        ordena(palavra1);
        ordena(palavra2);

        if (isAnagrama(palavra1, palavra2))
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}

// Verifica anagrama
bool isAnagrama(char *palavra1, char *palavra2)
{
    if (strlen(palavra1) != strlen(palavra2))
        return false;

    for (int i = 0; i < strlen(palavra1); i++)
        if (palavra1[i] != palavra2[i])
            return false;

    return true;
}

// Ordena palavra para verificacao
char *ordena(char *palavra)
{

    char aux;

    for (int i = 0; i < strlen(palavra); i++)
        for (int j = i + 1; j < strlen(palavra); j++)
            if (palavra[i] > palavra[j])
            {
                aux = palavra[i];
                palavra[i] = palavra[j];
                palavra[j] = aux;
            }

    return palavra;
}
