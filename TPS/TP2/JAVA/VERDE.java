
import java.io.*;
import java.util.*;

public class VERDE {

    public static void main(String[] args) {}

}

class Data {

    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    // Formato do CSV: "2018-03-31" (ano-mes-dia)
    public static Data parseData(String s) {

        Scanner dado = new Scanner(s);
        dado.useDelimiter("-");

        int ano = dado.nextInt();
        int mes = dado.nextInt();
        int dia = dado.nextInt();

        dado.close();

        return new Data(dia, mes, ano);
    }

    public String formatar() {
        return String.format("%02d/%02d/%04d", dia, mes, ano);
    }

}

class Hora {

    private int hora;
    private int minuto;

    public Hora(int hora, int minuto) {
        this.hora = hora;
        this.minuto = minuto;
    }

    public static Hora parseHora(String s) {

        Scanner dado = new Scanner(s);
        dado.useDelimiter(":");

        int h = dado.nextInt();
        int m = dado.nextInt();

        dado.close();

        return new Hora(h, m);
    }

    public String formatar() {
        return String.format("%02d:%02d", hora, minuto);
    }

}

class Restaurante {

    private int id;
    private String nome;
    private String cidade;
    private int capacidade;
    private double avaliacao;
    private String[] tiposCozinha;
    private int faixaPreco;
    private Hora horaAbertura;
    private Hora horaFechamento;
    private Data dataAbertura;
    private boolean aberto;

    public Restaurante(int id, String nome, String cidade, int capacidade, double avaliacao,
            String[] tiposCozinha, int faixaPreco, Hora horaAbertura, Hora horaFechamento,
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

    public int getId() {
        return this.id;
    }

    public static Restaurante parseRestaurante(String s) {

        Scanner dado = new Scanner(s);
        dado.useDelimiter(",");
        dado.useLocale(Locale.US); //  leitura do double com ponto decimal

        int id = dado.nextInt();
        String nome = dado.next();
        String cidade = dado.next();
        int capacidade = dado.nextInt();
        double avaliacao = dado.nextDouble();

        // tipos_cozinha
        String[] tiposCozinha = dado.next().split(";");

        // faixa_preco:
        int faixaPreco = dado.next().trim().length();

        // horario
        String[] horario = dado.next().split("-");
        Hora horaAbertura = Hora.parseHora(horario[0]);
        Hora horaFechamento = Hora.parseHora(horario[1]);

        Data dataAbertura = Data.parseData(dado.next());
        boolean aberto = dado.nextBoolean();

        dado.close();

        return new Restaurante(id, nome, cidade, capacidade, avaliacao, tiposCozinha,
                faixaPreco, horaAbertura, horaFechamento, dataAbertura, aberto);

    }

    public String formatar() {

        return String.format(Locale.US, "[%d ## %s ## %s ## %d ## %.2f ## [%s] ## %d ## %s-%s ## %s ## %b]",
                id, nome, cidade, capacidade, avaliacao,
                String.join(", ", tiposCozinha),
                faixaPreco,
                horaAbertura.formatar(),
                horaFechamento.formatar(),
                dataAbertura.formatar(),
                aberto);

    }
}

class ColecaoRestaurantes {

    private static final int CAPACIDADE_MAXIMA = 1000;

    private int tamanho;
    private Restaurante[] restaurantes;

    ColecaoRestaurantes() {
        this.tamanho = 0;
        this.restaurantes = new Restaurante[CAPACIDADE_MAXIMA];
    }

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
            while (dado.hasNextLine()) {

                String leitura = dado.nextLine().trim();
                if (leitura.isEmpty()) {
                    continue;
                }

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

        colecao.lerCSV("/tmp/restaurantes.csv");

        return colecao;
    }

}
