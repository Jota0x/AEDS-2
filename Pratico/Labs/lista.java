import java.util.Scanner;

public class lista{

    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        int n = dado.nextInt();
        int comportado = 0, nComportado = 0;
        String[] nomes = new String[n];

        for(int i = 0; i < n; i++)
        {   
            char letra = dado.next().charAt(0);
            nomes[i] = dado.nextLine(); 
            
            if(letra == '+')
                comportado++;
            else
                nComportado++;
        }

        bubble(nomes);

        for(int i = 0; i < n; i++)
        {
            System.out.println(nomes[i]);
        }

        System.out.println("Se comportaram: " + comportado + " | Nao se comportaram:" + nComportado);
    }

    public static void bubble(String[] nomes)
    {
        int tam = nomes.length;

        for(int i = 0; i < tam;i++)
            for(int j = i + 1; j < tam; j++)
            if(nomes[i].compareTo(nomes[j]) >= 1)
            {
                String aux = nomes[i];
                nomes[i] = nomes[j];
                nomes[j] = aux;
            }
    }

}