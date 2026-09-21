public class Verde {






}

//Modelagem de Data
class Data {

    int dia;
    int mes;
    int ano;

    public Data(int dia, int mes, int ano){
    
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;

    }

    //Transforma String em Objeto Data
    public Data parseData(String s) {
        
        String partes[] = s.split("-"); 
        return new Data(Integer.parseInt(partes[0]), Integer.parseInt(partes[1]), Integer.parseInt(partes[2]));
    }
    
    //Retorna data no formato DD/MM/YYYY
    public String format() {

        String data = String.format("%d/%d/%d", dia, mes, ano, 10);
        return data;
    }

}

//Modelagem de Veiculo
class Veiculo {

    private int id;
    private String marca;
    private String modelo;
    private int ano;
    private String categoria;
    private String combustivel;
    private int cilindros;
    private float cilindrada;
    private String transmissao;
    private String tracao;
    private float consumo_cidade;
    private float consumo_estrada;
    private float co2;
    private boolean turbo;
    private Data data_registro;

    public Veiculo(int id, String marca, String modelo, int ano, String categoria, String combustivel, int cilindros, float cilindrada,
        String transmissao, String tracao, float consumo_cidade, float consumo_estrada, float co2, boolean turbo, Data data_registro) {

            this.id = id;
            this.marca = marca;
            this.modelo = modelo;
            this.ano = ano;
            this.categoria = categoria;
            this.combustivel = combustivel;
            this.cilindros = cilindros;
            this.cilindrada = cilindrada;
            this.transmissao = transmissao;
            this.tracao = tracao;
            this.consumo_cidade = consumo_cidade;
            this.consumo_estrada = consumo_estrada;
            this.co2 = co2;
            this.turbo = turbo;
            this.data_registro = data_registro;
    }

    //metodos get
    public int getId() {return id;}
    public String getMarca() {return marca;}
    public String getModelo() {return modelo;}
    public int getAno() {return ano;}
    public String getCateroria() {return categoria;}
    public String getCombustivel() {return combustivel;}
    public int getCilindros() {return cilindros;}
    public float getCilindrada() {return cilindrada;}
    public String getTransmissao() {return transmissao;}
    public String getTracao() {return tracao;}
    public float getConsumoCidade() {return consumo_cidade;}
    public float getConsumoEstrada() {return consumo_estrada;}
    public float getCo2() {return co2;}
    public boolean getTurbo() {return turbo;}
    public Data getData() {return data_registro;}

    //Metodos de Veiculo
    public Veiculo parseVeiculo(String s) {}
    public String  format() {
        
        String formatacao = String.format("[%d ## %s ## %s ## %d ## %s ## [%s] ## %s ## %f ## %s ## %s ## %f ## %f ## %f ## %b ## %s]"
        , id, marca, modelo, ano, categoria, combustivel, cilindros, cilindrada, transmissao, tracao, consumo_cidade, consumo_estrada, co2, turbo, data_registro);

        return formatacao;
    }

}

