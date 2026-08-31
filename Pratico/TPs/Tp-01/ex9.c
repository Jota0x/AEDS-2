#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Ciframento(char *str);
int ehFim(char *str);

int main()
{
  char *str = (char *)malloc(100 * sizeof(char));

  fgets(str, 100, stdin);

  int tam = strlen(str);

  while (!ehFim(str))
  {
    Ciframento(str);

    printf("%s\n", str);

    fgets(str, 100, stdin);

    tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n')
      str[tam - 1] = '\0';
  }

  free(str);

  return 0;
}

// Verifica fim
int ehFim(char *str)
{
  if (strlen(str) != 3)
    return 0;

  if (str[0] == 'F' && str[1] == 'I' && str[2] == 'M')
    return 1;

  return 0;
}

void Ciframento(char *str)
{
  // Caso base
  // Verifica se conteudo é igual a "\0"
  if (*str == '\0')
    return;

  // Soma 3 ao conteudo da posicao para ciframento
  *str += 3;

  // Passo recursivo
  return Ciframento(str + 1);
}