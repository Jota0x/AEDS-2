#define MAX 100

typedef struct Lista
{
    int dado[MAX];
    int tam;

}Lista;

Lista* criar_lista();
void deletar();
void inserir_inicio(Lista* l, int dado);
void inserir_fim(Lista *l, int dado);
void inserir(Lista *l, int dado, int posicao);
void remover_inicio(Lista *l);
void remover_fim(Lista *l);
int remover(Lista *l, int pos);
void mostrar(Lista *l);
int pesquisar(Lista *l, int chave);




