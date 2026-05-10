typedef struct CelulaDupla
{

    int elemento;

    struct CelulaDupla *prox;

    struct CelulaDupla *ant;

} CelulaDupla;

CelulaDupla *primeiro; // cabeca sentinela

void removerInicio()
{
    // verifica lista vazia
    if (primeiro->prox == primeiro)
        return;

    CelulaDupla *remover = primeiro->prox;

    primeiro->prox = remover->prox;
    remover->prox->ant = primeiro;

    free(remover);
}