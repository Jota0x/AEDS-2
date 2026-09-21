typedef struct Node
{
    int dado;
    struct Node *prox;

}Node;

typedef struct Lista
{
    Node *inicio;
    Node *fim;

}Lista;

Lista *cria_lista();
Node *cria_celula(int valor);
void adicionar_inicio(Lista *l, int valor);
void adicionar_fim(Lista *l, int valor);
void adicionar_pos(Lista *l, int valor, int posicao);
void remover_inicio(Lista *l);
void remover_fim(Lista *l);
void remover_pos(Lista *l, int posicao);
void remover_valor(Lista *l, int chave);
void ordenar(Lista *l);
void mostrar(Lista *l);
void deletar(Lista *l);
