

typedef struct 
{
  int dia;
  int mes;
  int ano;

}Data;


//Transforma String em Data
Data parse_data(char *s)
{
    Data data;

    sscanf(s, "%d-%d-%d", &data.dia, &data.mes, &data.ano);

    return data;
}

//Formata data
void formatar_data(Data *data, char *buffer)
{
  sprintf(buffer, "%d/%d/%d", data->dia, data->mes, data->ano);
}





