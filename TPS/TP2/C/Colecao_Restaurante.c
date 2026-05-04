#include "Restaurante.c"

typedef struct
{
  int tamanho;
  Restaurante *restaurantes;

} Colecao_Restaurante;

void ler_CSV(Colecao_Restaurante *colecao, char *path)
{

  FILE *arquivo = fopen(path, "r");
  char linha[100];

  if (arquivo != NULL)
  {

    // loop principal
    // adiciona restaurante a colecao
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
      colecao->restaurantes[colecao->tamanho] = *parse_restaurante(linha);
      colecao->tamanho++;
    }

    fclose(arquivo);
  }
  else
    printf("ERRO AO ABRIR ARQUIVO");
}

Colecao_Restaurante *ler_csv()
{
  Colecao_Restaurante *colecao = (Colecao_Restaurante *)malloc(sizeof(Colecao_Restaurante));

  if(colecao == NULL)
    return;

  colecao->tamanho = 0;

  ler_CSV(colecao, "/tmp/RESTAURANTES.CSV");

  return colecao;
}
