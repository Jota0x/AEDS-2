#include "lista.h"

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    if (l == NULL)
        return;

    l->inicio = NULL;
    l->fim = NULL;

    return l;
}

void inserir_inicio(Lista *l, int val)
{
    // Lista nao existe
    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    // Lista vazia
    if (l->inicio == NULL)
        l->fim = nova;

    nova->prox = l->inicio;
    l->inicio = nova;
}

void inserir_pos(Lista *l, int val, int pos)
{

    // auxiliar de posicao
    int i = 1;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    // Lista vazia
    // Primeiro elemento
    if (l->inicio == NULL || pos <= 1)
    {
        nova->prox = l->inicio;
        l->inicio = nova;
        l->fim = nova;
        return;
    }

    Celula *aux = l->inicio;

    // loop principal
    // acha posicao
    while (aux->prox != NULL && i < pos - 1)
    {
        aux = aux->prox;
        i++;
    }

    nova->prox = aux->prox;
    aux->prox = nova;

    // Caso entre na ultima posicao
    if (nova->prox == NULL)
        l->fim = nova;
}

void inserir_fim(Lista *l, int val)
{
    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    // Lista vazia
    // Primeiro elemento
    if (l->inicio == NULL)
    {
        nova->prox = l->inicio;
        l->inicio = nova;
        l->fim = nova;
        return;
    }

    l->fim->prox = nova;
    l->fim = nova;
    nova->prox = NULL;
}

int remover_inicio(Lista *l)
{
    if (l == NULL || l->inicio == NULL)
        return -1;

    Celula *aux = l->inicio;

    l->inicio = l->inicio->prox;

    int valor = aux->dado;
    free(aux);

    return valor;
}

int remover_pos(Lista *l, int pos)
{
    if (l == NULL || l->inicio == NULL || pos < 1)
        return -1;

    if (pos == 1)
        remover_inicio(l);

    int i = 1;

    Celula *aux = l->inicio;
    Celula *remover;

    while (aux->prox != NULL && i < pos - 1)
    {
        aux = aux->prox;
        i++;
    }

    remover = aux->prox;
    int valor = remover->dado;
    aux->prox = remover->prox;

    free(remover);

    return valor;
}

int remover_fim(Lista *l)
{
    if (l == NULL && l->inicio == NULL)
        return -1;

    Celula *aux = l->inicio;

    while (aux->prox->prox != NULL)
        aux = aux->prox;

    Celula *remover = aux->prox;
    int valor = remover->dado;
    l->fim = aux;
    aux->prox == NULL;

    free(remover);

    return valor;
}