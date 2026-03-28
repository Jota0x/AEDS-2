import java.util.*;

public class Ex11 {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        String palavra = dado.nextLine();

        while (!palavra.equals("FIM")) {

            int tam = palavra.length() - 1;

            inverte(palavra, tam);
            System.out.print("\n");

            palavra = dado.nextLine();
        }

    }

    public static void inverte(String palavra, int tam) {

        if (tam < 0)
            return;

        System.out.print(palavra.charAt(tam));

        inverte(palavra, tam - 1);

    }

}