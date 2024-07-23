import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  
        int score = sc.nextInt();
        System.out.print(score == 100 ? "pass" : "failure");
    }
}