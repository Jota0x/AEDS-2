import java.util.*;

public class Data {

    private int dia;
    private int mes;
    private int ano;

    // Construtores
    public Data() {}
    public Data(int dia, int mes, int ano) {

        this.dia = dia;
        this.mes = mes;
        this.ano = ano;

    }

    //setters
    public  void setDia(int dia) {this.dia = dia;}
    public  void setMes(int mes) {this.mes = mes;}
    public  void setAno(int ano) {this.ano = ano;}

    //getter
    public  int getDia() {return this.dia;}
    public int getMes() {return this.mes;}
    public int getAno() {return this.ano;}

    public Data parseData(String s) {

        //Cria objeto do tipo Scanners
        Scanner dado = new Scanner(s);

        //Separa String para criar objeto
        dado.useDelimiter("-");

        int ano = dado.nextInt();
        int mes = dado.nextInt();
        int dia = dado.nextInt();
        
        //cria objeto Data
        Data data = new Data(dia,mes,ano);

        return data;

    }

    public String formatar() {
        return String.format("%02d/%02d/%04d", getDia(), getMes(), getAno());
    }

}