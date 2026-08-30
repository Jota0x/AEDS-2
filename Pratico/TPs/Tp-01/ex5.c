#include <stdio.h>
#include <stdlib.h>

int soma_digitos(int n);

int main()
{
  int n;

  scanf("%d",&n);

  printf("%d",soma_digitos(n));

  return 0;
}

int soma_digitos(int n)
{
  if(n < 0)
    return 0;
  else 
    return n % 10 + soma_digitos(n/10);
}
