typedef struct No
{

    struct No *dir, *esq;
    int dado;
    int altura;

} No;

typedef struct Arvore
{

    No *raiz;

} Arvore;

No *criar_no(int val);
Arvore *criar_arvore();
int max(int a, int b);
int altura(No *no); 
int fator_balanceamento(No *no);
void atualiza_altura(No *no);
No *rotacao_direita(No *no);
No *rotacao_esquerda(No *no);
No *rotacao_esquerda_direita(No *no);
No *rotacao_direita_esquerda(No *no);
No *balancemanto(No *no);
No *inserir(No *no, int val);
No *buscar(No *no, int chave);
void liberar(No *no);
