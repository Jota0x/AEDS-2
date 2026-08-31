import java.util.Scanner;

public class ex12 {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        while (dado.hasNextInt()) {
            int num = dado.nextInt();

            System.out.println(SomaDigitos(num));
        }

        dado.close();
    }

    //Soma digitos
    public static int SomaDigitos(int n)
    {
        if (n == 0)
            return 0;

        return n % 10 + SomaDigitos(n / 10);
    }

}