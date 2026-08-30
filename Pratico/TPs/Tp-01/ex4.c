#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverteString(char* string);

int main()
{
  char *string;

  scanf("%s",string);
  
  string = inverteString(string);
  
  return 0;
}

char* inverteString(char* string)
{
  char *nova;
  int aux = 0, tam = strlen(string);

  for(int i = tam; i >= 0; i--)
  {
    nova[aux] = string[i]; 
    aux++;
  }
  return nova;
}
