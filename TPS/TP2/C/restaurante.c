#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Tipos de dados
typedef struct
{
    int hora;
    int minuto;
    int segundo;

} Horario;

typedef struct
{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct
{
    int id;
    char *nome;
    char *cidade;
    double nota;
    char *tipos_cozinha;
    char *faixa_preco;
    Horario horario;
    Data data_abertura;
    bool aberto;

} Restaurante;

int main()
{

    return 0;
}