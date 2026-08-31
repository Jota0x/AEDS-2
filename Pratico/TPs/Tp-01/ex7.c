#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int comprimentoMaiorSubstring(char *palavra);
bool temRepetido(char *palavra, int inicio, int fim);
int ehFim(char *str);

int main()
{
    char *palavra = (char *)malloc(1000 * sizeof(char));

    scanf(" %[^\n]", palavra);

    while (!ehFim(palavra))
    {
        printf("%d\n", comprimentoMaiorSubstring(palavra));
        scanf(" %[^\n]", palavra);
    }

    free(palavra);

    return 0;
}

// Verifica fim
int ehFim(char *str)
{
    if (strlen(str) != 3)
        return 0;

    if (str[0] == 'F' && str[1] == 'I' && str[2] == 'M')
        return 1;

    return 0;
}

// Verifica se ha caractere repetido entre as posicoes inicio e fim
bool temRepetido(char *palavra, int inicio, int fim)
{
    for (int i = inicio; i <= fim; i++)
        for (int j = i + 1; j <= fim; j++)
            if (palavra[i] == palavra[j])
                return true;

    return false;
}

int comprimentoMaiorSubstring(char *palavra)
{
    int tam = strlen(palavra);
    int maiorComprimento = 0;

    for (int inicio = 0; inicio < tam; inicio++)
    {
        bool jaTemRepetido = false;

        for (int fim = inicio; fim < tam && !jaTemRepetido; fim++)
        {
            if (!temRepetido(palavra, inicio, fim))
            {
                int tamanhoAtual = fim - inicio + 1;
                if (tamanhoAtual > maiorComprimento)
                    maiorComprimento = tamanhoAtual;
            }
            else
            {
                jaTemRepetido = true;
            }
        }
    }

    return maiorComprimento;
}