#define TABLE_SIZE 15


typedef struct Hash
{
    int table[TABLE_SIZE];
}Hash;

Hash *criar_hash();
void funcao_hash(int chave);
void fucao_rehash(int chave);
void inserir(Hash *h, int chave);
