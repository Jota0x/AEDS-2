#include <stdio.h>
#include <stdlib.h>

typedef struct Celula
{
    int dado;
    Celula *prox;

} Celula;

typedef struct Celula *Lista;
Lista *l;

Lista* cria_lista();
void destroi_lista(Lista *l);
void adicionar_inicio(Lista *l, int val);
void adicinar_final(Lista *l, int val);
void adicionar_ordenado(Lista *l, int val);


