#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista *criar_lista()
{
    Lista *l = (int *)malloc(MAX * sizeof(int));

    if (l == NULL)
        return NULL;

    l->tam = -1;

    return l;
}

void deletar(Lista *l)
{
    free(l);
}

void inserir_inicio(Lista *l, int val)
{
    if (l->tam >= MAX - 1)
        return;
    else
    {
        for (int i = l->tam; i > 0; i--)
            l->dado[i] = l->dado[i - 1];

        l->dado[0] = val;
    }

    l->tam++;
}

void inserir_fim(Lista *l, int val)
{
    if (l->tam >= MAX - 1)
        return;
    else
    {
        l->tam++;
        l->dado[l->tam] = val;
    }
}

void inserir(Lista *l, int val, int posicao)
{
    if (l->tam >= MAX - 1)
        return;
    if (posicao < 0 || posicao > l->tam)
        return;
    else
    {
        for (int i = l->tam; i > posicao; i--)
            l->dado[i] = l->dado[i - 1];

        l->dado[posicao] = val;
        l->tam++;
    }
}