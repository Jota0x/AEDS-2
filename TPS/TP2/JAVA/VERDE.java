import java.util.*;
import java.io.*;

public class VERDE {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        ColecaoRestaurantes colecao = ColecaoRestaurantes.lerCSV();

        int id = dado.nextInt();

        while (id != -1) {

            for (int i = 0; i < colecao.getTamanho(); i++) {

                Restaurante restaurante = colecao.getRestaurante()[i];

                if (restaurante.getId() == id)
                    System.out.println(restaurante.formatar());
            }

            id = dado.nextInt();
        }

        dado.close();

    }

}

class Data {

    private int dia;
    private int mes;
    private int ano;

    // Construtores
    public Data() {
    }

    public Data(int dia, int mes, int ano) {

        this.dia = dia;
        this.mes = mes;
        this.ano = ano;

    }

    // setters
    public void setDia(int dia) {
        this.dia = dia;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    // getter
    public int getDia() {
        return this.dia;
    }

    public int getMes() {
        return this.mes;
    }

    public int getAno() {
        return this.ano;
    }

    public Data parseData(String s) {

        // Cria objeto do tipo Scanners
        Scanner dado = new Scanner(s);

        // Separa String para criar objeto
        dado.useDelimiter("-");

        int ano = dado.nextInt();
        int mes = dado.nextInt();
        int dia = dado.nextInt();

        // cria objeto Data
        Data data = new Data(dia, mes, ano);

        dado.close();

        return data;

    }

    public String formatar() {
        return String.format("%02d/%02d/%04d", getDia(), getMes(), getAno());
    }

}

class Hora {

    private int hora;
    private int minuto;

    // Construtores
    public Hora() {
    }

    public Hora(int hora, int minuto) {

        this.hora = hora;
        this.minuto = minuto;

    }

    // Setters
    public void setHora(int hora) {
        this.hora = hora;
    }

    public void setMinuto(int minuto) {
        this.minuto = minuto;
    }

    // getters
    public int getHora() {
        return this.hora;
    }

    public int getMinuto() {
        return this.minuto;
    }

    public Hora parseHora(String s) {

        Scanner dado = new Scanner(s);

        dado.useDelimiter(":");

        int hora = dado.nextInt();
        int minuto = dado.nextInt();

        Hora horas = new Hora(hora, minuto);

        dado.close();

        return horas;

    }

    public String formatar() {
        return String.format("%02d:%02d", getHora(), getMinuto());
    }

}

class Restaurante {

    private int id;
    private String nome;
    private String cidade;
    private int capacidade;
    private double avaliacao;
    private String tiposCozinha;
    private int faixaPreco;
    private Hora horaAbertura;
    private Hora horaFechamento;
    private Data dataAbertura;
    private boolean aberto;

    // Construtores
    public Restaurante() {
    }

    public Restaurante(int id, String nome, String cidade, int capacidade, double avaliacao,
            String tiposCozinha, int faixaPreco, Hora horaAbertura, Hora horaFechamento,
            Data dataAbertura, boolean aberto) {

        this.id = id;
        this.nome = nome;
        this.cidade = cidade;
        this.capacidade = capacidade;
        this.avaliacao = avaliacao;
        this.tiposCozinha = tiposCozinha;
        this.faixaPreco = faixaPreco;
        this.horaAbertura = horaAbertura;
        this.horaFechamento = horaFechamento;
        this.dataAbertura = dataAbertura;
        this.aberto = aberto;

    }

    // Setters
    public void setId(int id) {
        this.id = id;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }

    public void setAvaliacao(double avaliacao) {
        this.avaliacao = avaliacao;
    }

    public void setTiposCozinha(String tiposCozinha) {
        this.tiposCozinha = tiposCozinha;
    }

    public void setFaixaPreco(int faixaPreco) {
        this.faixaPreco = faixaPreco;
    }

    public void setAbertura(Hora abertura) {
        this.horaAbertura = abertura;
    }

    public void setFechamento(Hora fechamento) {
        this.horaFechamento = fechamento;
    }

    public void setDataAbertura(Data dataAbertura) {
        this.dataAbertura = dataAbertura;
    }

    public void setAberto(boolean aberto) {
        this.aberto = aberto;
    }

    // getters
    public int getId() {
        return this.id;
    }

    public String getNome() {
        return this.nome;
    }

    public String getCidade() {
        return this.cidade;
    }

    public int getCapacidade() {
        return this.capacidade;
    }

    public double getAvaliacao() {
        return this.avaliacao;
    }

    public String getTiposCozinha() {
        return this.tiposCozinha;
    }

    public int getFaixaPreco() {
        return this.faixaPreco;
    }

    public Hora getAbertura() {
        return this.horaAbertura;
    }

    public Hora getFechamento() {
        return this.horaFechamento;
    }

    public Data getDataAbertura() {
        return this.dataAbertura;
    }

    public boolean getAberto() {
        return this.aberto;
    }

    /*
     * Arrumar depois
     *
     * public static Restaurante parseRestaurante(String s) {
     * 
     * Restaurante restaurante = new Restaurante();
     * 
     * Scanner dado = new Scanner(s);
     * dado.useDelimiter("[,] ## ");
     * 
     * int id = dado.nextInt();
     * String nome = dado.next();
     * String cidade = dado.next();
     * int capacidade = dado.nextInt();
     * double avaliacao = Double.parseDouble(dado.next());
     * 
     * String tiposCozinha = dado.next();
     * 
     * dado.close();
     * 
     * }
     * 
     * 
     * public String formatar() {
     * return String.format(
     * "[%d ## %s ## %s ## %d ## %.1f ## [%s] ## %s ## %s ## %s ## %b]",
     * id, nome, cidade, capacidade, avaliacao,
     * String.join(",", tiposCozinha), "$".repeat(faixaPreco),
     * horarioAbertura.formatar(),
     * dataAbertura.formatar(), aberto);
     * }
     * 
     */

}

class ColecaoRestaurantes {

    private int tamanho = 0;
    private Restaurante[] restaurantes;

    // Construtores
    ColecaoRestaurantes() {
    }

    ColecaoRestaurantes(int tamanho, Restaurante restaurantes) {

        this.tamanho = tamanho;
        this.restaurantes = new Restaurante[tamanho];

    }

    // setters
    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public void setRestaurantes(Restaurante[] restaurantes) {
        this.restaurantes = restaurantes;
    }

    // getters
    public int getTamanho() {
        return this.tamanho;
    }

    public Restaurante[] getRestaurante() {
        return this.restaurantes;
    }

    public void lerCSV(String path) {

        try {

            File arquivo = new File(path);
            Scanner dado = new Scanner(arquivo);

            // pula primeira linha
            if (dado.hasNextLine()) {
                dado.nextLine();
            }

            // Loop principal para leitura
            while (dado.hasNextLine() && tamanho < restaurantes.length) {

                // le linha
                String leitura = dado.nextLine();

                // Transforma linha em Objeto
                Restaurante restaurante = Restaurante.parseRestaurante(leitura);

                restaurantes[tamanho] = restaurante;

                tamanho++;

            }

            dado.close();

        } catch (FileNotFoundException e) {
            System.err.println(e);
        }

    }

    public static ColecaoRestaurantes lerCSV() {

        ColecaoRestaurantes colecao = new ColecaoRestaurantes();

        colecao.lerCSV("/tmp/RESTAURANTES.CSV");

        return colecao;
    }

}
