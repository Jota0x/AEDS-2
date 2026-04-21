import java.util.*;

public class Aplicaocao {
    public static void main(String[] args) {

        Scanner dado = new Scanner(System.in);

        ColecaoRestaurantes colecao = ColecaoRestaurantes.lerCSV();

        int id = dado.nextInt();

        while (id != -1) {
            
            for (int i = 0; i < colecao.getTamanho(); i++) {

                Restaurante restaurante = colecao.getRestaurante()[i];

                if(restaurante.getId() == id)
                    System.out.println(restaurante.formatar());
            }

            id = dado.nextInt();
        }

        dado.close();

    }

}
