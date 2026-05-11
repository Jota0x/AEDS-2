#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{

    int dado;
    struct Celula *dir, *esq, *sup, *inf;

} Celula;

typedef struct Matriz
{

    int linhas, colunas;
    Celula *inicio;
} Matriz;

Celula *buscaElemento(Matriz *m, int val)
{
    Celula *aux = m->inicio;
    Celula *sentinela = aux;

    for (int i = 0; i < m->linhas; i++)
    {
        aux = sentinela;

        for (int j = 0; j < m->colunas; j++)
        {
            if (aux->dado == val)
                return aux;

            aux = aux->dir;
        }

        sentinela = sentinela->inf;
    }

    return NULL;
}
