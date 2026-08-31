import java.util.Scanner;

public class ex11 {
    public static void main(String[] args)
    {
        Scanner dado = new Scanner(System.in);

        String palavra = dado.nextLine();

        while (!ehFim(palavra))
        {
            int tam = palavra.length() - 1;

            Inversao(palavra, tam);
            System.out.println();

            palavra = dado.nextLine();
        }

        dado.close();
    }

    // Verifica fim
    public static boolean ehFim(String str)
    {
        if (str.length() != 3)
            return false;

        return str.charAt(0) == 'F' &&
                str.charAt(1) == 'I' &&
                str.charAt(2) == 'M';
    }

    // Imprime string invertida
    public static void Inversao(String str, int tam)
    {
        if(tam < 0)
            return;

        System.out.print(str.charAt(tam));

        Inversao(str, tam - 1);
    }
}