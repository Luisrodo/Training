import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;

public class Main {
    public static int solution(ArrayList<Integer> A){
        ArrayList<Integer> B = new ArrayList<>(A);

        Collections.sort(B);
        HashMap<Integer,Integer> par = new HashMap<>();

        int count = 0;
        Integer value = B.getFirst();

        for(Integer i: B){
            if( i == value ){
                count++;
            } else {
                par.put(value, count);
                value = i;
                count = 1;
            }
        }
        par.put(value, count);
        par.put(value, count -1);

        for(int i = 0; i < par.size(); i++)
            System.out.println(par.keySet().toArray()[i]);

        int min = (int)par.keySet().toArray()[0];
        int contmin = 1;
        int max = (int)par.keySet().toArray()[par.size()-1];
        int contmax = par.size()-2;
        int aux;
        int pasos = 0;

        while( min != max ){
            if(par.get(min) > par.get(max)){
                aux = (max - (int)par.keySet().toArray()[contmax]);
                pasos += par.get(max) * aux;
                par.replace((Integer)par.keySet().toArray()[contmax], par.get(max) + par.get((Integer)par.keySet().toArray()[contmax]));
                max = (Integer)par.keySet().toArray()[contmax];
                contmax--;
            } else {
                aux = ((int)par.keySet().toArray()[contmin] - min);
                pasos += par.get(min) * aux;
                par.replace((Integer)par.keySet().toArray()[contmin], par.get(min) + par.get((Integer)par.keySet().toArray()[contmin]));
                min = (Integer)par.keySet().toArray()[contmin];
                contmin++;
            }
        }
        return pasos;
    }
    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        System.out.println("Hello and welcome!");
        boolean a = "fútbol" == "fútbol";
        if (a)
            System.out.println("Hola");

        ArrayList<Integer> A = new ArrayList<>();
        A.add(1);
        A.add(2);
        A.add(2);
        A.add(3);
        A.add(3);
        A.add(4);
        A.add(5);
        A.add(1);
        A.add(3);
        A.add(3);

        for(int i = 0; i <4; i++){
            System.out.println(i);
        }
        System.out.println(i);
        int sol = solution(A);

        System.out.println(sol);



    }
}