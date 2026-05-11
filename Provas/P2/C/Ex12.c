#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{

    int dado;
    struct Celula *dir, *esq, *sup, *inf;
}Celula;

typedef struct Matriz
{
    Celula *inicio;
    int linhas, colunas;

}Matriz;

Celula *cria_celula(int val)
{
    Celula *nova = (Celula*)(sizeof(Celula));
    if(nova == NULL) return NULL;
    
    nova->dado = val;

    return nova;
}


void inserirLinha(Matriz  *m, int *valores)
{
    Celula *ultimalinha = m->inicio;

    //acha ultima linha 
    for(int i = 0; i < m->linhas; i++)
        ultimalinha = ultimalinha->inf;


    for(int i = 0; i < m->colunas;i++)
    {
        Celula *nova = cria_celula(valores[i]);

        ultimalinha->inf = nova;
        nova->sup = ultimalinha;


    }

}
