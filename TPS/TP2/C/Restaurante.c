#include "Hora.c"
#include "Data.c"
#include <stdio.h>
#include <stdbool.h>

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

// Trasnforma string em Restaurante
Restaurante *parse_restaurante(char *s)
{

  Restaurante *r = (Restaurante *)malloc(sizeof(Restaurante));

  // Variaveis auxiliares para os metodos parase
  char tmp_horario_abertura[10];
  char tmp_horario_fechamento[10];
  char tmp_data_abertura[10];
  char tmp_tipos[200]; // armazena todos os tipos

  sscanf(s, "%d,%[^,],%[^,],%d,%lf,%[^,],%[^,]-%[^,],%[^,],%d", &r->id, r->nome, r->cidade, &r->capacidade,
         &r->avaliacao, tmp_tipos, &r->faixa_preco, tmp_horario_abertura, tmp_horario_fechamento, tmp_data_abertura, &r->aberto);

  // Trasforma string em "Objetos"
  r->horario_abertura = parse_hora(tmp_horario_abertura);
  r->horario_fechamento = parse_hora(tmp_horario_fechamento);
  r->data_abertura = parse_data(tmp_data_abertura);
  int qt_tipos = contador_tipo(tmp_tipos);
  r->tipos_cozinha = separar_tipos(tmp_tipos, qt_tipos);

  return r;
}

// Formata Restatypedef struct Data
{
    int dia;
    int mes;
    int ano;

} Data;

Data *parse_data(char *s)
{
    Data *d = (Data *)malloc(sizeof(Data));

    sscanf(s, "%d-%d-%d", &d->ano, &d->mes, &d->ano);

    return d;
}

void formatar_data(Data *d, char *buffer)
{
    ssprint(buffer, "%02d/%02d/%04d", d->dia, d->mes, d->ano);
}

typedef struct Hora
{
    int hora;
    int minuto;

} Hora;

Hora *parse_data(char *s)
{
    Hora *h = (Hora *)malloc(sizeof(Hora));

    sscanf(s, "%d:%d", &h->hora, &h->minuto);

    return h;
}

void formatar_hora(Hora *h, char *buffer)
{
    sprint(buffer, "%02d;%02d", h->hora, h->minuto);
}
// Verificar depois
void formatar_restaurante(Restaurante *r, char *buffer)
{
  // Strign auxiliares
  char buf_abertura[10];
  char buf_fechamento[10];
  char buf_data[20];

  int pos = 0;

  // formata hor
  formatar_hora(&r->horario_abertura, buf_abertura);
  formatar_hora(&r->horario_fechamento, buf_fechamento);
  formatar_data(&r->data_abertura, buf_data);

  // início
  pos += sprintf(buffer + pos, "[%d ## %s ## %s ## %d ## %lf ## [", r->id, r->nome, r->cidade, r->capacidade, r->avaliacao);

  // tipos de cozinha
  for (int i = 0; r->tipos_cozinha[i] != NULL; i++)
  {
    pos += sprintf(buffer + pos, "%s", r->tipos_cozinha[i]);

    if (r->tipos_cozinha[i + 1] != NULL)
    {
      pos += sprintf(buffer + pos, ";");
    }
  }

  // restante
  pos += sprintf(buffer + pos, "] ## %s ## %s-%s ## %s ## %d]", r->faixa_preco, buf_abertura, buf_fechamento, buf_data, r->aberto);
}

// Metodos auxilares
/* ================================================================================================================= */

// Contador de tipo
int contador_tipo(char *s)
{
  // variaveis de controle
  int i = 1, contador = 1;

  while (s[i] != '\0')
  {
    if (s[i] == ';')
    {
      contador++;
    }
    i++;
  }
}

// Copiar substring
void copiar_substring(char *origem, int inicio, int fim, char *destino)
{
  int j = 0;

  for (int i = inicio; i < fim; i++)
    destino[j++] = origem[i];

  destino[j] = '\0';
}

// Separa tipos e aloca em vetor
char **separar_tipos(char *tmp_tipos, int total)
{
  char **tipos = malloc((total + 1) * sizeof(char *));

  int inicio = 0;
  int k = 0;
  int i = 0;

  // loop principal
  // separa tipos
  while (tmp_tipos[i] != '\0')
  {

    if (tmp_tipos[i] == ';')
    {
      int tamanho = i - inicio;

      tipos[k] = malloc((tamanho + 1) * sizeof(char));
      copiar_substring(tmp_tipos, inicio, i, tipos[k]);

      k++;
      inicio = i + 1;
    }

    i++;
  }

  int tamanho = i - inicio;
  tipos[k] = malloc((tamanho + 1) * sizeof(char));
  copiar_substring(tmp_tipos, inicio, i, tipos[k]);

  k++;
  tipos[k] = NULL; 

  return tipos;
}