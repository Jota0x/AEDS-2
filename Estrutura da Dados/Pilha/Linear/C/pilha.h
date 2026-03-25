#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10


typedef struct
{
    int topo;           //Variavel de controle da Pilha 
    int dados[MAX];     //Dados armazenados na Pilha 

}Pilha;

//métodos da Pilha
Pilha* newPilha();
bool isFull(Pilha *p);
bool isEmpty(Pilha *p);
void push(Pilha *p, int valor);
void pop(Pilha *p);
void freePilha(Pilha *p);