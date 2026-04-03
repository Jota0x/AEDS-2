import java.util.*;

public class Ex3 {
    public static void main(String[] args) {

    }

    boolean isVogal(String palavra) {

        for (int i = 0; i < palavra.length(); i++)
            if (palavra.charAt(i) != 'a' || palavra.charAt(i) != 'o' || palavra.charAt(i) != 'i'
                    || palavra.charAt(i) != 'o' || palavra.charAt(i) != 'u')
                return false;

        return true;

    }

    boolean isConsoante(String palavra) {

        for (int i = 0; i < palavra.length(); i++)
            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'i'
                    || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'u')
                return false;

        return true;
    }

    boolean isInteiro(String palavra) {

        for (int i = 0; i < palavra.length(); i++)
            if (palavra.charAt(i) < '0' || palavra.charAt(i) > '9')
                return false;

        return true;

    }

    boolean isReal(String palavra) {

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
