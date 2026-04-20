import java.util.*;

public class Restaurante {

    private int id;
    private String nome;
    private String cidade;
    private int capacidade;
    private double avaliacao;
    private String tiposCozinha;
    private String faixaPreco;
    private String horario;
    private String dataAbertura;
    private boolean aberto;

    //Construtores
    public Restaurante() {}
    public Restaurante(int id, String nome, String cidade, int capacidade, double avaliacao, 
                       String tiposCozinha, String faixaPreco, String horario, 
                       String dataAbertura, boolean aberto) {

        this.id = id;
        this.nome = nome;
        this.cidade = cidade;
        this.capacidade = capacidade;
        this.avaliacao = avaliacao;
        this.tiposCozinha = tiposCozinha;
        this.faixaPreco = faixaPreco;
        this.horario = horario;
        this.dataAbertura = dataAbertura;
        this.aberto = aberto;

    }

    //Setters
    public void setId(int id) {this.id = id;}
    public void setNome(String nome) {this.nome = nome;}
    public void setCidade(String cidade) {this.cidade = cidade;}
    public void setCapacidade(int capacidade) {this.capacidade = capacidade;}
    public void setAvaliacao(double avaliacao) {this.avaliacao = avaliacao;}
    public void setTiposCozinha(String tiposCozinha) {this.tiposCozinha = tiposCozinha;}
    public void setFaixaPreco(String faixaPreco) {this.faixaPreco = faixaPreco;}
    public void setHorario(String horario) {this.horario = horario;}
    public void setDataAbertura(String dataAbertura) {this.dataAbertura = dataAbertura;}
    public void setAberto(boolean aberto) {this.aberto = aberto;}

    //getters
    public int getId() {return this.id;}
    public String getNome() {return this.nome;}
    public String getCidade() {return this.cidade;}
    public int getCapacidade() {return this.capacidade;}
    public double getAvaliacao() {return this.avaliacao;}
    public String getTiposCozinha() {return this.tiposCozinha;}
    public String getFaixaPreco() {return this.faixaPreco;}
    public String getHorario() {return this.horario;}
    public String getDataAbertura() {return this.dataAbertura;}
    public boolean getAberto() {return this.aberto;}

    public static Restaurante parseRestaurante(String s) {

        Scanner dado = new Scanner(s);
        dado.useDelimiter("[,] ## ");

        int id = dado.nextInt();
        String nome = dado.next();
        String cidade = dado.next();
        int capacidade = dado.nextInt();
        double avaliacao = Double.parseDouble(dado.next());
        String tiposCozinha = dado.next();
        String faixaPreco = dado.next();
        String horario = dado.next();
        String dataAbertura = dado.next();
        boolean aberto = dado.nextBoolean();

        dado.close();

        return new Restaurante(id, nome, cidade, capacidade, avaliacao, 
                               tiposCozinha, faixaPreco, horario, dataAbertura, aberto);
    }

    public String formatar() {
        return String.format(
            "[%d ## %s ## %s ## %d ## %.1f ## [%s] ## %s ## %s ## %s ## %b]",
            getId(), getNome(), getCidade(), getCapacidade(), getAvaliacao(), 
            getTiposCozinha(), getFaixaPreco(), getHorario(), getDataAbertura(), getAberto()
        );
    }




}
