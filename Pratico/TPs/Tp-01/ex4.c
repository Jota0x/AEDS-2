#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehFim(char str[]);
char *inverteString(char *string);

int main()
{
  char *string = (char*)malloc(1000 * sizeof(char));

  scanf(" %[^\n]", string);

  while (ehFim(string) != 1)
  {
    char *invertido = inverteString(string);

    printf("%s\n", invertido);

    free(invertido);

    scanf(" %[^\n]", string);
  }

  free(string);

  return 0;
}

char *inverteString(char *string)
{
  char *nova = (char *)malloc(1000 * sizeof(char));
  int aux = 0, tam = strlen(string);

  for (int i = tam - 1; i >= 0; i--)
  {
    nova[aux] = string[i];
    aux++;
  }

  // Fecha string
  nova[aux] = '\0';

  return nova;
}

// verifica fim
int ehFim(char str[])
{
  if (strlen(str) != 3)
  {
    return 0;
  }

  if (str[0] == 'F' && str[1] == 'I' && str[2] == 'M')
  {
    return 1;
  }

  return 0;
}
