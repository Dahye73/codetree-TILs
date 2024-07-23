import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  

        int[] arr = new int[10];
        int i;

        for(i = 0; i < 10; i++){
            int a = sc.nextInt();
            if(a == 0){
                break;
            }
            arr[i] = a;
        }

        for(int j = i - 1; j >= 0; j--){
            System.out.print(arr[j] + " ");
        }
    }
}