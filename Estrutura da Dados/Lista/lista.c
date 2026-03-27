#include "lista.h"

Lista *newLista(int tam)
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    if (l == NULL)
        return NULL;

    l->fim = -1;
    l->dados = (int *)malloc(tam * sizeof(int));
    l->tam = tam;

    return l;
}

bool isEmpty(Lista *l)
{
    if (l->fim == -1)
        return true;
    else
        return false;
}

bool isFull(Lista *l)
{
    if (l->fim == l->tam - 1)
        return true;
    else
        return false;
}

void adicionarInicio(Lista *l, int val)
{
    if (!isFull(l))
    {
        l->fim++;
        for (int i = l->fim; i > 0; i--)
            l->dados[i] = l->dados[i - 1];

        l->dados[0] = val;
    }
    else
        printf("Lista cheia\n");
}

void adicionarPos(Lista *l, int pos, int val)
{
    if (!isFull(l) && (pos >= 0 && pos < l->tam))
    {
        l->fim++;
        for (int i = l->fim; i > pos; i--)
            l->dados[i] = l->dados[i - 1];

        l->dados[pos] = val;
    }
    else
        printf("Lista cheia\n");
}

void adicionarFim(Lista *l, int val)
{
    if (!isFull(l))
    {
        l->fim++;
        l->dados[l->fim] = val;
    }
    else
        printf("Lista cheia\n");
}

void removerInicio(Lista *l)
{
    if (!isEmpty(l))
    {
        for (int i = 0; i < l->fim; i++)
            l->dados[i] = l->dados[i + 1];

        l->fim--;
    }
    else
        printf("Lista vazia\n");
}

void removerPos(Lista *l, int pos)
{
    if (!isEmpty(l))
    {
        for (int i = pos; i < l->fim; i++)
            l->dados[i] = l->dados[i + 1];

        l->fim--;
    }
    else
        printf("Lista vazia\n");
}

void removerFim(Lista *l)
{
    if (!isEmpty(l))
    {
        l->fim--;
    }
    else
        printf("Lista vazia\n");
}

void freeLista(Lista *l)
{
    free(l->dados);
    free(l);
}