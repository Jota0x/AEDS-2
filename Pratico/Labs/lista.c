#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble(char noems[][100], int n);

int main()
{
    int n;

    scanf("%d", &n);
    char nomes[n][100];
    char letra;
    int comportado, nComportado;

    for (int i = 0; i < n; i++)
    {
        scanf(" %c%s", letra, nomes);
        if (letra == '+')
            comportado++;
        else
            nComportado++;
    }

    bubble(nomes, n);

    for (int i = 0; i < n; i++)
    {   
        printf("%s\n", i + 1);
        nomes[i];
    }
    printf("Se comportaram: %d | Nao se comportam: %d",comportado,nComportado);

}

void bubble(char nomes[][100], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)

            if (strcmp(nomes[i], nomes[j]) > 0)
            {
                char aux[100];
                strcpy(aux, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], aux);
            }
}
