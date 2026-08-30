import java.util.Scanner;

public class ex11 {
    public static void main(String[] args)
    {
        Scanner dado = new Scanner(System.in);
        
        String palavra = dado.nextLine();

        int tam = palavra.length();

        Inversao(palavra, tam);
    }

    //Imprime string invertida
    public static void Inversao(String str, int tam)
    {
        if(tam < 0)
            return;
        
        System.out.println(str.charAt(tam));
    
        Inversao(str, tam--);
        
    }
}