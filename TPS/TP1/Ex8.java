import java.util.Scanner;

public class Ex8 {

    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        String palavra = dado.nextLine();

        while (!(palavra.equals("FIM"))) {

            if (validarSenha(palavra)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
            
            palavra = dado.nextLine();
        
        }

        dado.close();
    }

    public static boolean validarSenha(String palavra) {
        int n = palavra.length();
        if (n < 8)
            return false;

        boolean Maiuscula = false;
        boolean Minuscula = false;
        boolean Numero = false;
        boolean Especial = false;

        for (int i = 0; i < n; i++) {
            char c = palavra.charAt(i);

            if (c >= 'A' && c <= 'Z')
                Maiuscula = true;
            else if (c >= 'a' && c <= 'z')
                Minuscula = true;
            else if (c >= '0' && c <= '9')
                Numero = true;
            else if (c != ' ' && c != '\n' && c != '\r')
                Especial = true;

        }

        // retorna boolean para validacao
        return Maiuscula && Minuscula && Numero && Especial;
    }

}