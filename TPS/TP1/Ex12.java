import java.util.*;

public class Ex12 {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        while (dado.hasNext()) {

            int n = dado.nextInt();

            System.out.println(soma(n));
        }
    }

    // Soma de digitos recursivo
    public static int soma(int n) {

        if (n == 0)
            return 0;

        return n % 10 + soma(n / 10);

    }

}
