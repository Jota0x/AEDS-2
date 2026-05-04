#include <stdio.h>
#include <stdlib.h>

// Celula
typedef struct No
{
  int dado;
  struct No *direita;
  struct No *esquerda;

} No;

// Arvore
typedef struct Arvore
{
  No *raiz;

} Arvore;

// Metodos
Arvore *cria_arvore();
No *cria_no(int val);
void destroi_no(No *raiz);
void destroi_arvore(Arvore *a);
void inserir(Arvore *a, int val);
void busca(No *raiz, int chave);
void maior_no(No *raiz);
void menor_no(No *raiz);
