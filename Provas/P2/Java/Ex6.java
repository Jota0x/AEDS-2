
public class Ex6 {

    class ArvoreArvore {

        No raiz;
    }

    class No {

        char letra;
        No esq, dir;
        No2 raiz;
    }

    class No2 {

        String palavra;
        No2 esq, dir;
    }

    int contarPalavras(ArvoreArvore arvore,char primeiro, char ultimo) {

        return contarNo(arvore.raiz, primeiro, ultimo);

    }

    int contarNo(No no, char pr, char ul) {

        No busca = busca(no, pr);
        if (busca == null) {
            return 0;
        }

        No2 raiz = busca.raiz;

        return contaNo2(raiz, ul);
    }

    int contaNo2(No2 no, char ultimo) {

        if (no == null) {
            return 0;
        }

        int contador = 0;

        if (ultimo == no.palavra.charAt(no.palavra.length() - 1)) {
            contador = 1;
        }

        return contador + contaNo2(no.dir, ultimo) + contaNo2(no.esq, ultimo);

    }

    //Busca No 
    No busca(No raiz, char p) {
        if (raiz == null || raiz.letra == p) {
            return raiz;
        }

        if (p > raiz.letra) {
            return busca(raiz.dir, p);
        } else {
            return busca(raiz.esq, p);
        }

    }

}
