#include "pilha.h"

//Cria nova Pilha 
Pilha* newPilha()  
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));

    if(p == NULL)
        return NULL;

    //Atribui valores a Pilha 
    p->topo = -1;

}

//Verifica se pilha esta Cheia
bool isFull(Pilha *p)
{
    if(p->topo == MAX - 1)
        return true;
    else
        return false;

}

//Verifica se Pilha esta vazia
bool isEmpty(Pilha *p)
{
    if(p->topo == -1)
        return true;
    else
        return false;
}

//Empilha 
void push(Pilha *p,int valor)
{
    if(!isFull(p))
    {

        p->topo++;
        p->dados[p->topo] = valor;

    }
    else
        printf("Pilha Cheia!\n");

}

void pop(Pilha *p)
{
    if(!isEmpty(p))
    {   

        printf("%d",&p->dados[p->topo]);    //imprime Valor q saiu da Pilha
        p->topo--;

    }
    else
        printf("Pilha vazia!\n");


}

//Libera memória alocada por pilha 
void freePilha(Pilha *p)
{
    free(p);
}


