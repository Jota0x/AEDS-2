
import com.sun.source.doctree.ReturnTree;

public class Ex13 {

    class Matriz {

        CelulaMat inicio;
    }

    class CelulaMat {

        CelulaMat prox, ant, sup, inf;

        Celula primeiro, ultimo;

        public CelulaMat() {

            primeiro = ultimo = new Celula();
        }

    }

    class Celula {

        int numero;
        Celula prox;
    }

    void removerImpares(Matriz m) {

        CelulaMat aux = m.inicio;
        CelulaMat sentinela = aux;

        while (aux != null) {
            aux = sentinela;

            while (aux != null) {
                remover(aux);
                aux = aux.prox;
            }

            if (sentinela.inf != null) {
                sentinela = sentinela.inf;
            }

        }

    }

    void remover(CelulaMat l) {

        while (l.primeiro != null && l.primeiro.numero % 2 != 0) {
            l.primeiro = l.primeiro.prox;
        }

        if (l.primeiro == null) {
            l.ultimo = null;
            return;
        }

        Celula remover = l.primeiro;

        while (remover != null) {

            if (remover.prox.numero % 2 != 0) {

                remover.prox = remover.prox.prox;

                if (remover.prox == null) {
                    l.ultimo = remover;
                }

            } else {

                remover = remover.prox;
            }

        }

    }

}
