#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void bubble(char *str);
void paraMinusculo(char *str);
bool isAnagrama(char *str1, char *str2);
int ehFim(char *str);

int main()
{
    char *palavra1 = (char *)malloc(1000 * sizeof(char));
    char *palavra2 = (char *)malloc(1000 * sizeof(char));

    scanf("%s", palavra1);

    while (!ehFim(palavra1))
    {
        scanf("%s", palavra2);

        paraMinusculo(palavra1);
        paraMinusculo(palavra2);

        bubble(palavra1);
        bubble(palavra2);

        if (isAnagrama(palavra1, palavra2))
            printf("SIM\n");
        else
            printf("NAO\n");

        scanf("%s", palavra1);
    }

    free(palavra1);
    free(palavra2);

    return 0;
}

// verifica fim
int ehFim(char str[])
{
    if (strlen(str) != 3)
        return 0;

    if (str[0] == 'F' && str[1] == 'I' && str[2] == 'M')
        return 1;

    return 0;
}

// Converte cada letra maiuscula para minuscula
void paraMinusculo(char *str)
{
    int tam = strlen(str);

    for (int i = 0; i < tam; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + ('a' - 'A');
    }
}

void bubble(char *str)
{
    int tam = strlen(str);

    for (int i = 0; i < tam; i++)
        for (int j = i + 1; j < tam; j++)
            if (str[i] > str[j])
            {
                char aux = str[i];
                str[i] = str[j];
                str[j] = aux;
            }
}

bool isAnagrama(char *str1, char *str2)
{
    if (strlen(str1) != strlen(str2))
        return false;

    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != str2[i])
            return false;
    }

    return true;
}