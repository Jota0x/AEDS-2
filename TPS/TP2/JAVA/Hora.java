import java.util.*;

public class Hora {

    private int hora;
    private int minuto;

    //Construtores
    public Hora() {}
    public Hora(int hora, int minuto) {

        this.hora = hora;
        this.minuto = minuto;

    }

    //Setters
    public void setHora(int hora) {this.hora = hora;}
    public void setMinuto(int minuto) {this.minuto = minuto;}

    //getters
    public int getHora() {return this.hora;}
    public int getMinuto() {return this.minuto;}

    public Hora parseHora(String s) {

        Scanner dado = new Scanner(s);

        dado.useDelimiter(":");

        int hora = dado.nextInt();
        int minuto = dado.nextInt();

        Hora horas = new Hora(hora, minuto);

        return horas;

    }

    public String formatar() {
        return String.format("%02d:%02d", getHora(), getMinuto());
    }

}
