import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        int[] arr = new int[10];
        for(int i = 0; i<10; i++){
            int a = sc.nextInt();
            if(a == 0){
                for(int j = i - 1; j>=0; j--){
                    System.out.print(arr[j] + " ");
                }
                break;
            }
            else{
                arr[i] = a;
            }
        }        
    }
}