#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista *criar_lista()
{
    Lista *l = (Lista*)malloc(sizeof(Lista));

    if(l == NULL)
        return NULL;

    l->inicio = NULL;
    l->fim = l->inicio;

    return l;

}

Node *criar_celula(int valor)
{
    Node *node = (Node*)malloc(sizeof(Node));

    if(node == NULL)
        return NULL;

    node->dado = valor;

    return node;
}

void adicionar_inicio(Lista *l, int valor)
{
    Node *node = cria_celula(valor);
    
    node->prox = l->inicio;
    l->inicio = node;

    if(l->fim == NULL)
        l->fim = node;

}

void adicionar_fim(Lista *l, int valor)
{
    Node *node = criar_celula(valor);

    l->fim->prox = node;
    l->fim = node;

    if(l->inicio == NULL)
        l->inicio = node;

}

void adicionar_posicao(Lista *l, int valor, int posicao)
{
    Node *node = criar_celula(valor);

    if(l->inicio == NULL || l->fim == NULL)
    {
        l->inicio = node;
        l->fim = l->inicio;
    }

    Node *aux = l->inicio;
    int posicao = 1;

    while(aux != NULL || posicao != aux)
    {
        Node *ant = aux;
        aux = aux->prox;

        

        posicao++;
    }

}