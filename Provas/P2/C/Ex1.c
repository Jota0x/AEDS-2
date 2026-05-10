typedef struct CelulaDupla
{

    int elemento;

    struct CelulaDupla *prox;

    struct CelulaDupla *ant;

} CelulaDupla;

CelulaDupla *primeiro; // cabeca sentinela

void inserirFim(int x)
{

    CelulaDupla *nova = (CelulaDupla *)malloc(sizeof(CelulaDupla));
    nova->elemento = x;

    CelulaDupla *ultimo = primeiro->ant;

    nova->prox = primeiro;
    nova->ant = ultimo;

    ultimo->prox = nova;
    primeiro->ant = nova;
}