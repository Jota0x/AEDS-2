import java.util.*;

class Pilha{

    private int topo;
    private int[] dados;

    public Pilha(){

        this.topo = -1;
        this.dados = new int[10];

    }


    //Verifica se pilha esta cheia 
    public boolean isFull(){

        if(topo == 10 - 1)
            return true;
        else
            return false;
    }

    //Verifica se pilha esta vazia
    public boolean isEmpty(){

        if(topo == -1)
            return true;
        else
            return false;
    }

    //Empilha 
    public void push(int valor){

        if(!isFull()){

            topo++;
            dados[topo] = valor;

        }
        else
            System.out.println("Pilha cheia\n");
    }

    public void pop(){

        if(!isEmpty()){

            System.out.println(dados[topo]);    //imprime valor q saiu da pilha 
            topo--;
        }
        else
            System.out.println("Pilha vazia\n");
    }





}