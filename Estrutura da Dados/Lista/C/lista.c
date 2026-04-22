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

void destruir_lista(Lista *l)
{
    if (l == NULL)
        return;

    Celula *aux;

    while (l->inicio != NULL && l->fim != NULL)
    {
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
}

void adicionar_inicio(Lista *l, int val)
{
    // Lista nao existe
    if (l == NULL)
        return;

    // cria nova celula
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    if (l->inicio == NULL)
        l->fim = nova;

    nova->prox = l->inicio;
    l->inicio = nova;
}

void adicionar_fim(Lista *l, int val)
{
    if (l == NULL)
        return;

    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->dado = val;

    // Lista vazia
    if (l->inicio == NULL)
    {
        nova->prox = l->inicio;
        l->inicio = nova;
        l->fim = nova;
    }

    l->fim->prox = nova;
    nova->prox = NULL;
}

void adicionar_ordenado(Lista *l, int val)
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
    }

    Celula *aux = l->inicio;

    while (aux->prox != NULL && aux->dado < val)
        aux = aux->prox;

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

    while (aux->prox != l->fim)
        aux = aux->prox;

    l->fim = aux;
    aux = aux->prox;
    free(aux);
}

void remover_posicao(Lista *l, int pos)
{
    if (l == NULL)
        return;
    if (l->inicio == NULL)
        return;

    int i = 1;

    Celula *aux = l->inicio;

    while (aux->prox != NULL && pos - 1 > i)
    {
        aux = aux->prox;
        i++;
    }

    // Remove celula
    Celula *remover = aux->prox;
    aux = aux->prox->prox;
    free(remover);
}

int quantidade_itens(Lista *l)
{
    Celula *aux = l->inicio;
    int quantidade = 0;

    while (aux != l->fim)
    {
        aux = aux->prox;
        quantidade++;
    }

    return quantidade;
}

void imprimir_lista(Lista *l)
{
    Celula *aux = l->inicio;

    for(int i = 0; i < quantidade_itens(l); i++)
    {
        printf("%d ",aux->dado);
        aux = aux->dado;
    }

}
