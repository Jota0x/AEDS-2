#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    struct Celula *prox;
    int dado;

}Celula;

typedef struct Lista
{
    Celula *inicio;
    Celula *fim;
    
}Lista;


Lista* criar_lista();
void inserir_inicio(Lista *l, int val);
void inserir_fim(Lista *l, int val);
void inserir_pos(Lista *l, int val);
void remover_inicio(Lista *l);
void remover_fim(Lista *l);
void remover_pos(Lista *l, int pos);







