class Fila {

    private int fim;
    private int[] dados;
    private int capacidade;

    public Fila(int tam) {

        this.fim = -1;
        this.dados = new int[tam];
        this.capacidade = tam;

    }

    public boolean isFull() {

        if (fim == capacidade - 1)
            return true;
        else
            return false;

    }

    public boolean isEmpty() {

        if (fim == -1)
            return true;
        else
            return false;

    }

    public void Adicionar(int valor) {
        if (!isFull()) {

            fim++;
            dados[fim] = valor;

        } else
            System.out.println("Fila cheia\n");
    }

    public void removerInicio() {
        if (!isEmpty()) {

            for (int i = 0; i < fim; i++)
                dados[i] = dados[i + 1];

            fim--;

        } else
            System.out.println("Fila vazia\n");
    }

}