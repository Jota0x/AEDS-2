#include "fila.h"

Fila *newFila(int tam)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    if (f == NULL)
        return NULL;

    f->fim = -1;
    f->dados = (int *)malloc(tam * sizeof(int));
    f->capacidade = tam;

    return f;
}

bool isFull(Fila *f)
{
    if (f->fim == f->capacidade - 1)
        return true;
    else
        return false;
}

bool isEmpty(Fila *f)
{
    if (f->fim == -1)
        return true;
    else
        return false;
}

void adicinar(Fila *f,int valor)
{
    if (!isFull(f))
    {
        f->fim++;
        f->dados[f->fim] = valor;
    }
    else
        printf("Fila cheia\n");
}

void removerInicio(Fila *f)
{
    if (!isEmpty(f))
    {

        for (int i = 0; i < f->fim; i++)
            f->dados[i] = f->dados[i + 1];

        f->fim--;
    }
    else
        printf("Fila vazia\n");
}

void freeFila(Fila *f)
{
    free(f->dados);
    free(f);
}
