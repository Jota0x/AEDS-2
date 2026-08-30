#include <stdio.h>
#include <stdlib.h>

void Ciframento(char *str);

int main()
{
    char *str = (char*)malloc(100 * sizeof(char));

    fgets(str,100,stdin);

    Ciframento(str);
  
    printf("%s",str);
  
    free(str);
  
    return 0;

}

void Ciframento(char *str)
{
  //Caso base
  //Verifica se conteudo é igual a "\0"
  if(*str == '\0')
    return;

  //Soma 3 ao conteudo da posicao para ciframento
  *str += 3;

  //Passo recursivo
  return Ciframento(str++);
}
