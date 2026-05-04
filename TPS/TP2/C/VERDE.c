#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX 1000

typedef struct Data
{
    int dia;
    int mes;
    int ano;

} Data;

typedef struct Hora
{
    int hora;
    int minuto;

} Hora;

typedef struct Restaurante
{
    int id;
    char nome[100];
    char cidade[100];
    int capacidade;
    double avaliacao;
    char **tipos_cozinha;
    int faixa_preco;
    Hora horario_abertura;
    Hora horario_fechamento;
    Data data_abertura;
    bool aberto;

} Restaurante;

typedef struct Colecao_Restaurante
{
    int tamanho;
    Restaurante *restaurantes;

} Colecao_Restaurante;

// Prototipos
// Data
Data parse_data(char *s);
void formatar_data(Data *d, char *buffer);

// Hora
Hora parse_hora(char *s);
void formatar_hora(Hora *h, char *buffer);

// Restaurante
Restaurante parse_restaurante(char *s);
void formatar_restaurante(Restaurante *r, char *buffer);

// Colecao Restaurante
void ler_CSV(Colecao_Restaurante *colecao, char *path);
Colecao_Restaurante *ler_csv();

// void gerar_log(char *matricula, char *algoritmo, long comparacoes, double tempo);

// Metodos auxiliares
int contador_tipos(char *s);
void copiar_substring(char *origem, int inicio, int fim, char *destino);
char **separar_tipos(char *tmp_tipos, int total);
bool parse_bool(char *s);
int meu_strcmp(char *s1, char *s2);

// ============================================== MAIN =========================================//

int main()
{
    Colecao_Restaurante *colecao = ler_csv();
    long comparacoes = 0;

    // le ids
    int ids[MAX];
    int n_ids = 0;
    int id;
    scanf("%d", &id);
    while (id != -1)
    {
        ids[n_ids++] = id;
        scanf("%d", &id);
    }

    // monta novo array de restaurante para pesquisa
    Restaurante arr[MAX];
    int n_arr = 0;
    for (int i = 0; i < colecao->tamanho; i++)
        for (int j = 0; j < n_ids; j++)
            if (colecao->restaurantes[i].id == ids[j])
                arr[n_arr++] = colecao->restaurantes[i];

    // ordena arr por nome com selection sort
    for (int i = 0; i < n_arr - 1; i++)
    {
        int aux = i;
        for (int j = i + 1; j < n_arr; j++)
            if (meu_strcmp(arr[j].nome, arr[aux].nome) < 0)
                aux = j;
        if (aux != i)
        {
            Restaurante tmp = arr[i];
            arr[i] = arr[aux];
            arr[aux] = tmp;
        }
    }

    clock_t inicio = clock();

    char nome[100];
    fgets(nome, 100, stdin);
    while (meu_strcmp(nome, "FIM") != 0)
    {
        // pesquisa binaria
        int esq = 0, dir = n_arr - 1, achou = 0;
        while (esq <= dir)
        {
            comparacoes++;
            int meio = (esq + dir) / 2;
            int cmp = meu_strcmp(nome, arr[meio].nome);
            if (cmp == 0)
                achou = 1;

            else if (cmp < 0)
                dir = meio - 1;
            else
                esq = meio + 1;
        }

        if (achou)
            printf("SIM\n");
        else
            printf("NAO\n");

        fgets(nome, 100, stdin);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // log
    FILE *log = fopen("891100_binaria.txt", "w");
    if (log != NULL)
    {
        fprintf(log, "%s\t%ld\t%lf\n", "891100", comparacoes, tempo);
        fclose(log);
    }

    return 0;
}

// ============================================== MAIN =========================================//

// Metodos Data
Data parse_data(char *s)
{
    Data d;

    sscanf(s, "%d-%d-%d", &d.ano, &d.mes, &d.dia);

    return d;
}

void formatar_data(Data *d, char *buffer)
{
    sprintf(buffer, "%02d/%02d/%04d", d->dia, d->mes, d->ano);
}

// Metodos hora
Hora parse_hora(char *s)
{
    Hora h;

    sscanf(s, "%d:%d", &h.hora, &h.minuto);

    return h;
}

void formatar_hora(Hora *h, char *buffer)
{
    sprintf(buffer, "%02d:%02d", h->hora, h->minuto);
}

// Metodos restaurante
Restaurante parse_restaurante(char *s)
{
    Restaurante r;

    // buffers auxiliares para transformacao
    char tmp_horario[20];
    char tmp_data[15];
    char tmp_tipos[100];
    char tmp_aberto[10];
    char tmp_faixa[10];

    sscanf(s, "%d,%99[^,],%99[^,],%d,%lf,%99[^,],%9[^,],%19[^,],%14[^,],%9s",
           &r.id, r.nome, r.cidade, &r.capacidade, &r.avaliacao,
           tmp_tipos, tmp_faixa, tmp_horario, tmp_data, tmp_aberto);

    // separa horario manualmente
    char tmp_abertura[10], tmp_fechamento[10];
    int i = 0, j = 0;
    while (tmp_horario[i] != '-')
        tmp_abertura[j++] = tmp_horario[i++];

    // fecha string
    tmp_abertura[j] = '\0';
    i++;
    j = 0;
    while (tmp_horario[i] != '\0')
        tmp_fechamento[j++] = tmp_horario[i++];

    // fecha string
    tmp_fechamento[j] = '\0';

    // converte faixa de preco de inteiro para $
    r.faixa_preco = 0;
    for (int k = 0; tmp_faixa[k] == '$'; k++)
        r.faixa_preco++;

    r.horario_abertura = parse_hora(tmp_abertura);
    r.horario_fechamento = parse_hora(tmp_fechamento);
    r.data_abertura = parse_data(tmp_data);
    r.aberto = parse_bool(tmp_aberto);

    int qt = contador_tipos(tmp_tipos);
    r.tipos_cozinha = separar_tipos(tmp_tipos, qt);

    return r;
}

void formatar_restaurante(Restaurante *r, char *buffer)
{
    char buf_abertura[10];
    char buf_fechamento[10];
    char buf_data[20];
    int pos = 0;

    formatar_hora(&r->horario_abertura, buf_abertura);
    formatar_hora(&r->horario_fechamento, buf_fechamento);
    formatar_data(&r->data_abertura, buf_data);

    // monta faixa_preco em '$'
    char faixa[10] = "";
    for (int i = 0; i < r->faixa_preco; i++)
        faixa[i] = '$';
    faixa[r->faixa_preco] = '\0';

    pos += sprintf(buffer + pos, "[%d ## %s ## %s ## %d ## %.1f ## [",
                   r->id, r->nome, r->cidade, r->capacidade, r->avaliacao);

    for (int i = 0; r->tipos_cozinha[i] != NULL; i++)
    {
        pos += sprintf(buffer + pos, "%s", r->tipos_cozinha[i]);
        if (r->tipos_cozinha[i + 1] != NULL)
            pos += sprintf(buffer + pos, ","); // ← vírgula
    }

    // aberto
    char tmp_aberto[10];
    if (r->aberto)
        sprintf(tmp_aberto, "true");
    else
        sprintf(tmp_aberto, "false");

    pos += sprintf(buffer + pos, "] ## %s ## %s-%s ## %s ## %s]",
                   faixa, buf_abertura, buf_fechamento, buf_data, tmp_aberto);
}

// Metodos Colecao Restaurante
void ler_CSV(Colecao_Restaurante *colecao, char *path)
{
    FILE *arquivo = fopen(path, "r");
    char linha[256];

    if (arquivo != NULL)
    {
        // pula primeira linha
        fgets(linha, sizeof(linha), arquivo);

        while (fgets(linha, sizeof(linha), arquivo) != NULL)
        {
            colecao->restaurantes[colecao->tamanho] = parse_restaurante(linha);
            colecao->tamanho++;
        }
        fclose(arquivo);
    }
    else
        printf("ERRO AO ABRIR ARQUIVO\n");
}

Colecao_Restaurante *ler_csv()
{
    Colecao_Restaurante *colecao = (Colecao_Restaurante *)malloc(sizeof(Colecao_Restaurante));

    if (colecao == NULL)
        return NULL;

    colecao->tamanho = 0;
    colecao->restaurantes = malloc(MAX * sizeof(Restaurante));

    if (colecao->restaurantes == NULL)
        return NULL;

    ler_CSV(colecao, "/tmp/restaurantes.csv");

    return colecao;
}

// Metodos auxilares
/* ================================================================================================================= */

// Contador de tipo
int contador_tipos(char *s)
{
    // variaveis de controle
    int i = 1, contador = 1;

    while (s[i] != '\0')
    {
        if (s[i] == ';')
        {
            contador++;
        }
        i++;
    }

    return contador;
}

// Copiar substring
void copiar_substring(char *origem, int inicio, int fim, char *destino)
{
    int j = 0;

    for (int i = inicio; i < fim; i++)
        destino[j++] = origem[i];

    destino[j] = '\0';
}

// Separa tipos e aloca em vetor
char **separar_tipos(char *tmp_tipos, int total)
{
    char **tipos = malloc((total + 1) * sizeof(char *));

    int inicio = 0;
    int k = 0;
    int i = 0;

    // loop principal
    // separa tipos
    while (tmp_tipos[i] != '\0')
    {

        if (tmp_tipos[i] == ';')
        {
            int tamanho = i - inicio;

            tipos[k] = malloc((tamanho + 1) * sizeof(char));
            copiar_substring(tmp_tipos, inicio, i, tipos[k]);

            k++;
            inicio = i + 1;
        }

        i++;
    }

    int tamanho = i - inicio;
    tipos[k] = malloc((tamanho + 1) * sizeof(char));
    copiar_substring(tmp_tipos, inicio, i, tipos[k]);

    k++;
    tipos[k] = NULL;

    return tipos;
}

bool parse_bool(char *s)
{
    // verifica "true"
    if (s[0] == 't' && s[1] == 'r' && s[2] == 'u' && s[3] == 'e')
        return true;

    // verifica "false"
    if (s[0] == 'f' && s[1] == 'a' && s[2] == 'l' && s[3] == 's' && s[4] == 'e')
        return false;

    return false;
}

int meu_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
        i++;
    }

    if (s1[i] == '\0' && s2[i] != '\0')
        return -1;
    if (s1[i] != '\0' && s2[i] == '\0')
        return 1;

    return 0;
}