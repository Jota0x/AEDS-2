#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n);

int main()
{
  int n;

  while (scanf("%d", &n) == 1)
  {
    printf("%d\n", soma_digitos(n));
  }

  return 0;
}

//Soma digitos
int soma_digitos(int n)
{
  int soma = 0;

  while (n != 0)
  {
    soma += n % 10;
    n = n / 10;
  }

  return soma;
}
