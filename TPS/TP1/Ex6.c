#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isAnagrama(char *palavra1, char *palavra2);
void ordena(char *palavra);
void minusculo(char *palavra);

int main()
{
    char *palavra1 = (char *)malloc(1000 * sizeof(char));
    char *palavra2 = (char *)malloc(1000 * sizeof(char));

    while (scanf("%s %s", palavra1, palavra2) == 2 && strcmp(palavra1, "FIM") != 0)
    {
        minusculo(palavra1);
        minusculo(palavra2);

        ordena(palavra1);
        ordena(palavra2);

        if (isAnagrama(palavra1, palavra2))
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    free(palavra1);
    free(palavra2);

    return 0;
}

// Verifica anagrama
bool isAnagrama(char *palavra1, char *palavra2)
{

    if (strlen(palavra1) != strlen(palavra2))
        return false;

    int tam = strlen(palavra1);

    for (int i = 0; i < tam; i++)
        if (palavra1[i] != palavra2[i])
            return false;

    return true;
}

// Ordena palavra para verificacao
void ordena(char *palavra)
{

    int tam = strlen(palavra);
    char aux;

    for (int i = 0; i < tam; i++)
        for (int j = i + 1; j < tam; j++)
            if (palavra[i] > palavra[j])
            {
                aux = palavra[i];
                palavra[i] = palavra[j];
                palavra[j] = aux;
            }
}

void minusculo(char *palavra)
{
    for (int i = 0; palavra[i] != '\0'; i++)
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {

            palavra[i] = palavra[i] + 32;
        }
}