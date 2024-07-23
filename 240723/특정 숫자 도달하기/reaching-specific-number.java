import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        
        int sum = 0;
        boolean check = false;

        for(int i = 0; i < 10; i++){
            int a = sc.nextInt();
            if(a >= 250){
                System.out.printf("%d %.1f", sum, (double)sum/i);
                check = true;
                break;
            }
            sum += a;
        }
        if(!check){
            System.out.printf("%d %.1f", sum, (double)sum/10);
        }

    }
}