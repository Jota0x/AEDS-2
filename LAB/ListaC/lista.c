#include "lista.h"

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    if (l == NULL)
        return;

    l->fim = NULL;
    l->inicio = NULL;

    return l;
}

void inserir_inicio(Lista *l, int val)
{
    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    if (l->fim == NULL)
        l->fim = nova;

    nova->prox = l->inicio;
    l->inicio = nova;
}

void inserir_fim(Lista *l, int val)
{

    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = nova;

    if (l->inicio == NULL)
    {
        nova->prox = l->inicio;
        l->inicio = nova = l->fim;
    }

    l->fim->prox = nova;
    l->fim = nova;
    nova->prox = NULL;
}

void inserirPos(Lista *l, int val, int pos)
{
    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    int i = 1;

    if (l->inicio == NULL)
    {
        nova->prox = l->inicio;
        l->inicio = nova = l->fim;
    }

    Celula *aux = l->inicio;

    while (aux != NULL && pos - 1 > i)
    {
        aux = aux->prox;
        i++;
    }

    nova->prox = aux->prox;
    aux->prox = nova;
}

void remover_inicio(Lista *l)
{
    if (l == NULL)
        return;
    if (l->inicio == NULL)
        return;

    Celula *aux = l->inicio;

    if (l->inicio == l->fim)
    {
        aux = l->inicio;
        l->inicio = l->fim = NULL;
        free(aux);
    }

    l->inicio = l->inicio->prox;
    free(aux);
}

void remover_fim(Lista *l)
{
    if (l == NULL)
        return;
    if (l->inicio == NULL)
        return;

    Celula *aux = l->inicio;

    if (l->inicio = l->fim)
    {
        l->inicio = l->fim = NULL;
        free(aux);
        return;
    }

    while (aux != l->fim)
        aux = aux->prox;

    l->fim = aux;
    aux = aux->prox;
    free(aux);
}

void removerPos(Lista *l, int val, int pos)
{
    if (l == NULL)
        return;
    if (l->inicio == NULL)
        return;

    Celula *aux = l->inicio;

    if (l->inicio = l->fim)
    {
        l->inicio = l->fim = NULL;
        free(aux);
        return;
    }

    int i = 1;
    Celula *anterior;

    while (aux != NULL && pos > i)
    {
        anterior = aux;
        aux = aux->prox;
        i++;
    }

    anterior->prox = aux->prox;
    free(aux);
}

void removerDuplicado(Lista *l)
{
    if (l == NULL)
        return;
    if (l->inicio == NULL)
        return;

    Celula *atual;
    Celula *anterior = l->inicio;

    while (anterior != NULL)
    {
        atual = anterior;
        atual = atual->prox;

        if (anterior->dado == atual->dado)
        {
            anterior->prox = atual->prox;
            free(atual);
        }
    }

}
