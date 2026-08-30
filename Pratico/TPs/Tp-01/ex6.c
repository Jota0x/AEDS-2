#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isAnagrama(char* string);

int main()
{
    char *palavra;

    scanf("%s",palavra);

    if(isAnagrama(palavra))
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}

bool isAnagrama(char* string)
{
    int tam = strlen(string);

    for(int i = 0, j = tam - 1; i < j; i++,j--)
    {
        if(string[i] != string[j])
            return false;
    }

    return true;

}