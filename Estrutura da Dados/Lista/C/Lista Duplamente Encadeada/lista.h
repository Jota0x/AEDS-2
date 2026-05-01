#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    int dado;
    struct Celula *ant;
    struct Celula *prox;

} Celula;

typedef struct lista
{
    Celula *inicio;
    Celula *fim;

} Lista;

Lista *criar_lista();
void inserir_inicio(Lista *l, int val);
void inserir_fim(Lista *l, int val);
int remover_iniciar(Lista *l);
int remover_fim(Lista *l);