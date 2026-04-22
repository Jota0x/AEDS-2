package Java;

public class Lista {

    private Celula inicio;
    private Celula fim;

    Lista() {
    }

    Lista(Celula incio, Celula fim) {

        this.inicio = null;
        this.fim = null;

    }

    public void inserirInicio(int val) {

        Celula nova = new Celula(val);
        nova.prox = inicio;

        if (fim == null)
            fim = nova;

        inicio = nova;

    }

    public void inserirFim(int val) {

        Celula nova = new Celula(val);

        if (inicio == null) {
            inicio = nova;
            fim = nova;
        }

        fim.prox = nova;
        fim = nova;

    }

    public void inserirPos(int val, int pos) {

        Celula nova = new Celula(val);

        if (inicio == null) {

            nova.prox = inicio;
            inicio = fim = nova;
        
        }

        Celula aux = inicio;
        int i = 1;

        while(aux != fim && pos - 1 > i)
        {
            aux = aux.prox;
            i++;
        }

        nova.prox = aux.prox;
        aux.prox = nova;

    }

    void removerInicio()
    {
        inicio = inicio.prox;
    }

    void removerFim()
    {
        Celula aux = inicio;

        while(aux.prox.prox != null)
            aux = aux.prox;

        fim = aux;
    }

    void removerPos(int pos)
    {
        
        //terminar logica

    }


}