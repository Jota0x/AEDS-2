import java.util.*;

public class Ex3 {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        String palavra = dado.nextLine();

        while (!palavra.equals("FIM")) {


            if (isVogal(palavra)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (isConsoante(palavra)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (isInteiro(palavra)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (isReal(palavra)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }

            palavra = dado.nextLine();

        }

    }

    public static boolean isVogal(String palavra) {

        for (int i = 0; i < palavra.length(); i++)
            if (palavra.charAt(i) != 'a' || palavra.charAt(i) != 'o' || palavra.charAt(i) != 'i'
                    || palavra.charAt(i) != 'o' || palavra.charAt(i) != 'u')
                return false;

        return true;

    }

    public static boolean isConsoante(String palavra) {

        for (int i = 0; i < palavra.length(); i++) {

            if (palavra.charAt(i) < 'a' || palavra.charAt(i) > 'z')
                return false;

            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'i'
                    || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'u')
                return false;

        }
        return true;
    }

    public static boolean isInteiro(String palavra) {

        for (int i = 0; i < palavra.length(); i++)
            if (palavra.charAt(i) < '0' || palavra.charAt(i) > '9')
                return false;

        return true;

    }

    public static boolean isReal(String palavra) {

        int ponto = 0;

        for (int i = 0; i < palavra.length(); i++) {

            if (palavra.charAt(i) == '.')
                ponto++;
            else if (palavra.charAt(i) < '0' || palavra.charAt(i) > '9')
                return false;

        }

        if (ponto > 1)
            return false;

        return true;

    }

}
