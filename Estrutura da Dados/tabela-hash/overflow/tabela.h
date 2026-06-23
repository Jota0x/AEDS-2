#define TABLE_SIZE 10
#define RESERVA 5

typedef struct Hash
{
    int table[TABLE_SIZE + RESERVA];
    int reserva;

}Hash;

Hash *criar_hash();
void funcao_hash(int val);
void inserir(Hash *t, int val);