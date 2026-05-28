#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

No *criar_no(int val)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
        return NULL;

    novo->dado = val;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 0;

    return novo;
}

Arvore *cria_arvore()
{

    Arvore *a = (Arvore *)malloc(sizeof(Arvore));

    if (a == NULL)
        return NULL;

    a->raiz = NULL;

    return a;
}

/* -- Funções Auxiliares -- */
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int altura(No *no)
{
    if (no == NULL)
        return NULL;
    else
        return no->altura;
}

int fator_balancemanto(No *no)
{
    if (no == NULL)
        return NULL;

    return altura(no->dir) - altura(no->esq);
}

void atualiza_altura(No *no)
{
    if (no == NULL)
        return;

    no->altura = 1 + max(altura(no->dir), altura(no->esq));
}

/* -- Rotações -- */
No *rotacao_direita(No *no)
{

    No *nova_raiz = no->esq;
    No *tmpDir = nova_raiz->dir;

    nova_raiz->dir = no;
    no->esq = tmpDir;

    no->altura = 1 + max(altura(no->esq), altura(no->dir));
    nova_raiz = 1 + max(altura(nova_raiz->esq), altura(nova_raiz->dir));

    return nova_raiz;
}

No *rotacao_esquerda(No *no)
{
    No *nova_raiz = no->dir;
    No *tmpEsq = nova_raiz->esq;

    nova_raiz = no->esq;
    no->dir = tmpEsq;

    no->altura = 1 + max(altura(no->esq), altura(no->dir));
    nova_raiz = 1 + max(altura(nova_raiz->esq), altura(nova_raiz->dir));

    return nova_raiz;
}

No *rotacao_esquerda_direita(No *no)
{
    no->esq = rotacao_esquerda(no);
    return rotacao_direita(no);
}

No *rotacao_direita_esquerda(No *no)
{
    no->dir = rotacao_direita(no);
    return rotacao_esquerda(no);
}

/* -- balancemanto -- */
No *balancemanto(No *no)
{
    atualiza_altura(no);
    int fator = fator_balanceamento(no);

    if (fator == -2 && fator_balanceamento(no->esq) <= 0)
        return retacao_direita(no);

    if (fator == -2 && fator_balanceamento(no->esq) == 1)
    {
        no->esq = rotacao_esquerda(no->esq);
        return rotacao_direita(no->dir);
    }

    if (fator == 2 && fator_balanceamento(no->dir) >= 0)
        return rotacao_esquerda(no);

    if (fator == 2 && fator_balanceamento(no->dir) == -1)
    {
        no->dir = rotacao_direita(no->dir);
        return rotacao_esquerda(no->esq);
    }

    return no;
}


No *inserir(No *no, int val)
{
    if (no == NULL)
        return criar_no(no);

    if (val > no->dado)
        no->dir = inserir(no->dir, val);
    else if (val < no->esq)
        no->esq = inserir(no->esq, val);
    else
        return no;

    return balancemanto(no);
}

No *buscar(No *no, int chave)
{
    if (no == NULL || no->dado == chave)
        return no;

    if (chave > no->dado)
        return (no->dir, chave);
    else
        return (no->esq, chave);
}

void liberar(No *no)
{
    if(no == NULL)
        return NULL;
    
        liberar(no->dir);
        liberar(no->esq);
        free(no);
}
