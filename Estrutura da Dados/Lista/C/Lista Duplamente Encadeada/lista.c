#include "lista.h"

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    if (l == NULL)
        return;

    l->inicio = NULL;
    l->fim = NULL;
}

void inserir_inicio(Lista *l, int val)
{
    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;
    nova->ant = NULL;
    nova->prox = l->inicio;

    // Lista vazia
    if (l->fim == NULL)
    {
        l->fim = nova;
        return;
    }

    l->inicio->ant = nova;
    l->inicio = nova;
}

void inserir_fim(Lista *l, int val)
{
    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    if (l->inicio == NULL)
    {
        nova->prox = l->inicio;
        l->inicio = nova;
        l->fim = nova;
        return;
    }

    l->fim->prox = nova;
    nova->ant = l->fim;
    l->fim = nova;
}

int remover_inicio(Lista *l)
{
    if (l == NULL && l->inicio == NULL)
        return;

    Celula *aux = l->inicio;

    l->inicio = l->inicio->prox;

    // Trata lista com unico elemento
    if (l->inicio    != NULL)
        l->inicio->ant = NULL;
    else
        l->fim = NULL;

    int valor = aux->dado;

    free(aux);
    return valor;
}

int remover_fim(Lista *l)
{
    if (l == NULL || l->inicio == NULL)
        return;

    Celula *aux = l->fim;

    l->fim = l->fim->ant;

    // Trata lista com unico elemento
    if (l->fim != NULL)
        l->fim->prox = NULL;
    else
        l->inicio = NULL;

    int valor = aux->dado;
    free(aux);

    return valor;
}