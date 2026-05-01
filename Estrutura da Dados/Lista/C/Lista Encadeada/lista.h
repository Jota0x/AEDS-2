#include <stdio.h>
#include <stdlib.h>

// Estrutura da Celula
typedef struct Celula
{
    int dado;
    struct Celula *prox;

} Celula;

// Estrutura da Lista
typedef struct Lista
{
    Celula *inicio;
    Celula *fim;

} Lista;

Lista *criar_lista();
void inserir_inicio(Lista *l, int val);
void inserir_pos(Lista *l, int val, int pos);
void inserir_fim(Lista *l, int val);
int remover_inicio(Lista *l);
int remover_pos(Lista *l);
int remover_fim(Lista *l);
