#include "lista.h"

Lista *criar_lista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));

    if (l == NULL)
        return NULL;

    l = NULL;

    return l;
}

void destroi_lista(Lista *l)
{
    if (l != NULL)
    {
        Celula *aux;

        while (*l != NULL)
        {
            aux = *l;
            *l = aux->prox;
            free(aux);
        }
    }
}

void adicionar_inicio(Lista *l, int val)
{
    // Lista nao existe
    if (l == NULL)
        return NULL;

    Celula *nova = (Celula *)malloc(sizeof(Celula));

    nova->dado = val;
    nova->prox = *l;
    *l = nova;
}

void adicinar_final(Lista *l, int val)
{
    // Lista nao existe
    if (l == NULL)
        return NULL;

    Celula *nova = (Celula *)malloc(sizeof(Celula));

    nova->dado = val;
    nova->prox = NULL;

    // Lista vazia
    // Adiciona primeiro elemento
    if (*l == NULL)
        *l = nova;

    Celula *aux = *l;

    while (aux->prox != NULL)
        aux = aux->prox;

    aux->prox = nova;
}

void adicionar_ordenado(Lista *l, int val)
{
    if (l == NULL)
        return NULL;

    Celula *nova = (Celula *)malloc(sizeof(Celula));

    nova->dado = val;

    // Lista vazia
    // Adiciona no inicio
    if (*l == NULL)
    {
        nova->prox = NULL;
        *l = nova;
    }

    Celula *aux = *l;

    while (aux->prox != NULL && aux->dado < val)
        aux = aux->prox;

    
    aux->prox = nova;
    nova->prox = aux;
}

void remover_inicio(Lista *l)
{
    //Lista nao existe
    if(l == NULL)
        return NULL;

    //Lista vazia
    if(*l == NULL)
        return NULL;

    Celula *aux = *l;

    *l = aux->prox;
    free(aux);

}

void remover_final(Lista *l)
{   
    //Lista nao existe
    if(l == NULL)
        return NULL;
    
    //Lista vazia 
    if(*l == NULL)
        return NULL;

    Celula *aux = *l;

    while(aux->prox != NULL)
        aux = aux->prox;

    free(aux);

}

void remove_posicao(Lista *l, int pos)
{
    //Lista nao exite
    if(l == NULL)
        return NULL;

    //Lista vazia
    if(*l == NULL)
        return NULL;

    Celula *aux = *l;
    int i = 1; //auxiliar para posicao


    while(aux->prox != NULL && i <= pos - 1 )
        aux = aux->prox; 


}