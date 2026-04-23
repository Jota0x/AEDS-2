#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int hora;
    int minuto;

} Hora;

typedef struct
{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct
{
    int tamanho;
    Restaurante *restaurantes;

} Colecao_Restaurante;

typedef struct
{
    int id;
    char *nome;
    char *cidade;
    int capacidade;
    double avaliacao;
    char **tipos_cozinha;
    int faixa_preco;
    Hora horario_abertura;
    Hora horario_fechamento;
    Data data_abertura;
    bool aberto;

} Restaurante;

// Metodos Hora
Hora parse_hora(char *s);
void formatar_hora(Hora *hora, char *buffer);

// Metodos Data
Data parse_data(char *s);
void formatar_data(Data *data, char *buffer);

// Metodos Restaurante
Restaurante parse_restaurante(char *s);
void formatar_restaurante(Restaurante *restaurante, char *buffer);

// Metodos Colecao_Restaurantes

// ========================================================================================== //

int main()
{
  

    return 0;
}

// ========================================================================================== //


// Transforma string em Hora
Hora parse_hora(char *s)
{
    Hora hora;

    sscanf(s, "%d:%d", &hora.hora, &hora.minuto);

    return hora;
}

// Formata Hora
void formatar_hora(Hora *hora, char *buffer)
{
    sprintf(buffer, "%02d:%02d", hora->hora, hora->minuto);
}

// Transforma String em Data
Data parse_data(char *s)
{
    Data data;

    sscanf(s, "%d-%d-%d", &data.dia, &data.mes, &data.ano);

    return data;
}

// Formata data
void formatar_data(Data *data, char *buffer)
{
    sprintf(buffer, "%d/%d/%d", data->dia, data->mes, data->ano);
}

// Trasnforma string em Restaurante
Restaurante parse_restaurante(char *s)
{

    Restaurante restaurante;

    sscanf(s, "%d, %s, %s, %d,",)
}

// Formata Restaurante
void formatar_restaurante(Restaurante *restaurente, char *buffer) {}
