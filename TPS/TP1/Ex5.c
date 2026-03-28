#include <stdio.h>
#include <stdlib.h>

// Prototipo da funcao
int soma(int n);

int main()
{

    int n;

    while (scanf("%d", &n) != EOF)
        printf("%d\n", soma(n));

    return 0;
}

// funcao recursiva Soma de Digitos
int soma(int n)
{
    if (n == 0)
        return 0;

    return n % 10 + soma(n / 10);
}
