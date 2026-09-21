#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    if (l == NULL)
        return NULL;

    l->inicio = NULL;
    l->fim = l->inicio;

    return l;
}

Node *criar_celula(int valor)
{
    Node *node = (Node *)malloc(sizeof(Node));

    if (node == NULL)
        return NULL;

    node->dado = valor;
    node->prox = NULL;

    return node;
}

void adicionar_inicio(Lista *l, int valor)
{
    Node *node = criar_celula(valor);

    node->prox = l->inicio;
    l->inicio = node;

    if (l->fim == NULL)
        l->fim = node;
}

void adicionar_fim(Lista *l, int valor)
{
    Node *node = criar_celula(valor);

    l->fim->prox = node;
    l->fim = node;

    if (l->inicio == NULL)
    {
        l->inicio = node;
        l->fim = node;
    }
}

void remover_inicio(Lista *l)
{
    if (l->inicio == NULL)
        l->fim = NULL;
    else
    {
        Node *node = l->inicio;
        l->inicio = l->inicio->prox;

        free(node);
    }
}

void remover_fim(Lista *l)
{
    if (l->fim == NULL)
        return;
    else
    {
        Node *node = l->inicio;

        while (node->prox != l->fim)
            node = node->prox;
        
        free(l->fim);
        l->fim = node;
    }
}

void mostrar(Lista *l)
{
    Node *node = l->inicio;

    while(node != NULL)
    {
       printf("%d ",node->dado);
        node = node->prox;
    }
}

void deletar(Lista *l)
{
    Node *node = l->inicio;

    while(node != NULL)
    {
        l->inicio = l->inicio->prox;
        free(node);
        node = l->inicio;
    }

    free(l->inicio);
    free(l->fim);
    free(l);
}