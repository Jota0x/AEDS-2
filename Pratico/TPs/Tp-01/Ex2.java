import java.util.Random;
import java.util.Scanner;

public class Ex2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random gerador = new Random();
        gerador.setSeed(4); // Semente fixa

        String linha = scanner.nextLine();

        while (!ehFim(linha)) {

            char c1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
            char c2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));

            String resultado = alterarAleatorio(linha, c1, c2);
            System.out.println(resultado);

            linha = scanner.nextLine();
        }

        scanner.close();
    }

    // Faz a alteracao
    public static String alterarAleatorio(String s, char c1, char c2) {
        int n = s.length();
        String resultado = "";

        for (int i = 0; i < n; i++) {
            char atual = s.charAt(i);
            if (atual == c1) {
                resultado += c2;
            } else {
                resultado += atual;
            }
        }

        return resultado;
    }

    // Verifica fim
    public static boolean ehFim(String str) {
        if (str.length() != 3) {
            return false;
        }

        return str.charAt(0) == 'F' &&
                str.charAt(1) == 'I' &&
                str.charAt(2) == 'M';
    }
}