/*
    Compara pares de elementos adjacentes e os troca de lugar se estiverem na ordem errada.
    O maior elemento "flutua" para o final da lista a cada passada.
*/

void bubble(int *vetor, int tam)
{

    for (int i = 0; i < tam; i++)
        for (int j = i + 1; j < tam; j++)
        {
            if (vetor[i] > vetor[j])
            {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
}




