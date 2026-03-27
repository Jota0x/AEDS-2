#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int fim;
    int *dados;
    int tam;

} Lista;

// cria pilha
Lista *newLista(int tam);
bool isEmpty(Lista *l);
bool isFull(Lista *l);
void adicionarInicio(Lista *l,int val);
void adicionarPos(Lista,int pos,int val);
void adicionarFim(Lista *l,int val);
void removerInicio(Lista *l,int val);
void removerPos(Lista *l,int pos);
void removerFim(Lista *l);
void freeLista(Lista *l);



