#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    int dado;
    struct Celula *prox;

}Celula;

typedef struct 
{
    Celula *inicio;
    Celula *fim;

}Lista;

Lista *l;

Lista* criar_lista();
void destruir_lista(Lista *l);
void adicionar_inicio(Lista *l, int val);
void adicionar_fim(Lista *l, int val);
void adicionar_ordenado(Lista *l, int val);
void remover_incio(Lista *l);
void remover_fim(Lista *l);
void remover_pos(Lista *l, int pos);
int  quantidade_itens(Lista *l);
void imprimir_lista(Lista *l);






