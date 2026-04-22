import java.io.*;
import java.util.*;

public class ColecaoRestaurantes {

    private int tamanho;
    private Restaurante[] restaurantes;  
    
    //Construtores
    ColecaoRestaurantes() {}
    ColecaoRestaurantes(int tamanho, Restaurante restaurantes) {

        this.tamanho = tamanho;
        this.restaurantes = new Restaurante[tamanho];

    }

    //setters
    public void setTamanho(int tamanho) {this.tamanho = tamanho;}
    public void setRestaurantes(Restaurante[] restaurantes) {this.restaurantes = restaurantes;}

    //getters
    public int getTamanho() {return this.tamanho;}
    public Restaurante[] getRestaurante() {return this.restaurantes;} 

    public void lerCSV(String path) {

        try{

        File arquivo = new File(path);
        Scanner dado = new Scanner(arquivo);

        //pula primeira linha 
        if(dado.hasNextLine())
        {
            dado.nextLine();
        }

        //Loop principal para leitura 
        while(dado.hasNext() && tamanho < restaurantes.length) {
            
            //le linha
            String leitura = dado.nextLine();

            //Transforma linha em Objeto 
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

        colecao.lerCSV("/temp/RESTAURANTES.CSV");

        return colecao;
    }




}
