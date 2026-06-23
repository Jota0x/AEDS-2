#include "tabela.h"
#include <stdio.h>
#include <stdlib.h>

Hash *criar_hash()
{
    Hash *h = (Hash *)malloc(sizeof(Hash));

    if (h == NULL)
        return NULL;

    for (int i = 0; i < TABLE_SIZE + RESERVA; i++)
        h->table[i] = NULL;

    h->reserva = 0;

    return h;
}

void inserir(Hash *t, int chave)
{
    int pos = chave % TABLE_SIZE;

    if (t->table[pos] == NULL)
        t->table[pos] = chave;
    else
    {
        t->table[TABLE_SIZE + t->reserva] = chave;
        t->reserva++;
    }
}

void buscar(Hash *t, int chave)
{
    int pos = chave % TABLE_SIZE;

    if (t->table[pos] == chave)
        return pos;
    else
    {

        for (int i = 0; i < t->reserva; i++)
            if (t->table[TABLE_SIZE + i] == chave)
                return TABLE_SIZE + i;
    }
}

void excluir(Hash *t, int chave)
{

    int pos = chave % TABLE_SIZE;

    if (t->table[pos] == chave)
        t->table[pos] = NULL;
    else
    {

        for (int i = 0; i < t->reserva; i++)
            if (t->table[TABLE_SIZE + i] == chave)
                t->table[TABLE_SIZE + i] = NULL;
    }
}