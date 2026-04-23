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
Restaurant parse_restaurante(char *s) {
  
  Restaurante r;
  
  //Variaveis auxiliares para os metodos parase
  char tmp_horario_abertura[10];
  char tmp_horario_fechamento[10];
  char tmp_data_abertura[10];

  sscanf("%d,%s,%s,%d,%lf,%s,%s-%s,%s,%d", r->id, r->nome, r->cidade, r->capacidade,
         r->avaliacao, r->tipos_cazinha, r->faixa_preco, tmp_horario_abertura, tmp_horario_fechamento, tmp_data_abertura, r->aberto);
  
  //Trasforma string em "Objetos"
  r->horario_abertura = parse_data(tmp_horario_abertura);
  r->horario_fechamento = parse_data(tmp_horario_fechamento);
  r->data_abertura = parse_data(tmp_data_abertura);

  return  r;
}

//Formata Restaurante
//Verificar depois 
void formatar_restaurante(Restaurante *restaurente, char *buffer) {

  ssprintf(buffer,"[%d ## %s ## %s ## %d ## %lf  ##
[%s] ## %s ## %s-%s ##
%s ## %d]", r->id, r->nome, r->cidade,r->capacidade,
           r->avaliacao, r->tipos_cozinha, r->faixa_preco, formatar_hora(r->horario_abertura, stdout),
           formatar_data(r->hora_abertura, stdout), formatar_data(r->data_abertura, stdout), r->aberto);

}
