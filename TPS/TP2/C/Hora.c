

typedef struct
{
  int hora;
  int minuto;

}Hora;


//Transforma string em Hora 
Hora parse_hora(char *s)
{
  Hora hora;

  sscanf(s,"%d:%d",&hora.hora, &hora.minuto);
  
  return hora;

}

//Formata Hora
void formatar_hora(Hora *hora, char *buffer)
{
  sprintf(buffer, "%02d:%02d", hora->hora, hora->minuto);
}

