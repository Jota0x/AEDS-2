
public class Ex8 {

    private No raiz;

    public void inserir(No no, String palavra) {

        No busca = busca(no, palavra.charAt(0));
        if (no == null) {
            return;
        }

        Celula nova = new Celula(palavra);

        //Trata lista vazia 
        if (busca.primeiro == null) {
            busca.primeiro = nova;
            return;
        }

        //Trata primeiro elemento
        if (busca.primeiro.palavra.compareTo(palavra) > 0) {
            nova.prox = busca.primeiro;
            busca.primeiro = nova;
            return;

        }

        Celula aux = busca.primeiro;

        //Verifica ordem alfabetica
        while (aux.prox != null && aux.palavra.compareTo(palavra) > 0) {
            aux = aux.prox;
        }

        nova.prox = aux.prox;
        aux.prox = nova;
    }

    public No busca(No no, char chave) {

        if (no == null || no.letra == chave) {
            return no;
        }

        if (chave > no.letra) {
            return busca(no.dir, chave);
        } else {
            return busca(no.esq, chave);
        }

    }

}

class No {

    char letra;
    No esq, dir;
    Celula primeiro, ultimo;

}

class Celula {

    String palavra;
    Celula prox;

    Celula(String palavra) {

        this.palavra = palavra;
        this.prox = null;

    }

}
