#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{

    int elemento;

    struct Celula *inf, *sup, *esq, *dir;

} Celula;

typedef struct
{

    int linhas, colunas;
    Celula *inicio;

} Matriz;

void removerUltimaColuna(Matriz *matriz)
{
    Celula *linha_inicio = matriz->inicio;

    // Acha ultimo elemento da Linha
    while (linha_inicio->dir)
        linha_inicio = linha_inicio->dir;

    //Guarda inicio da Coluna 
    Celula *ultima_coluna = linha_inicio;

    //Loop para a exclusão da ultima coluna 
    while (ultima_coluna != NULL)
    {
        Celula *aux = ultima_coluna->sup;
        ultima_coluna->esq->dir = NULL;
        free(ultima_coluna);
        ultima_coluna = aux;
    }

    matriz->colunas--;
}