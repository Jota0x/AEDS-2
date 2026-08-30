import java.util.Scanner;


public class ex1{
  public static void main(String[] args)
  { 
  Scanner dado = new Scanner(System.in);

  String str = dado.nextLine();
  
  Ciframento(str);

  }

  public static void Ciframento(String str)
  {
    int tamanho = str.length();
    char[] cifra = new char[tamanho];
  
    //loop principal
    //realiza Ciframento
    for(int i = 0; i < tamanho;i++)
    {
      cifra[i] = (char)(str.charAt(i) + 3);
    }
    
    //Cria nova String e imprime
    String nova = new String(cifra);

    System.out.println(nova);
  
  }
}
