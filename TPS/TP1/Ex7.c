#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Essa questao e bizarra de dificil
int comprimentoMaiorSubstring(char *palavra);

int main()
{
    char *palavra = (char *)malloc(1000 * sizeof(char));

    while (scanf(" %[^\n]", palavra) == 1 && strcmp(palavra, "FIM") != 0)
    {

        printf("%d\n", comprimentoMaiorSubstring(palavra));
    }

    free(palavra);

    return 0;
}

int comprimentoMaiorSubstring(char *palavra)
{

    int maiorComprimento = 0;
    int inicioJanela = 0;
    int ultimaPosicao[256];

    for (int i = 0; i < 256; i++)
        ultimaPosicao[i] = -1;

    for (int fimJanela = 0; palavra[fimJanela] != '\0'; fimJanela++)
    {
        unsigned char caractereAtual = (unsigned char)palavra[fimJanela];

        if (ultimaPosicao[caractereAtual] >= inicioJanela)
        {
            inicioJanela = ultimaPosicao[caractereAtual] + 1;
        }

        ultimaPosicao[caractereAtual] = fimJanela;

        int tamanhoAtual = fimJanela - inicioJanela + 1;
        if (tamanhoAtual > maiorComprimento)
        {
            maiorComprimento = tamanhoAtual;
        }
    }
    return maiorComprimento;
}