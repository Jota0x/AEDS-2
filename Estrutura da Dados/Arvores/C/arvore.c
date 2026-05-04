#include "arvore.h"

Arvore *cria_arvore()
{

    Arvore *a = (Arvore *)malloc(sizeof(Arvore));

    if (a == NULL)
        return;

    a->raiz = NULL;

    return;
}

No *cria_no(int val)
{
    No *nova = (No *)malloc(sizeof(No));
    if (nova == NULL)
        return;

    nova->dado = val;
    nova->direita = NULL;
    nova->esquerda = NULL;
}

// Destroi no
void destruir_no(No *raiz)
{
    if (raiz == NULL)
        return;

    // percorre toda a direita
    destroi_arvore(raiz->direita);

    // percorre toda a esquerda
    destroi_arvore(raiz->esquerda);

    free(raiz);
}

// Destroi arvore
void destruir_arvore(Arvore *a)
{
    if (a == NULL || a->raiz == NULL)
        return;

    destruir_no(a->raiz);
}

// Inserir
No *inserir(No *raiz, int val)
{
    if (raiz == NULL)
        return cria_no(val);

    if (val > raiz->dado)
        inserir(raiz->esquerda, val);
    else if (val < raiz->dado)
        inserir(raiz->direita, val);

    return raiz;
}

// Busca
No *busca(No *raiz, int chave)
{
    if (raiz == NULL || raiz->dado == chave)
        return raiz;

    if (chave > raiz->dado)
        return busca(raiz->direita, chave);
    else if (chave < raiz->dado)
        return busca(raiz->esquerda, chave);
}

//Acha Menor no
No *menor_no(No *raiz)
{
    if (raiz == NULL)
        return NULL;

    if (menor_no(raiz->esquerda) == NULL)
        return raiz;
    else
        return menor_no(raiz->esquerda);
}

//Acha Maior no
No *maior_no(No *raiz)
{
    if (raiz == NULL)
        return NULL;

    if (maior_no(raiz->direita) == NULL)
        return raiz;
    else
        return maior_no(raiz->direita);
}

//Excluir