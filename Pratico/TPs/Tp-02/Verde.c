#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Modelagem de Data
typedef struct Data
{
    int dia;
    int mes;
    int ano;

}Data;

//Modelagem de Veiculo
typedef struct Veiculo
{
    int id;
    char *marca;
    char *modelo;
    int ano;
    char *categoria;
    char *combustivel;
    int cilindros;
    double cilindrada;
    char *transmissao;
    char *tracao;
    double consumoCidade;
    double consumoEstrada;
    double co2;
    bool turbo;
    Data dataResgistro;
}Veiculo;

//Funcoes Data
parseData(char *s){
  
  Data nova_data;

  //pega dia 
  char *partes = strtok(s,"-");
  nova_data.dia = atoi(partes);
  //pega mes
  partes = strtok(NULL, "-");
  nova_data.mes = atoi(partes);
  //pega ano
  partes = strtok(NULL, "-");
  nova_data.ano = atoi(partes);

  return nova_data;
}

void formatData(Data d, char *buffer) {  
  sprintf("%d/%d/%d", d.dia, d.mes, d.ano);
}

//Funcoes Veiculo
Veiculo ParceVeiculo(char *s)
{
  Veiculo novo_veiculo;
  //pega id
  char *partes = strtok(s,",");
  novo_veiculo.id = atoi(partes);
  //pega marca
  partes = strtok(NULL, ",");
  novo_veiculo.marca = partes;
  //pega modelo
  partes = strtok(NULL, ",");
  novo_veiculo.modelo = partes;
  //pega ano
  partes = strtok(NULL, ",");
  novo_veiculo.ano = atoi(partes);


  return novo_veiculo;
}


