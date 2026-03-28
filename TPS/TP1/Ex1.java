import java.util.*;

public class Ex1 {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        String palavra = dado.nextLine();

        while (!palavra.equals("FIM")) {

            ciframento(palavra);

            palavra = dado.nextLine();

        }

    }

    // Ciframento
    public static void ciframento(String palavra) {

        // cria array para guardas as letras cifradas
        char[] letra = new char[palavra.length()];

        // loop principal
        for (int i = 0; i < palavra.length(); i++) {

            char newLetra = (char) (palavra.charAt(i) + 3);

            letra[i] = newLetra;

        }

        // cria String com array com as novas letras
        String newPalavra = new String(letra);

        System.out.println(newPalavra);

    }

}