#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

Hash *criar_hash()
{
    Hash *h = (Hash *)malloc(sizeof(Hash));
    if (h == NULL)
        return NULL;

    for (int i = 0; i < TABLE_SIZE; i++)
        h->table[i] = NULL;

    return h;
}

int funcao_hash(int chave)
{
    return chave % TABLE_SIZE;
}

int funcao_rehash(int chave)
{
    return ++chave % TABLE_SIZE;
}

void inserir(Hash *h, int chave)
{
    int pos = funcao_hash(chave);

    if (h->table[pos] == NULL)
        h->table[pos] = chave;
    else
    {

        pos = fucao_rehash(chave);
        if (h->table[pos] == NULL)
            h->table[pos] = chave;
    }
}

void excluir(Hash *h, int chave)
{
    int pos = funcao_hash(chave);

    if (h->table[pos] == chave)
        h->table[pos] = NULL;
    else
    {
        
        pos = fucao_rehash(chave);
        if (h->table[pos] == chave)
            h->table[pos] = NULL;
    }
}