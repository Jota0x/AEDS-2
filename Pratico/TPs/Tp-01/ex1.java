import java.util.Scanner;

public class Ex1 {
  public static void main(String[] args) {
    Scanner dado = new Scanner(System.in);

    String str = dado.nextLine();


    while (!ehFim(str)) {

      Ciframento(str);

      str = dado.nextLine();
    }
    dado.close();
  }

  public static void Ciframento(String str) {
    int tamanho = str.length();
    char[] cifra = new char[tamanho];

    // loop principal
    // realiza Ciframento
    for (int i = 0; i < tamanho; i++) {
      cifra[i] = (char) (str.charAt(i) + 3);
    }

    // Cria nova String e imprime
    String nova = new String(cifra);

    System.out.println(nova);

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
