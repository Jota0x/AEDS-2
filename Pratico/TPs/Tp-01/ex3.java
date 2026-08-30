import java.util.Scanner;

public class ex3 {
    public static void main(String[] args) {
  



    }
    
    //Verifica Vogal
    public static boolean isVogal(String str)
    {
      for(int i = 0; i < str.length();i++)
          if(str.charAt(i).toUpperCase != 'A' || str.charAt(i).toUpperCase != 'E' || str.charAt(i).toUpperCase != 'I' || str.charAt(i).toUpperCase != 'O' || str.charAt(i) != 'U')
            return false;

      return true;
    }
    
    //Verifica consoante
    public static boolean isConsoante(String str) {
      if(isVogal())
        return false;
      else
        return true;
    }
    
    //Verifica Inteiro
    public static boolean isInteiro(String str) {
    if(isVolgal() || isConsoante())
      return false;

    for(int i = 0; i < str.length();i++)
      if(str.charAt(i) == "," || str.charAt(i) == ".");
      return false;

    return true;
    }
    
    //Verifica real
    public static boolean isReal(String str) {
    if(isVogal() || isConsoante())
      return false;
    if(isInteiro)
      return true;

    //Auxilar que conta quantidade de pontos na String
    int aux = 0;

  for(int i = 0; i < str.length(); i++)
    if(str.charAt(i) == '.' || str.charAt(i) == ',')
        aux++;
  
  
  if(aux > 1)
    return false;

  return true;
  }
}
