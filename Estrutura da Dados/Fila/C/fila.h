#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int fim;
    int *dados;
    int capacidade;
}Fila;

Fila* newFila(int tam);
bool isFull(Fila *f);
bool isEmpty(Fila *f);
void adicionar(Fila *f,int valor);
void removerInicio(Fila *f);
void freeFila(Fila *f);




