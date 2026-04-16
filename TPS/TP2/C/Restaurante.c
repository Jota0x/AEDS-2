#include "Hora.c"
#include "Data.c"
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

}Restaurante;

//Trasnforma string em Restaurante 
Restaurante parse_restaurante(char *s){}

//Formata Restaurante 
void formatar_restaurante(Restaurante *restaurente, char *buffer){}
