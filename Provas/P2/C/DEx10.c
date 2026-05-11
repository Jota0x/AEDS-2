#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;

    struct Celula *prox;
} Celula;

typedef struct
{
    int numero;

    CelulaMatriz *prox, *ant, *sup, *inf;

} CelulaMatriz;

typedef struct No
{
    int numero;
    struct No *esq, *dir;
} No;

Celula *encontrarRepetidos(No *raiz, CelulaMatriz *inicio)
{



}