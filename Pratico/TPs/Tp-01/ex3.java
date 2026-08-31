import java.util.Scanner;

public class ex3 {
  public static void main(String[] args) {

    Scanner dado = new Scanner(System.in);
    ex3 obj = new ex3();

    String palavra = dado.nextLine();

    while (!obj.ehFim(palavra)) {

      if (obj.isVogal(palavra))
        System.out.print("SIM ");
      else
        System.out.print("NAO ");

      if (obj.isConsoante(palavra))
        System.out.print("SIM ");
      else
        System.out.print("NAO ");

      if (obj.isInteiro(palavra))
        System.out.print("SIM ");
      else
        System.out.print("NAO ");

      if (obj.isReal(palavra))
        System.out.println("SIM");
      else
        System.out.println("NAO");

      palavra = dado.nextLine();
    }

    dado.close();
  }

  // Verifica fim, sem usar equals/compareTo
  boolean ehFim(String palavra) {
    if (palavra.length() != 3)
      return false;

    return palavra.charAt(0) == 'F' &&
        palavra.charAt(1) == 'I' &&
        palavra.charAt(2) == 'M';
  }

  //Verifica Vogal
  boolean isVogal(String palavra) {
    for (int i = 0; i < palavra.length(); i++)
      if (palavra.charAt(i) != 'a' && palavra.charAt(i) != 'e' && palavra.charAt(i) != 'i'
          && palavra.charAt(i) != 'o' && palavra.charAt(i) != 'u'
          && palavra.charAt(i) != 'A' && palavra.charAt(i) != 'E' && palavra.charAt(i) != 'I'
          && palavra.charAt(i) != 'O' && palavra.charAt(i) != 'U')
        return false;
    return true;
  }

  //Verifica Consoante
  boolean isConsoante(String palavra) {
    for (int i = 0; i < palavra.length(); i++)
      if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'i'
          || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'u'
          || palavra.charAt(i) == 'A' || palavra.charAt(i) == 'E' || palavra.charAt(i) == 'I'
          || palavra.charAt(i) == 'O' || palavra.charAt(i) == 'U')
        return false;
    return true;
  }

  //Verifica Inteiro
  boolean isInteiro(String palavra) {
    for (int i = 0; i < palavra.length(); i++)
      if (palavra.charAt(i) < '0' || palavra.charAt(i) > '9')
        return false;
    return true;
  }

  //Verifica Real
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