
public class Ex7 {

    class No {

        String palavra;
        No dir;
        No esq;

    }

    class Arvore {

        No raiz;
    }

    int contarPalavras(No no, String padrao) {

        int contador = 0;

        if (no == null) {
            return 0;
        }

        if (no.palavra.charAt(0) == padrao.charAt(0) && no.palavra.length() == padrao.length()) {
            contador = 1;
        }

        return contador + contarPalavras(no.esq, padrao) + contarPalavras(no.dir, padrao);

    }

}
