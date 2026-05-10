
public class Ex5 {

    class Lista {

        CelulaLista inicio, fim;
    }

    class CelulaLista {

        CelulaPilha topo;
        CelulaLista prox;
    }

    class CelulaPilha {

        int elemento;
        CelulaPilha prox;
    }

    CelulaLista maiorPilha(Lista lista) {

        CelulaLista aux = lista.inicio;
        CelulaLista Celmaior = aux;
        int maior = contarPilha(aux.topo);

        while (aux != null) {

            int tamanho = contarPilha(aux.topo);

            if (maior < tamanho) {
                maior = tamanho;
                Celmaior = aux;
            }

            aux = aux.prox;

        }

        return Celmaior;
    }

    int contarPilha(CelulaPilha p) {

        int i = 0;
        CelulaPilha atual = p;

        while (atual != null) {
            i++;
            atual = atual.prox;
        }

        return i;

    }
}
