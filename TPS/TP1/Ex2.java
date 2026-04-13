import java.util.*;

public class Ex2 {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        // Cria objeto Random para randomizar letras
        Random random = new Random();
        random.setSeed(4);

        String palavra = dado.nextLine();

        while (!palavra.equals("FIM")) {

            // Letras aleatorizadas
            char letra1 = (char) ('a' + (Math.abs(random.nextInt()) % 26));
            char letra2 = (char) ('a' + (Math.abs(random.nextInt()) % 26));;

            // Faz troca
            alteracao(palavra, letra1, letra2);

            palavra = dado.nextLine();

        }

    }

    // Metodo para troca
    public static void alteracao(String palavra, char letra1, char letra2) {

        char[] novaString = new char[palavra.length()];

        for (int i = 0; i < palavra.length(); i++) {

            if (palavra.charAt(i) == letra1)
                novaString[i] = letra2;
            else
                novaString[i] = palavra.charAt(i);

        }

        String newString = new String(novaString);

        System.out.println(newString);

    }

}
